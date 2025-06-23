
#include "cube3d.h"

int exit_error(t_game *game, const char *str)
{
	if (str)
		write(STDERR_FILENO, str, strlen(str));
	exit_game(game);
	return (EXIT_FAILURE);
}

int main(int argc,  char **argv)
{
	t_game game;
	int save_opt;

	//handle -save option (optional screenshot)
	save_opt = (argc >= 2 && !strcmp(argv[1], "-save"));
	if (argc < (2 + save_opt))
		return (exit_error(&game, "error:\nNo map specified.\n"));
	//initialize the game
	if (!init_game(&game, save_opt))
		return (exit_error(&game, "Error:\nFailed to initialize game.\n"));

	//parse the map and configuration from .cub file
	if (!parse_config(&game.config, argv[1 + save_opt]))
		return (exit_error(&game, "error:\nInvalid or corrupt map file.\n"));

	//finalize initialization (textures, raycasting setup, etc.)
	if (!finish_init(&game))
		return (exit_error(&game, "Error:\n Failed to complete initialization. \n"));

	//Handle screenshot and exit if requested
	if (game.options & FLAG_SAVE)
		return (screenshot(&game));
	
	//set up input hooks and game loop
	mlx_hook(game.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.window.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_hook(game.window.win, X_EVENT_EXIT, 0, &exit_hook, &game);
	mlx_loop_hook(game.window.ptr, &main_loop, &game);
	mlx_loop(game.window.ptr);

	return (EXIT_SUCCESS);
}
