/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 10:46:31 by etugoluk          #+#    #+#             */
/*   Updated: 2018/07/16 10:46:32 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_color(int color, t_map *maps)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < (*maps).max_x)
	{
		b = 0;
		while (b < (*maps).max_y)
		{
			(*maps).arr[a][b].col = color;
			b++;
		}
		a++;
	}
}

void	get_color_move(int n, t_map *maps)
{
	if (n == 18)
		do_color(0xFF0000, maps);
	else if (n == 19)
		do_color(0xFF9900, maps);
	else if (n == 20)
		do_color(0xFFFF00, maps);
	else if (n == 21)
		do_color(0x00FF00, maps);
	else if (n == 23)
		do_color(0x00FFFF, maps);
	else if (n == 22)
		do_color(0x0066FF, maps);
	else if (n == 26)
		do_color(0x660099, maps);
	else if (n == 28)
		do_color(0xFFFFFF, maps);
	else if (n == 125)
		(*maps).start_y += 10;
	else if (n == 126)
		(*maps).start_y -= 10;
	else if (n == 123)
		(*maps).start_x -= 10;
	else if (n == 124)
		(*maps).start_x += 10;
}

int		key_codes(int n, t_map *maps)
{
	if (n == 53)
	{
		mlx_destroy_window((*maps).mlx, (*maps).mlx_win);
		free_arr(maps);
		exit(0);
		return (0);
	}
	else if (n == 12)
		(*maps).rz += M_PI / 180;
	else if (n == 14)
		(*maps).rz -= M_PI / 180;
	else if (n == 1)
		(*maps).rx += M_PI / 180;
	else if (n == 13)
		(*maps).rx -= M_PI / 180;
	else if (n == 0)
		(*maps).ry += M_PI / 180;
	else if (n == 2)
		(*maps).ry -= M_PI / 180;
	get_color_move(n, maps);
	mlx_clear_window((*maps).mlx, (*maps).mlx_win);
	draw(*maps);
	return (0);
}

int		get_map(t_map *maps, int fd)
{
	*maps = reader(fd, NULL);
	if (!(*maps).max_x)
		return (0);
	(*maps).rx = -0.8;
	(*maps).ry = -0.3;
	(*maps).rz = 0.2;
	(*maps).start_x = 450;
	(*maps).start_y = 100;
	(*maps).mlx = mlx_init();
	(*maps).mlx_win = mlx_new_window((*maps).mlx, 1600, 800, "fdf");
	return (1);
}

int		main(int argc, char **argv)
{
	t_map	maps;
	int		fd;

	if (argc != 2)
	{
		ft_putendl("wrong arguments");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("wrong file");
		return (0);
	}
	if (!get_map(&maps, fd))
	{
		ft_putendl("wrong data");
		return (0);
	}
	mlx_hook(maps.mlx_win, 2, 1L << 0, key_codes, &maps);
	draw(maps);
	mlx_loop(maps.mlx);
	close(fd);
	return (0);
}
