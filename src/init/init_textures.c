
#include "cub3d.h"

static int load_texture(t_game *game, t_img *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
	if(!tex->img_ptr)
		return (0);

	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->line_len, &tex->endian);
	if(!tex->addr)
		return (0);
	return (1);
}

int init_textures(t_game *game)
{
	if (!load_texture(game, &game->textures.north, game->config.north_path))
		return (0);
	if (!load_texture(game, &game->textures.south, game->config.south_path))
		return (0);
	if (!load_texture(game, &game->textures.east, game->config.east_path))
		return (0);
	if (!load_texture(game, &game->textures.west, game->config.west_path))
		return (0);
	return (1);
}
