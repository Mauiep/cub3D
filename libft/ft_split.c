/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:50:21 by rovillar          #+#    #+#             */
/*   Updated: 2021/12/10 17:24:15 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static char	**free_tab(char **tab, int i)
{
	while (i-- > 0)
	{
		free(tab[i]);
		tab[i] = 0;
	}
	free(tab);
	tab = (NULL);
	return (0);
}

static char	*ft_strncpy(char const *src, char charset)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!src)
		return (NULL);
	while (src[j])
	{
		if (src[j] && is_charset(src[j], charset))
			break ;
		j++;
	}
	dest = malloc(sizeof(char) * j + 1);
	if (!dest)
		return (0);
	dest = ft_memset(dest, 0, j + 1);
	while (src[i] && i < j)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

static int	count_word(char const *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		if (str[i] && !is_charset(str[i], charset))
			count++;
		while (str[i] && !is_charset(str[i], charset))
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab || !s)
		return (free_tab(tab, j));
	while (s[i] && j < count_word(s, c))
	{
		while (s[i] && is_charset(s[i], c))
			i++;
		if (s[i] && !is_charset(s[i], c))
		{
			tab[j] = ft_strncpy(s + i, c);
			if (!tab[j])
				return (free_tab(tab, j));
			j++;
		}
		while (s[i] && !is_charset(s[i], c))
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
