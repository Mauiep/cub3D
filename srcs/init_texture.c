/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admaupie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:35:39 by admaupie          #+#    #+#             */
/*   Updated: 2023/02/24 23:35:40 by admaupie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
	Init texture + buffer qui servent pr affichage
*/

int	init_texture(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 8)
	{
		data->texture[i] = (int *)malloc(sizeof(int) * (64 * 64));
		if (!data->texture[i])
			return (-1);
	}
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 64 * 64)
			data->buffer[i][j] = 0;
	}
	return (1);
}

int	init_buffer(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 720)
	{
		j = -1;
		while (j++ < 1280)
			data->buffer[i][j] = 0;
	}
	data->texture = (int **)malloc(sizeof(int *) * 64);
	if (!data->texture)
		return (-1);
	return (1);
}

int	load_image(t_data *data, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->img_width,
			&img->img_height);
	if (!img->img || img->img_height != 64 || img->img_width != 64)
		return (-1);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->ll, &img->end);
	if (!img->data)
		return (-1);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img->img);
	return (0);
}

int	load_texture(t_data *data)
{
	t_img	img;

	if (load_image(data, data->texture[0], data->no, &img) < 0)
		return (-1);
	if (load_image(data, data->texture[1], data->so, &img) < 0)
		return (-1);
	if (load_image(data, data->texture[2], data->ea, &img) < 0)
		return (-1);
	if (load_image(data, data->texture[3], data->we, &img) < 0)
		return (-1);
	return (0);
}
