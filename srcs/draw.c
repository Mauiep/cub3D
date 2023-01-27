#include "../includes/cub3D.h"

void	draw_sky_floor(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->raycast.drawStart)
	{
		data->addr[y * 1280 + x] = data->color_f;
		y++;
	}
	y = data->raycast.drawEnd;
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
	y = data->raycast.drawStart;
	while (y < data->raycast.drawEnd)
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
		if (data->raycast.raydirX < 0)
			data->raycast.color = data->texture[0][64
				* data->raycast.texY + data->raycast.texX];
		else if (data->raycast.raydirX > 0)
			data->raycast.color = data->texture[1][64
				* data->raycast.texY + data->raycast.texX];
	}
	if (data->raycast.side == 1)
	{
		if (data->raycast.raydirY > 0)
			data->raycast.color = data->texture[2][64
				* data->raycast.texY + data->raycast.texX];
		else if (data->raycast.raydirY < 0)
			data->raycast.color = data->texture[3][64
				* data->raycast.texY + data->raycast.texX];
	}
}
