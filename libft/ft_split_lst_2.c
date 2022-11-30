/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lst_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:50:42 by asokolov          #+#    #+#             */
/*   Updated: 2022/10/14 19:58:09 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_charset_2(char c, t_quotes quo)
{
	if (quo.q % 2 == 1 || quo.d_q % 2 == 1)
		return (0);
	else if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

static int	is_charset(char c, t_quotes quo)
{
	if (quo.q % 2 == 1 || quo.d_q % 2 == 1)
		return (0);
	else if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

char	*cpy_charset_2(char const *src, int i, int j)
{
	char	*dest;

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

char	*cpy_charset(char const *src, t_quotes quo)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!src)
		return (NULL);
	while (src[j])
	{
		if ((src[j] == '\"') && (quo.d_q % 2 == 0))
			quo.q++;
		if ((src[j] == '\'') && (quo.q % 2 == 0))
			quo.d_q++;
		if (src[j] && !is_charset(src[j], quo))
			break ;
		j++;
	}
	return (cpy_charset_2(src, i, j));
}
