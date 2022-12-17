#include "../includes/cub3D.h"

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

void	free_data(t_data *data)
{
	free_map(data->map);
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	free(data->f);
	free(data->c);
}

void	ft_error_2(t_data *data, int index)
{
	if (index == 1)
		ft_putstr_fd("Error: same textures\n", 1);
	else if (index == 2)
		ft_putstr_fd("Error: elem textures\n", 1);
	free_data(data);
	exit(0);
}

void	ft_error(int id, char **map)
{
	if (id == 0)
		ft_putstr_fd("Error: elem map\n", 1);
	else if (id == 1)
		ft_putstr_fd("Error: map\n", 1);
	free_map(map);
	exit(0);
}