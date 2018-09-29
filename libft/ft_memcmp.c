/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:44:27 by etugoluk          #+#    #+#             */
/*   Updated: 2017/10/26 17:44:28 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *r1, const void *r2, size_t num)
{
	unsigned char	*m1;
	unsigned char	*m2;
	size_t			i;

	i = 0;
	m1 = (unsigned char *)r1;
	m2 = (unsigned char *)r2;
	while (i < num)
	{
		if (m1[i] == m2[i])
			i++;
		else
			return (m1[i] - m2[i]);
	}
	return (0);
}
