/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admaupie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:36:29 by admaupie          #+#    #+#             */
/*   Updated: 2023/02/24 23:36:29 by admaupie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
    Fonction raycast
*/

void	ft_raycast(t_data *data, int x)
{
	while (x < 1280)
	{
		init_raycast(data, x);
		data->raycast.hit = 0;
		init_step(data);
		perform_dda(data);
		draw_start_end(data);
		if (data->raycast.side == 0)
		{
			data->raycast.wall_x = data->pos_y + data->raycast.perp_wall_dist
				* data->raycast.raydir_y;
		}
		else
		{
			data->raycast.wall_x = data->pos_x + data->raycast.perp_wall_dist
				* data->raycast.raydir_x;
		}
		data->raycast.wall_x -= floor(data->raycast.wall_x);
		data->raycast.tex_x = (int)(data->raycast.wall_x * (double)64);
		add_texture(data, x, data->raycast.draw_start);
		draw_map(data, x);
		x++;
	}
}

/*
    Init la direction du player
*/

void	init_step(t_data *data)
{
	if (data->raycast.raydir_x < 0)
	{
		data->raycast.step_x = -1;
		data->raycast.side_dist_x = (data->pos_x - data->raycast.map_x)
			* data->raycast.delta_dist_x;
	}
	else
	{
		data->raycast.step_x = 1;
		data->raycast.side_dist_x = (data->raycast.map_x + 1.0 - data->pos_x)
			* data->raycast.delta_dist_x;
	}
	if (data->raycast.raydir_y < 0)
	{
		data->raycast.step_y = -1;
		data->raycast.side_dist_y = (data->pos_y - data->raycast.map_y)
			* data->raycast.delta_dist_y;
	}
	else
	{
		data->raycast.step_y = 1;
		data->raycast.side_dist_y = (data->raycast.map_y + 1.0 - data->pos_y)
			* data->raycast.delta_dist_y;
	}
}

/*
    DDA fonction
    La méthode DDA (Digital Differential Analyzer) me permet de savoir
    où mon rayon touche le prochain wall.
*/

void	perform_dda(t_data *data)
{
	while (data->raycast.hit == 0)
	{
		if (data->raycast.side_dist_x < data->raycast.side_dist_y)
		{
			data->raycast.side_dist_x += data->raycast.delta_dist_x;
			data->raycast.map_x += data->raycast.step_x;
			data->raycast.side = 0;
		}
		else
		{
			data->raycast.side_dist_y += data->raycast.delta_dist_y;
			data->raycast.map_y += data->raycast.step_y;
			data->raycast.side = 1;
		}
		if (data->map[data->raycast.map_x][data->raycast.map_y] > '0')
			data->raycast.hit = 1;
	}
}

/*
    Calculer la distance du rayon perpendiculaire
    (la distance euclidienne donnerait un effet de fish-eye!)
*/

void	draw_start_end(t_data *data)
{
	if (data->raycast.side == 0)
	{
		data->raycast.perp_wall_dist = (data->raycast.map_x - data->pos_x
				+ (1 - data->raycast.step_x) / 2) / data->raycast.raydir_x;
	}
	else
	{
		data->raycast.perp_wall_dist = (data->raycast.map_y - data->pos_y
				+ (1 - data->raycast.step_y) / 2) / data->raycast.raydir_y;
	}
	data->raycast.line_height = (int)(720 / data->raycast.perp_wall_dist);
	data->raycast.draw_start = -data->raycast.line_height / 2 + 720 / 2;
	if (data->raycast.draw_start < 0)
		data->raycast.draw_start = 0;
	data->raycast.draw_end = data->raycast.line_height / 2 + 720 / 2;
	if (data->raycast.draw_end >= 720)
		data->raycast.draw_end = 720 - 1;
}

/*
    Fonction qui va add les textures au fur et a mesure
*/

void	add_texture(t_data *data, int x, int y)
{
	data->raycast.step = 1.0 * 64 / data->raycast.line_height;
	data->raycast.tex_pos = (data->raycast.draw_start - 720 / 2
			+ data->raycast.line_height / 2) * data->raycast.step;
	if (data->raycast.side == 0 && data->raycast.raydir_x > 0)
		data->raycast.tex_x = 64 - data->raycast.tex_x - 1;
	if (data->raycast.side == 1 && data->raycast.raydir_y < 0)
		data->raycast.tex_x = 64 - data->raycast.tex_x - 1;
	while (y < data->raycast.draw_end)
	{
		data->raycast.tex_y = (int)(data->raycast.tex_pos) & (64 - 1);
		data->raycast.tex_pos += data->raycast.step;
		draw_texture(data);
		data->buffer[y][x] = data->raycast.color;
		y++;
	}
}
