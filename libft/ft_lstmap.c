/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:21:16 by etugoluk          #+#    #+#             */
/*   Updated: 2017/10/30 15:21:18 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (lst && f)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return (NULL);
		if (lst)
		{
			new = f(lst);
			new->next = ft_lstmap(lst->next, f);
			return (new);
		}
	}
	return (NULL);
}
