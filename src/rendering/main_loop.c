#include "cube3d.h"

void	update_player(t_game *game)
{
	t_player *p = &game->player;

	// Update direction (rotation)
	p->dir += p->turn_dir * p->rot_speed;
	if (p->dir < 0)
		p->dir += 2 * PI;
	if (p->dir >= 2 * PI)
		p->dir -= 2 * PI;

	// Movement vector
	double move_step = p->walk_dir * p->move_speed;
	double strafe_step = p->strafe_dir * p->move_speed;

	double new_x = p->x + cos(p->dir) * move_step;
	double new_y = p->y + sin(p->dir) * move_step;

	new_x += cos(p->dir + PI / 2) * strafe_step;
	new_y += sin(p->dir + PI / 2) * strafe_step;

	// Optional: collision check here

	p->x = new_x;
	p->y = new_y;
}

// Stub for render (you can call raycaster & draw functions from here)
void	render(t_game *game)
{
	// Clear the previous frame (optional, depending on how mlx is used)
	// Cast rays
	// Draw walls
	// Draw minimap
	// Draw buffer to window
	mlx_put_image_to_window(game->mlx, game->window.win, game->screen.img_ptr, 0, 0);
}

int	main_loop(t_game *game)
{
	update_player(game);
	render(game);
	return (0);
}