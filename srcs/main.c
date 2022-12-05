#include "../includes/cub3D.h"

//need free map

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
	init_data(&data, &info, map);
	// mlx_loop(data.mlx);


	int	i;
	i = 0;
	while (data.map[i])
	{
		printf("%s\n", data.map[i]);
		i++;
	}
	free_data(&data);
	return (0);
}
