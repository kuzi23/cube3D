#include "cube3d.h"

void draw_textured_line(t_game *game, int x, int wall_height, t_ray ray)
{
    int y_start = (HEIGHT - wall_height) / 2;
    int y_end = y_start + wall_height;
    int y;

    if (y_start < 0) y_start = 0;
    if (y_end > HEIGHT) y_end = HEIGHT;

    for (y = y_start; y < y_end; y++)
    {
        put_pixel(&game->screen, x, y, 0xFFFFFF); // Placeholder: replace with texture sampling
    }
}

void draw_walls(t_game *game)
{
    int i;
    double dist;
    int wall_height;

    for (i = 0; i < WIDTH; i++)
    {
        dist = game->rays[i].distance * cos(game->rays[i].angle - game->player.dir); // Fix fish-eye
        wall_height = (int)((TEX_HEIGHT / dist) * (WIDTH / (2.0 * tan(FOV * PI / 360.0))));
        draw_textured_line(game, i, wall_height, game->rays[i]);
    }
}