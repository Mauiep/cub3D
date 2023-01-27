#include "../includes/cub3D.h"

/*
	free le double tableau **map
*/
void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
}

void	free_texture(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		free(data->texture[i]);
		i++;
	}
	free(data->texture);
}

/*
	free tout le contenu de la structure data
*/

void	free_data(t_data *data)
{
	free_map(data->map);
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
}

void	free_all(t_data *data)
{
	free_data(data);
	free_texture(data);
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
