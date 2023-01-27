#include "../includes/cub3D.h"

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
