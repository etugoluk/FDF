/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 13:15:37 by etugoluk          #+#    #+#             */
/*   Updated: 2018/07/16 13:15:37 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**malloc_map(int x, int y)
{
	t_point		**points;
	int			a;

	a = 0;
	points = (t_point **)malloc(sizeof(t_point*) * (x));
	while (a < x)
	{
		points[a] = (t_point *)malloc(sizeof(t_point) * (y + 1));
		a++;
	}
	return (points);
}

t_lists		*ft_newline(char *str)
{
	t_lists	*t;

	t = (t_lists*)malloc(sizeof(t_lists));
	t->content = str;
	t->next = NULL;
	return (t);
}

void		free_arr(t_map *maps)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < (*maps).max_x)
	{
		free((*maps).arr[i]);
		i++;
	}
	free((*maps).arr);
}

void		free_struct(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}

void		free_list(t_lists *l)
{
	t_lists *tmp;

	tmp = l;
	while (l)
	{
		tmp = l;
		l = l->next;
		free(tmp->content);
		free(tmp);
	}
}
