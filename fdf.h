/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 13:14:01 by etugoluk          #+#    #+#             */
/*   Updated: 2018/07/16 13:14:02 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include <mlx.h>

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_coord;

typedef struct		s_point
{
	int				val;
	int				col;
}					t_point;

typedef struct		s_lists
{
	char			*content;
	struct s_lists	*next;
}					t_lists;

typedef struct		s_map
{
	double			rx;
	double			ry;
	double			rz;
	struct s_point	**arr;
	int				max_x;
	int				max_y;
	int				start_x;
	int				start_y;
	void			*mlx;
	void			*mlx_win;
}					t_map;

void				do_color(int color, t_map *maps);
void				get_color_move(int n, t_map *maps);
int					key_codes(int n, t_map *maps);
int					get_map(t_map *maps, int fd);
int					ft_atoi_16(const char *str);
void				draw_coords(t_map m, t_coord c, t_coord center);
void				draw(t_map m);
void				draw_line(t_map m, t_coord c0, t_coord c1);
t_coord				rotating(t_coord t, t_map m, t_coord c);
t_point				**malloc_map(int x, int y);
t_lists				*ft_newline(char *str);
void				free_arr(t_map *maps);
void				free_struct(char **arr);
void				free_list(t_lists *l);
int					fill_col_point(char **arr, t_point **points, int a, int b);
int					fill_point(char **arr, t_point **points, int a, int b);
t_point				**write_to_map(t_lists *l, t_map maps, int a, int b);
t_point				**free_points(t_point **points, int x);
int					read_lines(t_lists *l, t_map *maps, int fd, char *line);
t_map				reader(int fd, char *line);

#endif
