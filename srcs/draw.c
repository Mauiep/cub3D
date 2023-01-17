#include "../includes/cub3D.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < 720)
	{
		x = 0;
		while (y < 720 / 2 && x < 1280)
		{// afficher le ciel
			ft_pixel_put(data, x, y, data->color_c);
			x++;
		}
		while (y < 720 && y >= 720 / 2 && x < 1280)
		{// afficher le sol
			ft_pixel_put(data, x, y, data->color_f);
			x++;
		}
		y++;
	}
}