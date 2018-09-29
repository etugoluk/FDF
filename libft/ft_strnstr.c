/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:46:05 by etugoluk          #+#    #+#             */
/*   Updated: 2017/10/30 14:46:06 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *n, size_t len)
{
	if (*n == '\0')
		return ((char *)s);
	while ((*s != '\0') && (len-- >= ft_strlen(n)))
	{
		if (ft_strncmp(s, n, ft_strlen(n)) == 0)
			return ((char *)s);
		s++;
	}
	return (0);
}
