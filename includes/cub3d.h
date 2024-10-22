/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:30:36 by jguerin           #+#    #+#             */
/*   Updated: 2024/10/22 15:31:41 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../GNL/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

// ------ Macros ------ //

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
# define ERR_MAP_TOO_SMALL "Map should be at least 3 lines high\n"
# define ERR_MAP_TOO_LARGE "Map shouln't be larger than 30"
# define ERR_MAP_TOO_LONG "Map shouln't be longer than 30"
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

// ------ Structures ------ //

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

// ------ Functions ------ //

// ft_check_arg //

int				check_arg(char *file);
int				check_texture(t_infomap *map);
int				load_texture(t_infomap *map);

// ft_check_file //

int				ft_check_file(char *str);
char			**copy_file(char *str, int y);

// ft_color //

char			**get_color(char *line, int i);
int				*convert_color(char **color);

// ft_fill //

char			**ft_fill_values(char **tab, t_parsing *s_parse, char **values, int i);
char			**ft_fill_map(char **tab);
void			ft_fill_info(t_infomap *s_infos, char **tab);

// ft_error //

int				ft_get_element(char *str);
int				ft_double(int i);
int				map_wall(char *str);
int				wall_around(char *str);
int				err_msg(char *arg, char *error, int code);

// ft_init_clear //

t_parsing		*ft_init_parsing(t_parsing *s_parse);
t_infomap		*ft_init_map(t_infomap *s_infos);
void			ft_clear_struct2(t_infomap *map);

// ft_init_utils //

void			ft_init_all(t_parsing *s_parse, t_infomap *s_infos);
char			**ft_clear_tab(char **tab);

// ft_map_utils //

int				ft_is_pos(char *str);
int				ft_zero_oob(char *s1, char *s, char *s2);
int				ft_is_diff(char c);
int				size_of_map(t_infomap *map);

// ft_map //

int				ft_other_char(char *str);
int				ft_space_before(char *str);
void			ft_check_map(char **map, t_parsing *s_parse, int i, int dup);
//void			get_true_map(char **tab);
// int				count_map_lines(char **map);
int				count_map_lines(t_infomap *map);

// ft_parsing //

int				ft_error(t_parsing *s_parse);
void			ft_get_error(t_parsing *s_parse, char **tab, int i);
int				ft_check_parsing(t_parsing *pars, t_infomap *map, int error);

// ft_print //

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_print_error_map(t_parsing *s_parse, int error);
void			ft_print_no_values(t_parsing *s_parse, int error);
void			ft_print_wrong_text(t_parsing *s_parse, int error);
// utils //

int				ft_strlenn(const char *s);
int				ft_sstrlen(char **s);
int				ft_atoi(char *str);
char			*ft_strdup(const char *src);

// split //

char			**ft_split(char const *s, char c);

#endif 
