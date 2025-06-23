#ifndef CONFIG_H
# define CONFIG_H

typedef struct s_config
{
    char *texture_north;
    char *texture_south;
    char *texture_east;
    char *texture_west;
    char *texture_sprite;

    int floor_color;
    int ceiling_color;

    char **map;
    int map_width;
    int map_height;
} t_config;

#endif