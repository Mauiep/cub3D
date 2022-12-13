#include "../includes/cub3D.h"

void	check_textures(t_data *data, int index)
{
	if (index == 0)
	{
		if (!data->tex.no.img || !data->tex.so.img || !data->tex.we.img
			|| !data->tex.ea.img)
		{
			ft_putstr_fd("Error: elem textures\n", 1);
			free_data(data);
			exit(0);
		}
	}
	if (index == 1)
	{
		if (!data->tex.no.addr || !data->tex.no.addr || !data->tex.no.addr
			|| !data->tex.no.addr)
		{
			ft_putstr_fd("Error: elem textures\n", 1);
			free_data(data);
			exit(0);
		}
	}
}

void	init_textures(t_data *data)
{
	int	h;
	int	l;

	data->tex.no.img = mlx_xpm_file_to_image(data->mlx, data->no, &l, &h);
    data->tex.so.img = mlx_xpm_file_to_image(data->mlx, data->so, &l, &h);
    data->tex.we.img = mlx_xpm_file_to_image(data->mlx, data->we, &l, &h);
    data->tex.ea.img = mlx_xpm_file_to_image(data->mlx, data->ea, &l, &h);
	check_textures(data, 0);
	data->tex.no.addr = (unsigned int *)mlx_get_data_addr(data->tex.no.img,
		&data->tex.no.bpp, &data->tex.no.ll, &data->tex.no.end);
	data->tex.so.addr = (unsigned int *)mlx_get_data_addr(data->tex.so.img,
		&data->tex.so.bpp, &data->tex.so.ll, &data->tex.so.end);
	data->tex.we.addr = (unsigned int *)mlx_get_data_addr(data->tex.we.img,
		&data->tex.we.bpp, &data->tex.we.ll, &data->tex.we.end);
	data->tex.ea.addr = (unsigned int *)mlx_get_data_addr(data->tex.ea.img,
		&data->tex.ea.bpp, &data->tex.ea.ll, &data->tex.ea.end);
	check_textures(data, 1);
}

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
	// data->addr = mlx_get_data_addr(data->img, &data->bpp,
	// 	&data->ll, &data->end);
}