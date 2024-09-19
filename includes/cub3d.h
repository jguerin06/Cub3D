/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:30:36 by jguerin           #+#    #+#             */
/*   Updated: 2024/09/19 11:16:43 by jguerin          ###   ########.fr       */
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

// ------ Structures ------ //

typedef struct s_parse
{
	int	north;
	int	south;
	int	east;
	int	west;
	int	sprite;
	int	floor;
	int	ceiling;
	int	map_wg_char;
	int	map_end;
	int	map_wall;
	int	map_dup;
	int	map_no_pos;
	int	no_map;
	int	wrong_line;

}	t_struct;

typedef struct s_infos
{
	int	x;
	int	y;

}	t_struct2;

// ------ Functions ------ //


// ft_check //

int			ft_is_cub(char *file);
int			ft_check_file(char *str, int i);

// ft_error //

int			ft_get_element(char *str);
int			ft_double(int i);
int			map_wall(char *str);
int			wall_around(char *str);

// ft_init //

t_struct	*ft_init_struct(t_struct *s_parse);

// ft_map_utils //

int			ft_is_pos(char *str);
int			ft_zero_oob(char *s1, char *s, char *s2);
int			ft_is_diff(char c);

// ft_map //

int			ft_other_char(char *str);
int			ft_space_before(char *str);
t_struct	*ft_check_map2(t_struct *s_parse, int dup, char *str);
t_struct	*ft_check_map(char **map, t_struct *s_parse, int i, int dup);

// ft_parsing //

int			ft_error(t_struct *s_parse);
t_struct	*ft_get_error(t_struct *s_parse, char **tab, int i);

// utils //

int			ft_strlenn(const char *s);
int			ft_atoi(char *str);
char		*ft_strdup(const char *src);
char		**ft_split(char const *s, char c);

#endif 
