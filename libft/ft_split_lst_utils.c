/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lst_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:58:53 by asokolov          #+#    #+#             */
/*   Updated: 2022/10/14 19:41:23 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_stuct_quo(t_quotes *quo)
{
	quo->q = 0;
	quo->d_q = 0;
}

int	count_word_2(char const *str, int i, t_quotes quo)
{
	while (str[i] && is_charset_2(str[i], quo))
	{
		if ((str[i] == '\"') && (quo.d_q % 2 == 0))
			quo.q++;
		if ((str[i] == '\'') && (quo.q % 2 == 0))
			quo.d_q++;
		i++;
	}
	return (i);
}

int	count_word_3(char const *str, int i, t_quotes quo)
{
	while (str[i] && !is_charset_2(str[i], quo))
	{
		if ((str[i] == '\"') && (quo.d_q % 2 == 0))
			quo.q++;
		if ((str[i] == '\'') && (quo.q % 2 == 0))
			quo.d_q++;
		i++;
	}
	return (i);
}
