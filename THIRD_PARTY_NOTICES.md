# Third-Party Notices and Licenses

**NXtify** is maintained and developed by **noesio582-boop** ([@noesio582-boop](https://github.com/noesio582-boop)).
It is an independent, unofficial homebrew application for Nintendo Switch and is not affiliated with or endorsed by Spotify AB or Nintendo Co., Ltd.

## Upstream Projects and Authors

- **noesio582-boop** ([@noesio582-boop](https://github.com/noesio582-boop)) — Lead developer of NXtify, modern Switch port, background service integration, Zeroconf pairing, Pathfinder library sync, bilingual UI, and Songate / Gatefold interface adaptation.
- **HiroshiYamauchi** — Original creator of the Switch streaming client and Phase 2 sysmodule/IPC architecture (`GPL-3.0-or-later`).
- **AndryTheBeast** — Creator of **Songate** for Nintendo Switch, whose hardware-accelerated SDL2 homebrew UI framework, touch/gamepad navigation subsystem, and view architecture power the NXtify interface (`GPL-3.0`). Upstream: <https://github.com/AndryTheBeast/Songate>
- **DEVIROYrus** — Creator of **Gatefold** for foobar2000, whose original design, typography, icons, CSS layouts, and dynamic OKLab cover palette extraction algorithm provide the visual identity (`MIT License`). Upstream: <https://github.com/DEVIROYrus/Gatefold>
- **feelfreelinux & contributors** — Creators of **cspot**, providing the native C++ streaming and authentication stack (`GPL-3.0-or-later`). Upstream: <https://github.com/feelfreelinux/cspot>
- **ppkantorski** — Creator of **libultrahand** (`GPL-2.0-only`) and **sys-tune**, used by the Ultrahand overlay and IPC server. Upstream: <https://github.com/ppkantorski/libultrahand>
- **dammitjeff** — Creator of **Streamfin Switch**, referenced for the overlay layout. Upstream: <https://github.com/dammitjeff/streamfin-switch>
- **natinusala** — Creator of **Borealis** (`Apache-2.0`). Upstream: <https://github.com/natinusala/borealis>

## Libraries Included in Builds

- **SDL2, SDL2_ttf, SDL2_image** — zlib license.
- **Inter typeface** — SIL Open Font License 1.1 (Rasmus Andersson).
- **libnx and devkitPro portlibs** — ISC, BSD, MIT, and LGPL/GPL licenses.
- **nlohmann/json, fmt, nanopb, Tremor, cJSON, mdnssvc** — Bundled through `vendor/cspot` under their respective open-source licenses.
- **libcurl and zlib** — MIT/curl and zlib licenses.
