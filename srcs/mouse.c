/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admaupie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:36:29 by admaupie          #+#    #+#             */
/*   Updated: 2023/02/24 23:36:29 by admaupie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static
void	mouse_rotation(t_data *data, int axis, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	if (axis)
		rot = -rot;
	data->dir_x = data->dir_x * cos(rot) - data->dir_y * sin(rot);
	data->dir_y = old_dir_x * sin(rot) + data->dir_y * cos(rot);
	data->plane_x = data->plane_x * cos(rot) - data->plane_y * sin(rot);
	data->plane_y = old_plane_x * sin(rot) + data->plane_y * cos(rot);
}

int	mouse_move(t_data *data)
{
	int	x;
	int	y;
	int	ret;

	ret = 0;
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	if (y >= MHEIGHT)
		mlx_mouse_move(data->mlx, data->win, MWIDTH_2, MHEIGHT);
	if (x > MWIDTH_2 - 5 || x < MWIDTH_2 + 5)
	{
		if (x >= MWIDTH_2)
			mouse_rotation(data, (ret == 0), (x - MWIDTH_2) * 0.005);
		else
			mouse_rotation(data, (ret != 0), (MWIDTH_2 - x) * 0.005);
	}
	if (y > MHEIGHT_2 - 5 || y < MHEIGHT_2 + 5)
	{
		if (y >= MHEIGHT_2)
			data->raycast.n_draws = (y - MHEIGHT_2) * -1;
		else
			data->raycast.n_draws = (MHEIGHT_2 - y) * 1;
	}
	mlx_mouse_move(data->mlx, data->win, MWIDTH_2, y);
	return (0);
}
