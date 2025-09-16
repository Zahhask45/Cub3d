# Cub3d (Raycaster) – CUBORMINI

A 42-school style raycasting engine inspired by Wolfenstein 3D. This repository contains a complete MiniLibX-based 3D renderer with textured walls, a dynamic minimap, mouse and keyboard controls, and a robust `.cub` map parser with extensive validation.

---

## Features

- Textured raycasting renderer (N/E/S/W wall textures)
- Smooth movement and rotation (keyboard + mouse)
- Minimap rendering with view window
- Configurable window size: `WIDTH = 1920`, `HEIGHT = 1000`
- Robust map parser with validation and clear error messaging
- Floor/Ceiling color parsing (RGB), converted to hex fill
- XPM texture loading (via MiniLibX)
- Example maps: `maps/valid/` and negative testcases in `maps/invalid/`

---

## Project Layout

- `Cub3D/`
  - `inc/` – public headers (see `cub.h` for types and constants)
  - `src/` – source code grouped by domain
    - `init/` – initialization of map, textures, rays, and player
    - `map_valid/` – map parsing, size detection, and validation
    - `window/` – core raycasting, frame, and window loop
    - `render/` – per-frame render, texture selection and mapping
    - `input/` – keyboard/mouse hooks and handling
    - `utils/` – helpers, memory, cleanup, minimap utilities
    - `textures/` – texture helpers
  - `mlx/minilibx-linux/` – MiniLibX (Linux flavor)
  - `libft/` – custom C utility library (with GNL bonus)
  - `maps/` – sample `.cub` maps (valid and invalid)
  - `Textures/` – example texture assets (XPM/PNG)

---

## Build

Requirements (Linux/WSL recommended):
- `cc`/`gcc`, `make`
- X11 development libraries: `libx11-dev`, `libxext-dev`

Install deps on Debian/Ubuntu:
```bash
sudo apt update && sudo apt install -y build-essential libx11-dev libxext-dev
```

Build the project:
```bash
cd Cub3D
make
```

This compiles `libft` and `MiniLibX`, then produces the executable:
- Binary: `cub3D`

Clean targets:
```bash
make clean   # remove objects
make fclean  # remove objects + binary
make re      # full rebuild
```

---

## Run

Use any `.cub` file from `Cub3D/maps/valid/` as an example:
```bash
./cub3D maps/valid/subject_map.cub
```
If no argument or a wrong number of arguments is provided, the program exits with failure. The window title is set to `BANANA` by default.

---

## Controls

- Move: `W` (forward), `S` (backward), `A` (strafe left), `D` (strafe right)
- Rotate: Left/Right Arrow keys
- Mouse: horizontal movement rotates the camera; cursor wraps at screen edges
- Exit: `ESC`

Movement is clipped using collision checks against the map grid.

---

## The .cub Map Format

A `.cub` file is a text configuration that defines:
1) Texture paths for each cardinal wall
2) Floor and ceiling colors (RGB)
3) A 2D map grid with walls, spaces, and a single player start

General order (whitespace tolerated):
```
NO path/to/north_texture.xpm
SO path/to/south_texture.xpm
EA path/to/east_texture.xpm
WE path/to/west_texture.xpm
F  r,g,b
C  r,g,b

111111
1N0011
100011
111111
```

- Textures: `NO`, `SO`, `EA`, `WE` must point to valid `.xpm` files. Other formats are rejected.
- Colors: `F` (floor) and `C` (ceiling) take RGB triplets (0–255). They are converted to hex for rendering.
- Map grid: composed of characters like `1` (wall), `0` (empty/walkable), and one player start: `N`, `S`, `E`, or `W`.
- Map must be closed (no holes on edges or around empty tiles). Only one player is allowed, and it cannot be on the edge.

See negative examples under `maps/invalid/` for all the validations enforced:
- Missing/duplicate/forbidden texture lines
- Non-XPM texture files
- Missing/invalid/malformed RGB
- Map too small, not closed, holes in each direction
- Player missing/multiple/on edge
- File extension issues

---

## Rendering Pipeline (High-level)

- Initialization (`init_all`, `start_text`, `init_textures`, `init_minimap`)
- Per-frame loop (`mlx_loop_hook` → `render`):
  - Gather input and update player state
  - Ray setup per screen column, DDA to find wall hit
  - Compute wall distances and draw spans
  - Sample correct wall texture (N/E/S/W) and blit to frame
  - Compose minimap and present the frame

Performance-critical portions: DDA stepping, texture coordinate calculation, and frame blitting. Constants like `MOVESPEED`, `ROTATION_SPEED`, and mouse sensitivity (`ROTATION_MOUSE`) live in `inc/cub.h`.

---

## Assets

- `Cub3D/Textures/` includes sample PNG and XPM files. The runtime requires `.xpm` for walls.
- Additional packs under `PixelTexturePack/Textures/` can be used to craft your own `.cub` maps (convert to XPM as needed).

---

## Troubleshooting

- Missing X11 libraries: install `libx11-dev` and `libxext-dev`.
- On native Windows, use WSL with an X server (e.g., VcXsrv) or build/run on Linux.
- If textures fail to load, verify the paths in your `.cub` and ensure files are `.xpm`.
- If the window opens but nothing renders, check your map closure (walls) and that there is exactly one player start.

---

## License and Credits

- MiniLibX (42) is included under its own terms.
- `libft/` contains common C utilities and a GNL bonus implementation used here.
- Example textures in `PixelTexturePack/Textures/` come with their own licenses; see `PixelTexturePack/Textures/License.txt`.

---

## Author

- João (jodos-sa) and Bruno (brumarti)
