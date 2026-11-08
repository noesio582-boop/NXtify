param(
    [int]$Jobs = 4,
    [string]$DevkitPro = ""
)

$ErrorActionPreference = "Stop"

# --- Resolve the devkitPro root (Windows path). The installer sets DEVKITPRO
# to the MSYS2-style /opt/devkitpro, which maps to C:\devkitPro on disk.
$candidates = @()
if (-not [string]::IsNullOrWhiteSpace($DevkitPro)) { $candidates += $DevkitPro }
if (-not [string]::IsNullOrWhiteSpace($env:DEVKITPRO)) {
    if ($env:DEVKITPRO -match '^/opt/devkitpro/?$') {
        $candidates += "C:\devkitPro"
    } else {
        $candidates += $env:DEVKITPRO
    }
}
$candidates += "C:\devkitPro"

$root = $null
foreach ($c in $candidates) {
    if (Test-Path -LiteralPath (Join-Path $c "cmake\Switch.cmake")) {
        $root = $c
        break
    }
}
if ($null -eq $root) {
    throw "Could not find cmake\Switch.cmake under any of: $($candidates -join ', '). Install it in the devkitPro MSYS2 shell: pacman -S switch-cmake"
}
Write-Host "devkitPro root: $root"

# --- Prefer devkitPro's own MSYS2 cmake/ninja/cygpath. The cmake found on a
# normal Windows PATH here is MSYS-flavored and mistreats absolute Windows
# paths (C:\... becomes a relative path), so all paths handed to it must be
# converted with cygpath — same approach as twiNX's build script.
$msysBin = Join-Path $root "msys2\usr\bin"
$cygpath = Join-Path $msysBin "cygpath.exe"
$useMsys = Test-Path -LiteralPath $cygpath

function Convert-BuildPath {
    param([Parameter(Mandatory = $true)][string]$Path)
    if ($useMsys) {
        $converted = & $cygpath -u $Path
        if ($LASTEXITCODE -eq 0 -and -not [string]::IsNullOrWhiteSpace($converted)) {
            return $converted.Trim()
        }
    }
    return ($Path -replace '\\', '/')
}

$cmakeExe = "cmake"
$ninjaExe = "ninja"
if ($useMsys) {
    if (Test-Path -LiteralPath (Join-Path $msysBin "cmake.exe")) { $cmakeExe = Join-Path $msysBin "cmake.exe" }
    if (Test-Path -LiteralPath (Join-Path $msysBin "ninja.exe")) { $ninjaExe = Join-Path $msysBin "ninja.exe" }
}

$env:Path = "$root\devkitA64\bin;$root\tools\bin;$msysBin;$env:Path"

# Under MSYS2 tools, devkitPro lives at its canonical mount /opt/devkitpro
if ($useMsys) {
    $env:DEVKITPRO = "/opt/devkitpro"
    $env:DEVKITA64 = "/opt/devkitpro/devkitA64"
    $toolchain = "/opt/devkitpro/cmake/Switch.cmake"
} else {
    $env:DEVKITPRO = ($root -replace '\\', '/')
    $env:DEVKITA64 = "$env:DEVKITPRO/devkitA64"
    $toolchain = (Join-Path $root "cmake\Switch.cmake") -replace '\\', '/'
}

# Files delivered from the cloud session can carry timestamps a few hours in
# the future (UTC container vs local clock); ninja then loops with "manifest
# still dirty". Clamp any future mtime to now before building.
$now = Get-Date
Get-ChildItem -Path $PSScriptRoot -Recurse -File | Where-Object { $_.LastWriteTime -gt $now } | ForEach-Object { $_.LastWriteTime = $now }

$makeExe = Join-Path $msysBin "make.exe"
$appDir = Join-Path $PSScriptRoot "app"
$buildAppDir = Join-Path $PSScriptRoot "build_app"
New-Item -ItemType Directory -Force -Path $buildAppDir | Out-Null

Write-Host "Building Spotify application with devkitPro make..."
& $makeExe -C $appDir "-j$Jobs"
if ($LASTEXITCODE -ne 0) { throw "Nintendo Switch build failed with exit code $LASTEXITCODE." }

Copy-Item (Join-Path $appDir "Spotify.nro") (Join-Path $buildAppDir "Spotify.nro") -Force
Write-Host ""
Write-Host "Output: $(Join-Path $buildAppDir 'Spotify.nro')"
