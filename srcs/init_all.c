/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admaupie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:35:34 by admaupie          #+#    #+#             */
/*   Updated: 2023/02/24 23:35:35 by admaupie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
	init les donnees
	data->map == map
	data->so == l'elem NO
	etc...
*/

void	init_raycast(t_data *data, int x)
{
	data->raycast.camera_x = 2 * x / (double)1280 - 1;
	data->raycast.raydir_x = data->dir_x + data->plane_x
		* data->raycast.camera_x;
	data->raycast.raydir_y = data->dir_y + data->plane_y
		* data->raycast.camera_x;
	data->raycast.map_x = (int)data->pos_x;
	data->raycast.map_y = (int)data->pos_y;
	data->raycast.delta_dist_x = fabs(1 / data->raycast.raydir_x);
	data->raycast.delta_dist_y = fabs(1 / data->raycast.raydir_y);
}

void	init_struct(t_data *data)
{
	data->speedrot = 0.05;
	data->speedmove = 0.05;
	data->move_forward = 0;
	data->move_back = 0;
	data->move_right = 0;
	data->move_left = 0;
	data->rot_left = 0;
	data->rot_right = 0;
}

int	init_data(t_data *data, t_info *info, char **map)
{
	if (get_elem_map(data, info, map) == -1)
		return (-1);
	get_map(data, info, map);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (-2);
	data->win = mlx_new_window(data->mlx, 1280, 720, "cub3D");
	data->img = mlx_new_image(data->mlx, 1280, 720);
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->end);
	return (1);
}

int	init_all(t_data *data, t_info *info, char **map)
{
	data->map = NULL;
	data->texture = NULL;
	if (init_data(data, info, map) < 0)
		ft_error_2(data, 3);
	init_struct(data);
	init_position(data);
	if (init_buffer(data) < 0 || init_texture(data) < 0)
		ft_error_2(data, 4);
	if (load_texture(data) < 0)
		return (free_all(data), -1);
	return (1);
}
