#include "../includes/cub3D.h"

/*

	A terme pas besoin d'utiliser 'mlx_loop_hook', on appelera update une fois puis a chaque 
	utilisation d'une touche du clavier necessitant un nouvel affichage.

*/

int	update(t_data *data)
{
	usleep(100000);
	fprintf(stderr, "refreshed\n");
	mlx_destroy_image(data->mlx, data->img);
    data->img = mlx_new_image(data->mlx, 1280, 720);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
		&data->line_length, &data->end);
	gameplay(data);
	draw_background(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
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
	keyboard(&data);
	mlx_loop_hook(data.mlx, &update, &data);
	mlx_loop(data.mlx);
	return (0);
}
