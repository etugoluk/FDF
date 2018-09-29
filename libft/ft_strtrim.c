/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:19:20 by etugoluk          #+#    #+#             */
/*   Updated: 2017/10/30 14:19:21 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	j = (int)ft_strlen(s);
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	while (((s[j] == ' ') || (s[j] == '\n') || (s[j] == '\t')
		|| (s[j] == '\0')) && (j >= 0))
		j--;
	if (i == (int)ft_strlen(s))
		i = 0;
	new = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!new)
		return (NULL);
	while (i <= j)
		new[k++] = s[i++];
	new[k] = '\0';
	return (new);
}
