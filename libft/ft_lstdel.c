/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:20:44 by etugoluk          #+#    #+#             */
/*   Updated: 2017/10/30 15:20:45 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *add;

	if (alst && *alst && del)
	{
		add = *alst;
		while ((*alst)->next != NULL)
		{
			add = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = add;
		}
		ft_lstdelone(alst, del);
	}
}
