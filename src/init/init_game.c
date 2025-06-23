
#include "cube3d.h"


int init_game(t_game *game, int save_opt)
{
	//zero out the game struct to avoid garbage values
	ft_bzero(game, sizeof(t_game));

	//initialize MLX context
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);

        //Set save flag
	if(save_opt)
		game->options |= FLAG_SAVE;

	//If not in screenshot-only mode, create window
	if (!(game->options & FLAG_SAVE))
	{
		game->win = mlx_new_window(game->mlx, HEIGHT, "cub3D");
		if (!game->win)
			return (0);
	}

	//initialize floor/ceiling colors to invalid (-1)
	game->floor_color = -1;
	game->ceiling_color = -1;

	//Nullif map and screen image data initially
	game->map = NULL;
	game->screen.img_ptr = NULL;
	
	//Nullify texture images
	game->textures.north.img_ptr = NULL;
	game->textures.south.img_ptr = NULL;
	game->textures.east.img_ptr = NULL;
	game->textures.west.img_ptr = NULL;

	//Initialize player position to -1 (indicating not set)
	game->player.x = -1;
	game->player.y = -1;
	game->player.dir = 0;

	return (1);
}
