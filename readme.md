cub3D/
├── Makefile
├── cub3d.c                → Main entry point
├── includes/
│   └── cub3d.h            → Central header for all prototypes, macros, structs
├── src/
│   ├── init/
│   │   ├── init_game.c     → Initialize game structures and map
│   │   └── init_textures.c → Load textures, floor/ceiling colors
│   ├── parsing/
│   │   ├── parser.c        → Parse the .cub file
│   │   ├── map_check.c     → Validate map (closed walls, characters, format)
│   │   └── utils_parser.c  → Helper functions for parsing
│   ├── rendering/
│   │   ├── raycaster.c     → Main raycasting logic
│   │   ├── draw_walls.c    → Render vertical wall slices with textures
│   │   └── draw_minimap.c  → (Optional) Mini-map rendering
│   ├── events/
│   │   ├── controls.c      → Handle keyboard inputs (WASD, arrows, ESC)
│   │   └── exit.c          → Clean exit when pressing ESC or window close
│   ├── mlx/
│   │   └── mlx_utils.c     → Wrapper functions for MLX image manipulation
│   └── utils/
│       ├── math_utils.c    → Normalize angles, distance calc, etc.
│       └── error.c         → Handle and display errors
├── assets/
│   └── textures/           → Wall textures (north.xpm, south.xpm, etc.)
└── maps/
    └── sample.cub         → Example map file
