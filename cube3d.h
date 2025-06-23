
#ifndef CUB3D_H
#define CUB3D_H

// standard Libraries
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <errno.h>


// mlx library
#include "minilibx-linux/mlx.h"
#include "config.h"

#define WIDTH 800
#define HEIGHT 600
#define FOV 60.0
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define PI 3.14159265358979323846

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
#define  FLAG_SAVE 1

#define MOVE_SPEED 0.1
#define ROT_SPEED (5 * PI / 180)

typedef struct s_img 
{ 
	void    *img_ptr;
	char    *data;
	int     bpp;
	int     size_line;
	int     endian;
	int     width;
	int     height;
}   t_img;


typedef struct s_texture
{
	t_img north;
	t_img south;
	t_img east;
	t_img west;
}	t_texture;

typedef struct s_player
{
	double x;
	double y;
	double dir;
}	t_player;

typedef struct s_ray 
{
	double  angle;
	double  distance;
	int     hit_vert;
	int     hit_horiz;
	int  wall_type;
}   t_ray;

typedef struct s_window {
    void *ptr;
    void *win;
} t_window;

typedef struct s_game
{
    void *mlx;
    t_window window;
    t_img screen;
    t_texture textures;
    t_player player;
    t_ray *rays;
    char **map;
    int map_width;
    int map_height;
    int floor_color;
    int ceiling_color;
    t_config config;
    int options;
} t_game;


int main(int argc, char **argv);

int init_game(t_game *game, int save_opt);
void init_textures(t_game *game);
void ft_bzero(void *s, size_t n);

int parse_cub_file(char *filename, t_game *game);
int validate_map(t_game *game);
void parse_colors(char *line, int *color);
void parse_texture_path(char *line, t_texture *textures, char dir);

void render_frame(t_game *game);
void cast_rays(t_game *game);
void draw_walls(t_game *game);
void draw_minimap(t_game *game);
t_ray cast_single_ray(t_game *game, double ray_angle);
void draw_walls(t_game *game);
void draw_texture_line(t_game *game, int x, int  wall_height, t_ray ray);
void draw_minimap(t_game *game);

int handle_input(int keycode, t_game *game);
int close_game(t_game *game);

void put_pixel(t_img *im, int x, int y, int color);
void get_pixel_color(t_img *img, int x, int y);

double normalize_angle(double angle);
double distance (double x1, double y1, double x2, double y2);
int exit_error(t_game *game, const char *message);
void exit_game(t_game *game);

char *skip_spaces(char *str);
int is_valid_char(char c);

#endif
