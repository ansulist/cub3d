/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:35:28 by juhaamid          #+#    #+#             */
/*   Updated: 2024/03/07 17:40:40 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

# define WINDOW_SIZE_X 800
# define WINDOW_SIZE_Y 800

// struct for keyhold and release
typedef struct s_key
{
	_Bool	w;
	_Bool	s;
	_Bool	a;
	_Bool	d;
	_Bool	left;
	_Bool	right;
}	t_key;

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_player
{
	t_point	pos;
	t_point	delta;
	t_point	dir;
	t_point	plane;
	float	angle;
}	t_player;

typedef struct s_image
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		tex_y;
	int		tex_x;
	char	**map;
}	t_image;

enum
{
	NO_DIRECTION = 0,
	N_TEXT = 1,
	E_TEXT = 2,
	S_TEXT = 3,
	W_TEXT = 4,
	F = 5,
	C = 6,
};

typedef struct s_map
{
	int		size_x;
	int		size_y;
	char	**blocs;
	int		bloc_px_size;
}	t_map;

typedef struct s_textures
{
	// store only path of the texture from the map.cub
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_textures;

typedef struct s_cub3d
{
	int			color_f;
	int			color_c;
	t_image		image;
	void		*mlx;
	void		*win;
	char		**maps;
	bool		show_map;
	char		player_position;
	t_player	player;
	t_map		map;
	t_key		key;
	t_textures	textures;
	t_image		text[5];
}	t_cub3d;

typedef struct s_racalc
{
	int		x;
	float	camera_x;
	t_point	ray_direction;
	t_point	side_dist;
	t_point	delta_dist;
	t_point	step;
	t_point	map;
	int		side;
	float	distance_to_wall;
}	t_racalc;

typedef struct s_draw_wcalc
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	float	wall_x;
	float	step;
	float	texture_pos;
}	t_draw_wcalc;

# define PI 3.1415926535
// # define DEG_TO_RAD(degrees) ((degrees) * PI / 180.0)
# define PLAYER_SPEED 100

# define FOV 60

# define ESC 53
# define UP 126
# define DOWN 125
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define RIGHT 124
# define LEFT 123
# define SHOW_MAP 46
# define ON_MOUSE_DW 4

void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	draw_ray(t_cub3d *cub, int color);
int		valid(char *file);
void	display(t_cub3d *cub);
int		keymove(t_cub3d *cub3d);
void	leftright(int code, t_cub3d *cub);
void	dda(t_cub3d *m, t_point p1, t_point p2, int color);
void	draw_floor(t_cub3d *cub3d, int color);
void	draw_cieling(t_cub3d *cub3d, int color);
int		keypressed(int code, t_cub3d *cub3d);
int		keyrelease(int code, t_cub3d *cub3d);
int		load_config_from_file(char *cubfile, t_cub3d *cub3d);
int		open_map(char *av);
int		load_color(int fd, char *id, int *hex_color);
int		parse_rgb_color(char *color, int *hex_color);
char	*load_texture_path(int fd, char *id);
int		ft_free_twod_array(char **str);
int		free_path_texture(t_cub3d *cub3d);
int		free_all_element(t_cub3d *cub3d);
int		check_lines(t_cub3d *cub3d);
void	load_wall_textures(t_cub3d *m);
void	init_img(t_image *img);
void	init_tex(t_cub3d *m);
void	reset_image(t_cub3d *cub3d);
void	raycast(t_cub3d *cub3d, t_image *texture);
int		get_image_pixel(t_image *text, int x, int y);
int		map_to_array(t_cub3d *cub3d, int fd);
int		map_size_count(char *cubfile, int *size_x, int *size_y);
int		check_map_full(t_cub3d *cub3d);
int		close_window(t_cub3d *cub3d);
bool	check_all_path_ext(t_cub3d *cub3d);
int		check_map_more(t_cub3d *cub3d);
void	pick_texture(t_cub3d *cub3d, t_racalc *rc, t_image *texture);
void	init_racalc(t_cub3d *cub3d, int x, t_racalc *rc);
void	check_wall_hit(t_cub3d *cub3d, t_racalc *rc);
void	calculate_distance_to_wall(t_racalc *rc);
t_point	calculate_ray_direction(t_cub3d *cub3d, float camera_x);
t_point	calculate_delta_distance(t_point *ray_direction);
t_point	calculate_step(t_point *ray_direction);
t_point	calcsid(t_cub3d *cub3d, t_point *rayd, t_point *map, t_point *deltd);
int		check_sides_maps_horizontal(t_cub3d *cub3d);
int		check_sides_maps_vertical(t_cub3d *cub3d);
int		ft_strcmp(char *s1, char *s2);
void	keya_handler(t_cub3d *cub3d);
void	keyd_handler(t_cub3d *cub3d);
void	keyw_handler(t_cub3d *cub3d);
void	keys_handler(t_cub3d *cub3d);
void	keyleft_handler(t_cub3d *cub3d);
void	keyright_handler(t_cub3d *cub3d);
int		check_inside_map(t_cub3d *cub3d);
int		check_player_direction(t_cub3d *cub3d, int x, int y, int player_pos);
int		check_space_neibours(t_cub3d *cub3d, int y, int x);
int		check_sides_maps(t_cub3d *cub3d);
int		check_walls_top_and_bottom(t_cub3d *cub3d);
int		check_empty(t_cub3d *cub3d);
int		check_validity(t_cub3d *cub3d);
void	check_plane_for_player(t_cub3d *cub3d);
void	check_direction_for_player(t_cub3d *cub3d);
void	init_cub3d(t_cub3d *cub3d);
void	init_image(t_cub3d *cub3d);
int		check_ac_av(int ac, char **av);
char	*load_texture_path(int fd, char *id);
char	**custom_split(char *line);
int		parse_map(int fd, t_cub3d *cub3d, int size_x, int size_y);
int		load_texture(char **splitted, char **texture);
int		fill_map_blocs(int fd, t_cub3d *cub3d, int size_x, int i);
int		free_path_texture(t_cub3d *cub3d);
float	deg_to_rad(float a);
#endif
