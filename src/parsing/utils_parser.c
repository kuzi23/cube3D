#include "cube3d.h"

int count_split(char **split)
{
	int count = 0;
	while (split && split[count])
		count++;
	return count;
}

void free_split(char **split)
{
	int i = 0;
	while (split && split[i])
		free(split[i++]);
	free(split);
}

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

void	parse_map_line(t_game *game, char *line)
{
	char	**new_map;
	int		i;
	int		len;

	// Allocate space for new map array (existing lines + 1 new + NULL)
	new_map = malloc(sizeof(char *) * (game->map_height + 2));
	if (!new_map)
		exit_error(game, "Error:\nMemory allocation failed.\n");

	// Copy existing map lines (pointers, not content)
	i = 0;
	while (i < game->map_height)
	{
		new_map[i] = game->map[i];
		i++;
	}

	// Add the new line
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
		exit_error(game, "Error:\nMemory allocation failed on strdup.\n");

	new_map[i + 1] = NULL;

	// Free old map container (not the lines themselves)
	if (game->map)
		free(game->map);

	game->map = new_map;
	game->map_height++;

	// Update maximum map width if needed
	len = ft_strlen(line);
	if (len > game->map_width)
		game->map_width = len;
}