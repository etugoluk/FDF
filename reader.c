/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 10:46:49 by etugoluk          #+#    #+#             */
/*   Updated: 2018/07/16 10:46:49 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			read_lines(t_lists *l, t_map *maps, int fd, char *line)
{
	while (get_next_line(fd, &line) == 1)
	{
		l->next = ft_newline(line);
		l = l->next;
		if ((*maps).max_y != count_words(line, ' ') || (*maps).max_x == 1000)
			return (0);
		(*maps).max_x++;
	}
	return (1);
}

t_map		reader(int fd, char *line)
{
	t_lists	*l;
	t_lists	*head;
	t_map	maps;

	maps.max_x = 0;
	if (get_next_line(fd, &line) != 1)
		return (maps);
	l = ft_newline(line);
	head = l;
	if (!(maps.max_y = count_words(head->content, ' ')) || maps.max_y > 999)
	{
		free_list(head);
		return (maps);
	}
	maps.max_x++;
	if (!read_lines(l, &maps, fd, line))
	{
		maps.max_x = 0;
		free_list(head);
		return (maps);
	}
	if (!(maps.arr = write_to_map(head, maps, -1, -1)))
		maps.max_x = 0;
	free_list(head);
	return (maps);
}
