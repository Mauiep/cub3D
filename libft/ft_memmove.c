/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:50:05 by rovillar          #+#    #+#             */
/*   Updated: 2021/12/10 17:11:14 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*start;
	char		*end;

	start = (char *)src;
	end = (char *)dest;
	if (!src && !dest)
		return (NULL);
	if (end > start)
	{
		while (n-- > 0)
			end[n] = start[n];
	}
	else
	{
		while (n != 0)
		{
			*end++ = *start++;
			n--;
		}
	}
	return (dest);
}
