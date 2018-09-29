/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:19:30 by etugoluk          #+#    #+#             */
/*   Updated: 2017/10/30 14:19:31 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				count_words(const char *s, char c)
{
	int			count_words;
	int			i;

	i = 0;
	count_words = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count_words++;
			while ((s[i] != c) && (s[i + 1] != '\0'))
				i++;
		}
		i++;
	}
	return (count_words);
}

static int		count_letters(char **arr, const char *s, char c)
{
	int			count_letters;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		count_letters = 0;
		if (s[i] != c)
		{
			count_letters++;
			while ((s[i] != c) && (s[i] != '\0'))
			{
				i++;
				count_letters++;
			}
			arr[j] = ft_strnew(count_letters);
			if (!arr[j++])
				return (0);
		}
		if (s[i] != '\0')
			i++;
	}
	return (1);
}

static	void	fill(char **arr, char const *s, char c)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		j = 0;
		if (s[i] != c)
		{
			arr[k][j] = s[i];
			while ((s[i] != c) && (s[i] != '\0'))
				arr[k][j++] = s[i++];
			arr[k++][j] = '\0';
		}
		if (s[i] != '\0')
			i++;
	}
}

static void		ft_tabfree(char **arr)
{
	int			i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**result;
	int			words;

	if (!s)
		return (NULL);
	result = NULL;
	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	result[words] = 0;
	if (!count_letters(result, s, c))
	{
		ft_tabfree(result);
		return (NULL);
	}
	fill(result, s, c);
	return (result);
}
