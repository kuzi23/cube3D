#include "cube3d.h"

void clear_image(t_img *img)
{
    ft_bzero(img->data, img->height * img->size_line);
}

void render_frame(t_game *game)
{
    clear_image(&game->screen);
    cast_rays(game);
    draw_walls(game);
    mlx_put_image_to_window(game->mlx, game->window.win, game->screen.img_ptr, 0, 0);
}