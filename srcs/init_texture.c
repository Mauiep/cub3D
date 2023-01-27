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

void	load_image(t_data *data, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->img_width,
			&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->ll, &img->end);
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
}

void	load_texture(t_data *data)
{
	t_img	img;

	load_image(data, data->texture[0], data->no, &img);
	load_image(data, data->texture[1], data->so, &img);
	load_image(data, data->texture[2], data->ea, &img);
	load_image(data, data->texture[3], data->we, &img);
}
