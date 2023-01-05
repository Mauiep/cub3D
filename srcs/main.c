#include "../includes/cub3D.h"

int	update(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
    data->img = mlx_new_image(data->mlx, 1920, 1080);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->end);
	keyboard(data);
	gameplay(data);
	//draw_map();
	return (0);
}

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
	init_textures(&data);
	mlx_loop_hook(data.mlx, update, &data);
	// int	i;
	// i = 0;
	// while (data.map[i])
	// {
	// 	printf("%s\n", data.map[i]);
	// 	i++;
	// }
	// free_data(&data);
	return (0);
}
