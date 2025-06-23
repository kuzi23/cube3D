#include "cube3d.h"

int is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int is_player_start(char c)
{
    return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int is_surrounded(t_game *game, int i, int j)
{
    // Check above
    if (i == 0 || game->map[i - 1][j] == ' ')
        return 0;
    // Check below
    if (i == game->map_height - 1 || game->map[i + 1][j] == ' ')
        return 0;
    // Check left
    if (j == 0 || game->map[i][j - 1] == ' ')
        return 0;
    // Check right
    if (j == (int)strlen(game->map[i]) - 1 || game->map[i][j + 1] == ' ')
        return 0;

    // All neighbors valid, so it is surrounded
    return 1;
}

int validate_map(t_game *game)
{
	int i, j;

	for (i = 0; i < game->map_height; i++)
	{
		for (j = 0; game->map[i][j]; j++)
		{
			if (!is_valid_char(game->map[i][j]))
				return (exit_error(game, "Error:\nInvalid character in map.\n"));
			if (game->map[i][j] == '0' || is_player_start(game->map[i][j]))
			{
				if (!is_surrounded(game, i, j))
					return (exit_error(game, "Error:\nMap is not closed properly.\n"));
			}
		}
	}
	return (1);
}
