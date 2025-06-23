#include "cub3d.h"

int handle_input(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game);
    else if (keycode == KEY_W)
    {
        game->player.x += cos(game->player.dir) * MOVE_SPEED;
        game->player.y += sin(game->player.dir) * MOVE_SPEED;
    }
    else if (keycode == KEY_S)
    {
        game->player.x -= cos(game->player.dir) * MOVE_SPEED;
        game->player.y -= sin(game->player.dir) * MOVE_SPEED;
    }
    else if (keycode == KEY_A)
    {
        game->player.x += cos(game->player.dir - PI / 2) * MOVE_SPEED;
        game->player.y += sin(game->player.dir - PI / 2) * MOVE_SPEED;
    }
    else if (keycode == KEY_D)
    {
        game->player.x += cos(game->player.dir + PI / 2) * MOVE_SPEED;
        game->player.y += sin(game->player.dir + PI / 2) * MOVE_SPEED;
    }
    else if (keycode == KEY_LEFT)
        game->player.dir -= ROT_SPEED;
    else if (keycode == KEY_RIGHT)
        game->player.dir += ROT_SPEED;

    render_frame(game);
    return 0;
}
