/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:48:04 by rovillar          #+#    #+#             */
/*   Updated: 2021/12/10 17:17:10 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	const char	*start;
	char		*end;

	i = 0;
	start = src;
	end = dest;
	if (!src && !dest)
		return (0);
	while (n != 0)
	{
		end[i] = start[i];
		i++;
		n--;
	}
	return (dest);
}
