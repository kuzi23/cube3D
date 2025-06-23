#include "cube3d.h"

char *skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return str;
}

void parse_colors(char *line, int *color)
{
	int r, g, b;
	char **split;

	split = ft_split(line, ',');
	if (!split || count_split(split) != 3)
		exit_error(NULL, "Error:\nInvalid color format.\n");

	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error(NULL, "Error:\nColor values must be 0-255.\n");

	*color = (r << 16) | (g << 8) | b;
	free_split(split);
}

void parse_texture_path(char *line, t_texture *textures, char dir)
{
	char *path = skip_spaces(line);

	if (dir == 'N')
		textures->north.img_ptr = mlx_xpm_file_to_image(textures->north.img_ptr, path, &textures->north.width, &textures->north.height);
	else if (dir == 'S')
		textures->south.img_ptr = mlx_xpm_file_to_image(textures->south.img_ptr, path, &textures->south.width, &textures->south.height);
	else if (dir == 'W')
		textures->west.img_ptr = mlx_xpm_file_to_image(textures->west.img_ptr, path, &textures->west.width, &textures->west.height);
	else if (dir == 'E')
		textures->east.img_ptr = mlx_xpm_file_to_image(textures->east.img_ptr, path, &textures->east.width, &textures->east.height);
}
