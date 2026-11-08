# NXtify 0.9.5 / Overlay 0.5.0

## Novedades en NXtify 0.9.5

- **Sistema de Actualizaciones OTA (Over-The-Air)**:
  - Busqueda automatica de actualizaciones activada por defecto al iniciar la aplicacion.
  - Al detectar una nueva version, muestra un anuncio en pantalla con las novedades y opcion de actualizar inmediatamente.
  - Al completar la descarga y aplicacion de la actualizacion, solicita reiniciar la aplicacion para aplicar los cambios de inmediato.
  - Nuevo apartado en **Configuracion > Actualizaciones** con estado de actualizaciones, comprobacion manual, selector de versiones beta y lista de versiones disponibles.
- **Control de puntero por movimiento con Joy-Con desacoplado**:
  - Control de cursor mediante giroscopio del Joy-Con derecho al desacoplar los mandos.
  - Recentrado de puntero rapido presionando R3 (stick derecho).
  - Sensibilidad y aceleracion calibradas para maxima precision y comodidad.
- **Traducciones completas al español** en todas las secciones nuevas y ajustes del sistema.

## Opciones de descarga

- `NXtify-v0.9.5-SD-Package.zip` — Paquete completo Todo en Uno (NRO, Overlay y Sysmodule).
- `NXtify-0.9.5.zip` — Aplicacion NRO independiente.
- `NXtify.nro` — Binario ejecutable individual.
- `NXtify.ovl` — Overlay Tesla individual.
- `NXtify-Overlay-0.5.0.zip` — Overlay y reproductor en segundo plano.
- `NXtify-source-0.9.5.zip` — Codigo fuente completo.
- `SHA256SUMS.txt` — Sumas de verificacion SHA-256.
- Complete multi-thousand-track Liked Songs and playlist sessions with Play
  All, session caching, and only 100 interface rows materialized at once.
- Large player, podcast, and collection artwork now uses Spotify's largest
  supplied image instead of the 300-pixel card endpoint.
- Session lyrics caching avoids repeat network requests for the same track.
- Removed unused AAC, MP3, ALAC, and Opus decoder paths; Spotify playback
  continues to use selectable 160 or 320 kbps OGG Vorbis streams.
- Preserved loaded dashboards, libraries, collections, and artwork across tab
  changes.
- Hardened playback-state publication and Shuffle/Repeat queue updates.

## Overlay and background service 0.5.0 highlights

- Restored Nintendo 64 Nintendo Switch Online compatibility in hardware
  testing by reducing persistent decoder, socket, queue, cache, and artwork
  pressure.
- Remote 50-track collection fetches, 25-item overlay pages, and a bounded
  100-track playback window replace thousand-track up-front loading.
- Followed podcasts are available under Your Library with playable episodes.
- Automatic service startup retries with bounded backoff, supervises Dormant
  transitions, and recovers without requiring the manual retry path during a
  normal launch.
- Loading screens retain a local B-button escape and catalog work stays away
  from Ultrahand's render thread.
- Search and browser input is claimed by the overlay instead of being repeated
  into the foreground game or application.
- Play/Pause uses an explicit requested state. Pending playback-state, seek,
  volume, Shuffle, Repeat, and quality requests coalesce so stale actions are
  not replayed later.
- Closing Ultrahand releases overlay-owned artwork, network, and IPC resources;
  reopening reconnects cleanly while the independent service keeps playing.
- Artwork networking is just-in-time: cache hits claim no BSD session and a
  cache miss releases its session immediately after the transfer.
- Centered artwork and a clearer volume layout keep the percentage readable
  while aligning the Volume label with its slider.
- The service remains dormant at console boot and opens audout only when audio
  playback actually begins.

## Notes

NXtify is unofficial, requires Spotify Premium for native playback, and uses
undocumented Spotify protocols that Spotify may change. Lyrics availability
and line synchronization depend on Spotify's response for the track, account,
and region.

NXtify is not affiliated with Spotify or Nintendo.
