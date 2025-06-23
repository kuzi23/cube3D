
#include "cube3d.h"

static int load_texture(t_game *game, t_img *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
	if(!tex->img_ptr)
		return (0);

	tex->data = mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->size_line, &tex->endian);
	if(!tex->data)
		return (0);
	return (1);
}

int init_textures(t_game *game)
{
	if (!load_texture(game, &game->textures.north, game->config.texture_north))
		return (0);
	if (!load_texture(game, &game->textures.south, game->config.texture_south))
		return (0);
	if (!load_texture(game, &game->textures.east, game->config.texture_east))
		return (0);
	if (!load_texture(game, &game->textures.west, game->config.texture_west))
		return (0);
	return (1);
}
