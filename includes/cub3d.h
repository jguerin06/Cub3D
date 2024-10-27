/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:30:36 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/27 11:34:53 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../srcs/GNL/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

// ------ Parsing ------ //

# define ERR_USAGE "./cub3d <path/to/map.cub>\n"
# define ERR_INVALID_FILE "File doesn't exist\n"
# define FILE_NOT_CUB "Not a .cub file\n"
# define ERR_FILE_NOT_PNG "Not a .png file\n"
# define ERR_FILE_IS_DIR "is a directory\n"
# define ERR_INVALID_MAP "Map description is either wrong or incomplete\n"
# define ERR_INV_LETTER "Invalid letter in map\n"
# define ERR_NUM_PLAYER "Map has more than one player\n"
# define ERR_RGB_VAL "Invalid RGB value (min : 0, max : 255)\n"
# define ERR_TEXTURE_MISS "Missing texture(s)\n"
# define ERR_INV_TEXTURE "Invalid texture(s)\n"
# define ERR_COLOR_MISS "Missing color(s)\n"
# define ERR_INVALID_COLOR "Invalid color(s) parameter\n"
# define ERR_MAP_MISSING "Missing map\n"
# define ERR_MAP_DUP "Dup has been found in map\n"
# define ERR_MAP_TOO_SMALL "Map should be at least 3 lines high\n"
# define ERR_MAP_TOO_LARGE "Map shouldn't be larger than 30\n"
# define ERR_MAP_TOO_LONG "Map shouldn't be longer than 30\n"
# define ERR_MAP_NO_WALLS "Map is not surrounded by walls\n"
# define ERR_MAP_LAST "Map is not the last element in file\n"
# define ERR_PLAYER_POS "Invalid player position\n"
# define ERR_PLAYER_DIR "Map has nos player position (expected N, S, E or W)\n"

# define MAX_WIDTH 30
# define MAX_HEIGHT 30

enum	e_output
{
	SUCCESS = 0,
	ERROR = -1
};

typedef struct s_parse
{
	int	north;
	int	south;
	int	east;
	int	west;
	int	floor;
	int	ceiling;
	int	map_wg_char;
	int	map_end;
	int	map_wall;
	int	map_dup;
	int	map_no_pos;
	int	no_map;
	int	wrong_line;

}	t_parsing;

typedef struct s_infos
{
	int		x;
	int		y;
	int		height;
	int		width;
	int		*floor_color;
	int		*ceiling_color;
	int		start_of_map;
	int		end_of_map;
	int		map_line;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	**floor;
	char	**ceiling;
	char	**map;
	char	**truemap;
	mlx_texture_t	*text_no;
	mlx_texture_t	*text_so;
	mlx_texture_t	*text_ea;
	mlx_texture_t	*text_we;
}	t_infomap;

// ------ Macros ------ //

# define NAME		"Cub3D"

// # define WIDTH		3840
// # define HEIGHT		1920
// # define MAPSQUARE	48.0

# define WIDTH		1920
# define HEIGHT		1080
# define MAPSQUARE	16.0

# define PI			3.14159265359
# define PLRSPEED	1

// ------ Colors ------ //

# define BLACK	0x000000FF
# define WHITE	0xFFFFFFFF
# define RED	0xFF0000FF
# define GREEN	0x00FF00FF
# define BLUE	0x0000FFFF
# define YELLOW	0xFFFF00FF
# define PURPLE	0xFF00FFFF
# define CYAN	0x00FFFFFF
# define ORANGE	0xFFA500FF
# define PINK	0xFFC0CBFF
# define GREY	0x808080FF

# define WALL	0x474F7AFF
# define FLOOR	0xFFD0ECFF

// ------ Structures ------ //

typedef struct s_opt
{
	float		x;
	float		y;
	float		pdx;
	float		pdy;
	float		pa;
	int			mouse_x;
	int			mouse_y;
	int			pos_x;
	int			pos_y;
	bool		mouse_visible;
	char		direction;
	char		*floor;
	char		*ceiling;
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*plr_img;
	mlx_image_t	*map_img;
	mlx_image_t	*ray_img;
	mlx_image_t	*celling_img;
	mlx_image_t	*floor_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*weapon_img;
	int			total_frames;
	int			current_frame;
	int			animation_active;
	int			weapon;
	mlx_texture_t	*textures[4];
}	t_opt;

typedef struct s_vector
{
	float	x;
	float	y;
	bool	hit;
}	t_vector;

// ------ Raycast ------ //

int		start_raycast(t_infomap	map);
void	draw_map(t_opt *opt, t_infomap map);
void	draw_square(t_opt *opt, int x, int y, uint32_t color);
void	init_player(t_opt *opt);
void	put_player(t_opt *opt);
void	draw_ray(t_opt *opt);
void	draw_3d(t_opt *opt);
void	ft_hook(void *param);
void	draw_celling(t_opt *opt, t_infomap map);
void	draw_floor(t_opt *opt, t_infomap map);
void	exit_cub(t_opt *opt);
void	draw_weapon(t_opt *opt, int	weapon);
void	animate_knife(t_opt *opt);
void	init_knife_animation(t_opt *opt);
void	scrollhook(double xdelta, double ydelta, void* param);
void	draw_little_square(mlx_image_t *img, int x, int y, int size, int color);
t_vector	wall_intersector(t_vector v1, double a1, t_vector v2, double a2);
t_vector	next_grid_intersector(t_vector player, double angle, int x, int y);

// ------ Utils ------ //

void	render_wall(t_opt *opt, int ray_index, double dist, int facing, double border_dist);
int		find_pixel_color(mlx_texture_t *texture, int x, int y);
int		is_vertical(double x, double y);
int		get_rgba(int r, int g, int b, int a);
char	*ft_itoa(int n);
char	*ft_strjoin_nf(char *s1, char *s2);

// ------ Movement ------ //

void	turn_left(t_opt *opt);
void	turn_right(t_opt *opt);
void	go_right(t_opt *opt);
void	go_left(t_opt *opt);
void	go_up(t_opt *opt);
void	go_down(t_opt *opt);

// ------ Mouse ------ //

void	mouse_control(t_opt *opt);
void	mouse_visible(t_opt *opt);
void	mouse_hidden(t_opt *opt);

// ------ Parsing ------ //

// ft_check_arg //

int				check_arg(char *file);
int				check_texture(t_infomap *map);

// ft_check_file //

int				ft_check_file(char *str);
int				load_texture(t_infomap *map);
int				copy_map(t_infomap *map);
int				check_info(t_infomap *map);
char			**copy_file(char *str, int y);

// ft_color //

char			**get_color(char *line, int i);
int				*convert_color(char **color);

// ft_fill //

char			**ft_fill_values(char **tab, t_parsing *s_parse, char **values, int i);
char			**ft_fill_map(char **tab);
void			ft_fill_info(t_infomap *s_infos, char **tab);

// ft_error //

int				ft_double(int i);
int				err_msg(char *arg, char *error, int code);

// ft_init_clear //

t_parsing		*ft_init_parsing(t_parsing *s_parse);
t_infomap		*ft_init_map(t_infomap *s_infos);
void			ft_clear_map(t_infomap *map);
void			ft_clear_map2(t_infomap *map);


// ft_init_utils //

void			ft_init_all(t_parsing *s_parse, t_infomap *s_infos);
void			ft_clear_tab(char **tab);

// ft_map_utils //

int				ft_zero_oob(char *s1, char *s, char *s2);
int				size_of_map(t_infomap *map);
int				count_map_lines(t_infomap *map);

// ft_map_utils 2 //

int				map_wall(char *str);
int				wall_around(char *str);
int				check_corner(char **map, int i, int j);
int				player_position(t_infomap *map, t_opt *player);
int				check_map_is_at_the_end(t_infomap *map);

// ft_map_utils 3 //

int				ft_get_element(char *str);
int				ft_is_pos(char *str);
int				ft_other_char(char *str);
int				ft_is_diff(char c);


// ft_map //

void			ft_check_map(char **map, t_parsing *s_parse, int i, int dup);

// ft_parsing //

int				ft_error(t_parsing *s_parse);
void			ft_get_error(t_parsing *s_parse, char **tab, int i);
int				map_initializer(char *path, t_parsing *pars, t_infomap *map);
int				ft_check_parsing(t_parsing *pars, t_infomap *map, int error);

// ft_print //

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_print_error_map(t_parsing *s_parse, int error);

// utils //

int				ft_strlenn(const char *s);
int				ft_sstrlen(char **s);
int				ft_atoi(char *str);
char			*ft_strdup(const char *src);
char			**ft_sstrdup(char **s1);

// split //

char			**ft_split(char const *s, char c);

#endif 
