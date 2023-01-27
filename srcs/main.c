#include "../includes/cub3D.h"

/*
	fonction dans boucle loop hook
*/

int	update(t_data *data)
{
	int	x;

	x = 0;
	gameplay(data);
	ft_raycast(data, x);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

/*
	/!\ 2 LEAKS STILL REACHABLE /!\

	+

	VERIFIER SI FREE CORRECT DANS (((FT_ERROR.C -> FT_ERROR_2)))
*/

int	main(int ac, char **av)
{
	t_data	data;
	t_info	info;
	char	**map;

	if (ac != 2 || !file_is_cub(av[1]))
	{
		printf("Error arg\n");
		return (0);
	}
	map = make_map(&av[1]);
	parsing_map(map, &info);
	init_all(&data, &info, map);
	keyboard(&data);
	mlx_loop_hook(data.mlx, &update, &data);
	mlx_loop(data.mlx);
	return (0);
}
