#include "cube3d.h"

t_ray cast_single_ray(t_game *game, double ray_angle)
{
    t_ray ray;

    ray.angle = normalize_angle(ray_angle);
    ray.distance = 0; // You will implement real intersection later
    ray.hit_vert = 0;
    ray.hit_horiz = 0;
    ray.wall_type = 0;

    // TODO: implement horizontal and vertical intersection logic
    // and set ray.distance, ray.wall_type, etc.

    return ray;
}

void cast_rays(t_game *game)
{
    double angle;
    int i;

    if (!game->rays)
        game->rays = malloc(sizeof(t_ray) * WIDTH);

    angle = game->player.dir - (FOV * PI / 180.0) / 2;
    for (i = 0; i < WIDTH; i++)
    {
        game->rays[i] = cast_single_ray(game, angle);
        angle += (FOV * PI / 180.0) / WIDTH;
    }
}
