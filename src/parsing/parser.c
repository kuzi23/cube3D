#include "cube3d.h"

int parse_cub_file(t_game *game, char *filename)
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (exit_error(game, "Error:\nCould not open map file.\n"));

	while ((line = get_next_line(fd)) != NULL)
	{
		char *trimmed = skip_spaces(line);

		if (*trimmed == '\0' || *trimmed == '\n')
		{
			free(line);
			continue;
		}
		else if (strncmp(trimmed, "NO ", 3) == 0)
			parse_texture_path(trimmed + 3, &game->textures, 'N');
		else if (strncmp(trimmed, "SO ", 3) == 0)
			parse_texture_path(trimmed + 3, &game->textures, 'S');
		else if (strncmp(trimmed, "WE ", 3) == 0)
			parse_texture_path(trimmed + 3, &game->textures, 'W');
		else if (strncmp(trimmed, "EA ", 3) == 0)
			parse_texture_path(trimmed + 3, &game->textures, 'E');
		else if (strncmp(trimmed, "F ", 2) == 0)
			parse_colors(trimmed + 2, &game->floor_color);
		else if (strncmp(trimmed, "C ", 2) == 0)
			parse_colors(trimmed + 2, &game->ceiling_color);
		else
			parse_map_line(game, trimmed);

		free(line);
	}
	close(fd);
	return (validate_map(game));
}
