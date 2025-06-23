#include "cube3d.h"

void free_map(char **map)
{
    int i = 0;

    if (!map)
        return;
    while (map[i])
        free(map[i++]);
    free(map);
}

void destroy_texture(t_img *img, void *mlx)
{
    if (img && img->img_ptr)
        mlx_destroy_image(mlx, img->img_ptr);
}

void exit_game(t_game *game)
{
    if (!game)
        exit(EXIT_FAILURE);

    // Destroy textures
    destroy_texture(&game->textures.north, game->mlx);
    destroy_texture(&game->textures.south, game->mlx);
    destroy_texture(&game->textures.east, game->mlx);
    destroy_texture(&game->textures.west, game->mlx);

    // Destroy screen buffer
    if (game->screen.img_ptr)
        mlx_destroy_image(game->mlx, game->screen.img_ptr);

    // Free the map
    free_map(game->map);

    // Destroy window and display
    if (game->window.win)
        mlx_destroy_window(game->mlx, game->window.win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }

    exit(EXIT_SUCCESS);
}

int close_game(t_game *game)
{
    exit_game(game);
    return (0);
}

int exit_hook(t_game *game)
{
	// Free resources here if needed
	// Example:
	if (game->window.win)
		mlx_destroy_window(game->mlx, game->window.win);
	if (game->screen.img_ptr)
		mlx_destroy_image(game->mlx, game->screen.img_ptr);

	exit(0);
	return (0);
}
