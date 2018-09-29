/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:45:24 by etugoluk          #+#    #+#             */
/*   Updated: 2017/10/26 17:45:25 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destptr, const char *srcptr, size_t num)
{
	size_t i;

	i = 0;
	while ((i < num) && (srcptr[i] != '\0'))
	{
		destptr[i] = srcptr[i];
		i++;
	}
	while (i < num)
		destptr[i++] = '\0';
	return (destptr);
}
