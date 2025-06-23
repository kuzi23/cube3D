#include "cube3d.h"

int parse_cub_file(char *filename, t_game *game)
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (exit_error(game, "Error:\nCould not open map file.\n"));

	while (get_next_line(fd, &line) > 0)
	{
		line = skip_spaces(line);
		if (*line == '\0' || *line == '\n')
		{
			free(line);
			continue;
		}
		else if (ft_strncmp(line, "NO ", 3) == 0)
			parse_texture_path(line + 3, &game->textures, 'N');
		else if (ft_strncmp(line, "SO ", 3) == 0)
			parse_texture_path(line + 3, &game->textures, 'S');
		else if (ft_strncmp(line, "WE ", 3) == 0)
			parse_texture_path(line + 3, &game->textures, 'W');
		else if (ft_strncmp(line, "EA ", 3) == 0)
			parse_texture_path(line + 3, &game->textures, 'E');
		else if (ft_strncmp(line, "F ", 2) == 0)
			parse_colors(line + 2, &game->floor_color);
		else if (ft_strncmp(line, "C ", 2) == 0)
			parse_colors(line + 2, &game->ceiling_color);
		else
			parse_map_line(game, line);
		free(line);
	}
	close(fd);
	return (validate_map(game));
}
