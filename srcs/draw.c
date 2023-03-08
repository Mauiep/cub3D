/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admaupie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:35:14 by admaupie          #+#    #+#             */
/*   Updated: 2023/02/24 23:35:16 by admaupie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_sky_floor(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->raycast.draw_start)
	{
		data->addr[y * 1280 + x] = data->color_f;
		y++;
	}
	y = data->raycast.draw_end;
	while (y < 720)
	{
		data->addr[y * 1280 + x] = data->color_c;
		y++;
	}
	x++;
}

void	draw_map(t_data *data, int x)
{
	int	y;

	draw_sky_floor(data, x);
	y = data->raycast.draw_start;
	while (y < data->raycast.draw_end)
	{
		data->addr[y * 1280 + x] = data->buffer[y][x];
		y++;
	}
}

/*
	prepare la taille de la texture a afficher par rapport
	a sa distance avec le player
*/

void	draw_texture(t_data *data)
{
	if (data->raycast.side == 0)
	{
		if (data->raycast.raydir_x < 0)
			data->raycast.color = data->texture[0][64
				* data->raycast.tex_y + data->raycast.tex_x];
		else if (data->raycast.raydir_x > 0)
			data->raycast.color = data->texture[1][64
				* data->raycast.tex_y + data->raycast.tex_x];
	}
	if (data->raycast.side == 1)
	{
		if (data->raycast.raydir_y > 0)
			data->raycast.color = data->texture[2][64
				* data->raycast.tex_y + data->raycast.tex_x];
		else if (data->raycast.raydir_y < 0)
			data->raycast.color = data->texture[3][64
				* data->raycast.tex_y + data->raycast.tex_x];
	}
}
