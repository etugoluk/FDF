/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_intarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:53:02 by etugoluk          #+#    #+#             */
/*   Updated: 2017/11/07 11:53:03 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_intarray(int **arr, int a, int b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < a)
	{
		j = 0;
		while (j < b)
		{
			ft_putnbr(arr[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
