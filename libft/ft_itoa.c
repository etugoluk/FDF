/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:19:39 by etugoluk          #+#    #+#             */
/*   Updated: 2017/10/30 14:19:39 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	get_size(long *i, long *n_copy)
{
	int			size;

	size = 0;
	if (*n_copy <= 0)
	{
		size++;
		*n_copy *= -1;
	}
	while (*n_copy / *i > 0)
	{
		size++;
		*i *= 10;
	}
	*i /= 10;
	return (size);
}

char			*ft_itoa(int n)
{
	long		size;
	long		i;
	long		n_copy;
	char		*number;

	n_copy = n;
	i = 1;
	size = get_size(&i, &n_copy);
	number = ft_strnew(size);
	if (!number)
		return (NULL);
	size = 0;
	if (n < 0)
		number[size++] = '-';
	if (n == 0)
		number[size++] = 48;
	while (i != 0)
	{
		number[size++] = n_copy / i + 48;
		n_copy %= i;
		i /= 10;
	}
	number[size] = '\0';
	return (number);
}
