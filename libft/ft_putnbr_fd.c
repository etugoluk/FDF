/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:49:31 by etugoluk          #+#    #+#             */
/*   Updated: 2017/10/28 17:49:32 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	long	n_copy;
	long	div;

	div = 0;
	i = 1;
	n_copy = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n_copy = -n_copy;
	}
	while ((n_copy / i) > 0)
		i *= 10;
	if (n_copy != 0)
		i /= 10;
	while (i != 0)
	{
		div = n_copy / i;
		ft_putchar_fd(div + 48, fd);
		n_copy %= i;
		i /= 10;
	}
}
