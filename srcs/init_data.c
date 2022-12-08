#include "../includes/cub3D.h"

//init les donnees
//data->map == map
//data->so == l'elem NO
//etc...
void	init_data(t_data *data, t_info *info, char **map)
{
	get_elem_map(data, info, map);
	get_map(data, info, map);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "cub3D");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->end);
}