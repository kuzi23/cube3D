
#include "cube3d.h"

void ft_bzero(void *s, size_t n)
{
	unsigned char *p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

void exit_error(const char *message, t_game *game)
{
	if (message)
		fprintf(stderr, "Error: %s\n", message);
	exit_game(game);
}

void exit_game(t_game *game)
{
	if (!game)
		exit(EXIT_FAILURE);

	if (game->screen.img_ptr)
		mlx_destroy_image(game->mlx, game->screen.img_ptr);

	mlx_destroy_window(game->mlx, game->win);

	// Destroy texture images if they exist
	if (game->textures.north.img_ptr)
		mlx_destroy_image(game->mlx, game->textures.north.img_ptr);
	if (game->textures.south.img_ptr)
		mlx_destroy_image(game->mlx, game->textures.south.img_ptr);
	if (game->textures.east.img_ptr)
		mlx_destroy_image(game->mlx, game->textures.east.img_ptr);
	if (game->textures.west.img_ptr)
		mlx_destroy_image(game->mlx, game->textures.west.img_ptr);

	// Free map
	if (game->map)
	{
		for (int i = 0; game->map[i]; i++)
			free(game->map[i]);
		free(game->map);
	}

	free(game->mlx);
	exit(EXIT_SUCCESS);
}


