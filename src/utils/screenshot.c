#include "cube3d.h"


static void	write_int(int fd, int value)
{
	write(fd, &value, 4);
}

static void	write_bmp_header(int fd, t_game *game)
{
    (void)game;
	int file_size = 54 + (WIDTH * HEIGHT * 4);
	int padding = 0;

	write(fd, "BM", 2);
	write_int(fd, file_size);
	write_int(fd, 0);
	write_int(fd, 54);

	write_int(fd, 40);
	write_int(fd, WIDTH);
	write_int(fd, -HEIGHT); // top-down
	write(fd, "\1\0", 2);
	write(fd, "\20\0", 2); // 32 bits
	write_int(fd, 0);
	write_int(fd, WIDTH * HEIGHT * 4 + padding);
	write_int(fd, 0);
	write_int(fd, 0);
	write_int(fd, 0);
	write_int(fd, 0);
}

int screenshot(t_game *game)
{
	int fd;

	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (exit_error(game, "Failed to open screenshot.bmp"));

	write_bmp_header(fd, game);
	write(fd, game->screen.data, WIDTH * HEIGHT * 4);

	close(fd);
	exit_game(game);  // Exit after saving screenshot
	return (0);
}