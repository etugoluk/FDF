/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:13:43 by etugoluk          #+#    #+#             */
/*   Updated: 2018/07/20 12:13:44 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fill_col_point(char **arr, t_point **points, int a, int b)
{
	char	**value;
	char	*tmp;

	value = ft_strsplit(arr[b], ',');
	points[a][b].val = ft_atoi(value[0]);
	points[a][b].col = ft_atoi_16(value[1]);
	tmp = ft_itoa(points[a][b].val);
	if (ft_strcmp(value[0], tmp) || points[a][b].col == -1)
	{
		free(tmp);
		free_struct(arr);
		free_struct(value);
		return (0);
	}
	free(tmp);
	free_struct(value);
	return (1);
}

int			fill_point(char **arr, t_point **points, int a, int b)
{
	char	*tmp;

	points[a][b].val = ft_atoi(arr[b]);
	points[a][b].col = 0xFFFFFF;
	tmp = ft_itoa(points[a][b].val);
	if (ft_strcmp(arr[b], tmp))
	{
		free(tmp);
		free_struct(arr);
		return (0);
	}
	free(tmp);
	return (1);
}

t_point		**free_points(t_point **points, int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		free(points[i]);
		i++;
	}
	free(points);
	return (NULL);
}

t_point		**write_to_map(t_lists *l, t_map maps, int a, int b)
{
	t_point	**points;
	char	**arr;

	points = malloc_map(maps.max_x, maps.max_y);
	while (++a < maps.max_x)
	{
		b = -1;
		arr = ft_strsplit(l->content, ' ');
		while (++b < maps.max_y)
		{
			if (ft_strchr(arr[b], ',') && count_words(arr[b], ',') == 2)
			{
				if (!fill_col_point(arr, points, a, b))
					return (free_points(points, maps.max_x));
			}
			else
			{
				if (!fill_point(arr, points, a, b))
					return (free_points(points, maps.max_x));
			}
		}
		l = l->next;
		free_struct(arr);
	}
	return (points);
}
