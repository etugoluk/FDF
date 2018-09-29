/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:44:09 by etugoluk          #+#    #+#             */
/*   Updated: 2017/10/26 17:44:10 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memptr, int val, size_t num)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)memptr;
	while (i < num)
	{
		if (*s == (unsigned char)val)
			return (s);
		s++;
		i++;
	}
	return (NULL);
}
