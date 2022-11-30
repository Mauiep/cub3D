/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:07:27 by rovillar          #+#    #+#             */
/*   Updated: 2021/12/09 18:00:59 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	nbr_len(unsigned int nb)
{
	if (nb < 10)
		return (1);
	return (1 + nbr_len(nb / 10));
}

static int	nbr_sign(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

static int	nbr_mal_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				size;

	nb = nbr_sign(n);
	size = nbr_len(nb) + nbr_mal_sign(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str = ft_memset(str, 0, size + 1);
	while (size > 0)
	{
		size--;
		str[size] = (nb % 10) + 48;
		nb = nb / 10;
		if (size == 0 && n < 0)
			str[size] = '-';
	}
	return (str);
}
