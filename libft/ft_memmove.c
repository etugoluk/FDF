/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:43:56 by etugoluk          #+#    #+#             */
/*   Updated: 2017/10/26 17:43:56 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	char *d;
	char *s;

	d = (char *)destptr;
	s = (char *)srcptr;
	if (destptr < srcptr)
		ft_memcpy(destptr, srcptr, num);
	else
	{
		while ((int)--num >= 0)
		{
			d[num] = s[num];
		}
	}
	return (destptr);
}
