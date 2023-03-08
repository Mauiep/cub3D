/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admaupie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:37:48 by admaupie          #+#    #+#             */
/*   Updated: 2023/02/24 23:37:49 by admaupie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_file(t_data *data)
{
	int		fd;

	fd = open(data->so, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open(data->no, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open(data->ea, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open(data->we, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}
