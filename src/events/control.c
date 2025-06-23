#include "cube3d.h"

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

int key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.walk_dir = +1;
	else if (keycode == KEY_S)
		game->player.walk_dir = -1;
	else if (keycode == KEY_A)
		game->player.strafe_dir = -1;
	else if (keycode == KEY_D)
		game->player.strafe_dir = +1;
	else if (keycode == KEY_LEFT)
		game->player.turn_dir = -1;
	else if (keycode == KEY_RIGHT)
		game->player.turn_dir = +1;
	else if (keycode == KEY_ESC)
		exit_hook(game);
	return (0);
}

int key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_S)
		game->player.walk_dir = 0;
	else if (keycode == KEY_A || keycode == KEY_D)
		game->player.strafe_dir = 0;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		game->player.turn_dir = 0;
	return (0);
}