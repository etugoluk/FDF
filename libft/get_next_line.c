/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:20:49 by etugoluk          #+#    #+#             */
/*   Updated: 2018/02/01 15:20:55 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					find_n(t_lines **lst, char **line, int k)
{
	int				i;
	char			*tmp;

	i = 0;
	if (!(*lst)->buf || ft_strlen((*lst)->buf) == 0)
		return (0);
	while ((*lst)->buf[i] != '\0')
	{
		if ((*lst)->buf[i] == '\n')
			break ;
		i++;
	}
	if ((((*lst)->buf[i] == '\n') && k == 0) || (k == 1))
	{
		*line = ft_strsub((*lst)->buf, 0, i);
		tmp = (*lst)->buf;
		(*lst)->buf = ft_strsub((*lst)->buf, ft_strlen(*line) + 1,
		ft_strlen((*lst)->buf) - ft_strlen(*line));
		free(tmp);
		return (1);
	}
	return (0);
}

int					reading(int fd, t_lines **lst, char **line)
{
	int				ret;
	char			*buf;
	char			*tmp;

	if (find_n(lst, line, 0))
		return (1);
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = (*lst)->buf;
		(*lst)->buf = ft_strjoin((*lst)->buf, buf);
		free(tmp);
		if (find_n(lst, line, 0))
		{
			free(buf);
			return (1);
		}
	}
	free(buf);
	if (find_n(lst, line, 1))
		return (1);
	return (ret);
}

t_lines				*new_line(int fd)
{
	t_lines			*lst;

	if (!(lst = (t_lines *)malloc(sizeof(t_lines))))
		return (NULL);
	if (!(lst->buf = ft_strdup("")))
	{
		free(lst);
		return (NULL);
	}
	lst->fd = fd;
	lst->next = NULL;
	return (lst);
}

int					get_next_line(const int fd, char **line)
{
	static t_lines	*head;
	t_lines			*lst;

	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (!head)
		head = new_line(fd);
	lst = head;
	while (lst->next && fd != lst->fd)
		lst = lst->next;
	if (!lst->next && fd != lst->fd)
	{
		lst->next = new_line(fd);
		lst = lst->next;
	}
	return (reading(fd, &lst, line));
}
