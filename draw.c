/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 10:46:39 by etugoluk          #+#    #+#             */
/*   Updated: 2018/07/16 10:46:40 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_atoi_16(const char *str)
{
	int		i;
	int		result;
	int		add;
	int		k;

	i = 2;
	result = 0;
	k = pow(16, ft_strlen(str) - 3);
	if (ft_strlen(str) < 2 || ((str[0] != '0') && str[1] != 'x'))
		return (-1);
	while (((str[i] >= 48) && (str[i] <= 57)) || ((str[i] >= 65)
		&& (str[i] <= 70)) || ((str[i] >= 97) && (str[i] <= 102)))
	{
		if ((str[i] >= 48) && (str[i] <= 57))
			add = (int)(str[i] - 48);
		else if ((str[i] >= 65) && (str[i] <= 70))
			add = str[i] - 65 + 10;
		else if ((str[i] >= 97) && (str[i] <= 102))
			add = str[i] - 97 + 10;
		result += add * k;
		k /= 16;
		i++;
	}
	return (i == (int)ft_strlen(str) && result < 16777216 ? result : -1);
}

void		draw_coords(t_map m, t_coord c, t_coord center)
{
	int		square;
	t_coord	c0;
	t_coord	c1;

	square = ft_minimum(600 / m.max_x, 1000 / m.max_y);
	c0.x = c.y * square + m.start_x;
	c0.y = c.x * square + m.start_y;
	c0.z = m.arr[c.x][c.y].val * square / 2;
	c0.color = m.arr[c.x][c.y].col;
	if (c.y != m.max_y - 1)
	{
		c1.x = (c.y + 1) * square + m.start_x;
		c1.y = c.x * square + m.start_y;
		c1.z = m.arr[c.x][c.y + 1].val * square / 2;
		c1.color = m.arr[c.x][c.y + 1].col;
		draw_line(m, rotating(c0, m, center), rotating(c1, m, center));
	}
	if (c.x != m.max_x - 1)
	{
		c1.x = c.y * square + m.start_x;
		c1.y = (c.x + 1) * square + m.start_y;
		c1.z = m.arr[c.x + 1][c.y].val * square / 2;
		c1.color = m.arr[c.x + 1][c.y].col;
		draw_line(m, rotating(c0, m, center), rotating(c1, m, center));
	}
}

void		draw(t_map m)
{
	t_coord count;
	t_coord center;

	count.x = 0;
	count.y = 0;
	center.x = 800;
	center.y = 400;
	center.z = 0;
	while (count.x < m.max_x)
	{
		count.y = 0;
		while (count.y < m.max_y)
		{
			draw_coords(m, count, center);
			count.y++;
		}
		count.x++;
	}
}

void		draw_line(t_map m, t_coord c0, t_coord c1)
{
	t_coord	d;
	int		signx;
	int		signy;
	int		error;

	d.x = abs(c1.x - c0.x);
	d.y = abs(c1.y - c0.y);
	signx = c0.x < c1.x ? 1 : -1;
	signy = c0.y < c1.y ? 1 : -1;
	error = d.x - d.y;
	mlx_pixel_put(m.mlx, m.mlx_win, c1.x, c1.y, c0.color);
	while (c0.x != c1.x || c0.y != c1.y)
	{
		mlx_pixel_put(m.mlx, m.mlx_win, c0.x, c0.y, c1.color);
		if (error * 2 > -d.y)
		{
			error -= d.y;
			c0.x += signx;
		}
		else
		{
			error += d.x;
			c0.y += signy;
		}
	}
}

t_coord		rotating(t_coord t, t_map m, t_coord c)
{
	t_coord c0;
	t_coord c1;
	t_coord c2;

	c0.x = t.x;
	c0.y = (t.y - c.y) * cos(m.rx) + (t.z - c.z) * sin(m.rx) + c.y;
	c0.z = (t.z - c.z) * cos(m.rx) - (t.y - c.y) * sin(m.rx) + c.z;
	c1.x = (c0.x - c.x) * cos(m.ry) - (c0.z - c.z) * sin(m.ry) + c.x;
	c1.y = c0.y;
	c1.z = (c0.z - c.z) * cos(m.ry) + (c0.x - c.x) * sin(m.ry) + c.z;
	c2.x = (c1.x - c.x) * cos(m.rz) + (c1.y - c.y) * sin(m.rz) + c.x;
	c2.y = (c1.y - c.y) * cos(m.rz) - (c1.x - c.x) * sin(m.rz) + c.y;
	c2.color = t.color;
	return (c2);
}
