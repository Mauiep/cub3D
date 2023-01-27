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
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

/*
	free et quitte le programme pour cause d'erreur de textures
	ou pour cause de fail init

	/!\ A VERIFIER /!\
	FT_ERROR_2 CALL DANS INIT_ALL
*/
void	ft_error_2(t_data *data, int index)
{
	if (index == 1)
		ft_putstr_fd("Error: same textures\n", 1);
	else if (index == 2)
		ft_putstr_fd("Error: elem textures\n", 1);
	else if (index == 3)
		ft_putstr_fd("Error init_all\n", 1);
	else if (index == 4)
	{
		ft_putstr_fd("Error: malloc texture/buffer\n", 1);
		free(data->mlx);
	}
	free_data(data);
	exit(0);
}

/*
	free et quitte le programme pour cause d'erreur de parsing de la map
*/
void	ft_error(int id, char **map)
{
	if (id == 0)
		ft_putstr_fd("Error: elem map\n", 1);
	else if (id == 1)
		ft_putstr_fd("Error: map\n", 1);
	free_map(map);
	exit(0);
}