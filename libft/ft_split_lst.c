/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:50:21 by rovillar          #+#    #+#             */
/*   Updated: 2022/10/14 19:40:47 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy_following(char const *src, int i, int j, int k)
{
	char	*dest;

	dest = malloc(sizeof(char) * j + 1);
	if (!dest)
		return (0);
	dest = ft_memset(dest, 0, j + 1);
	while (src[i] == ' ')
		i++;
	while (src[i] && i < j)
	{
		dest[k] = src[i];
		k++;
		i++;
	}
	return (dest);
}

static char	*ft_strncpy(char const *src, t_quotes quo)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	if (!src)
		return (NULL);
	while (src[j] == ' ')
		j++;
	while (src[j])
	{
		if ((src[j] == '\"') && (quo.d_q % 2 == 0))
			quo.q++;
		if ((src[j] == '\'') && (quo.q % 2 == 0))
			quo.d_q++;
		if (src[j] && is_charset_2(src[j], quo))
			break ;
		j++;
	}
	return (ft_strncpy_following(src, i, j, k));
}

static int	count_word(char const *str, t_quotes quo)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i = count_word_2(str, i, quo);
		if (str[i] && !is_charset_2(str[i], quo))
			count++;
		i = count_word_3(str, i, quo);
		if (str[i] && is_charset_2(str[i], quo))
			count++;
	}
	return (count);
}

char	**ft_split_lst_following(char const *s, t_quotes quo, int j, char **tab)
{
	int	i;

	i = 0;
	while (s[i] && j < count_word(s, quo))
	{
		if (s[i] && !is_charset_2(s[i], quo))
		{
			tab[j] = ft_strncpy(s + i, quo);
			if (!tab[j])
				return (free_tab(tab, j));
			j++;
		}
		i = count_word_3(s, i, quo);
		if (s[i] && is_charset_2(s[i], quo))
		{
			tab[j] = cpy_charset(s + i, quo);
			if (!tab[j])
				return (free_tab(tab, j));
			j++;
		}
		i = count_word_2(s, i, quo);
	}
	return (tab[j] = NULL, tab);
}

char	**ft_split_lst(char const *s)
{
	int			j;
	char		**tab;
	t_quotes	quo;

	j = 0;
	init_stuct_quo(&quo);
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word(s, quo) + 1));
	if (!tab)
		return (free_tab(tab, j));
	return (ft_split_lst_following(s, quo, j, tab));
}
