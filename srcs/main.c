/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admaupie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:36:15 by admaupie          #+#    #+#             */
/*   Updated: 2023/02/24 23:36:17 by admaupie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_strllen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_printmap(int		*minimap, t_data *data, int x, int y)
{
	int	a;
	int	b;
	
	a = x / 10 + (int)(data->pos_x + 0.5) - 10;
	b = y / 10 + (int)(data->pos_y + 0.5) - 10;
	if ((a < 0 || a >= ft_strllen(data->map))
			|| b < 0 || b >= (int)ft_strlen(data->map[0]))
		minimap[x * 200 + y] = 8405604;
	else if ((y >= 98 && y <= 102) && (x >= 98 && x <= 102))
		minimap[x * 200 + y] = data->color_c + 200;
	else if (data->map[a][b] == '1')
		minimap[x * 200 + y] = 8405604;
	else if (data->map[a][b] == '0' || data->map[a][b] == ' ')
		minimap[x * 200 + y] = 14722245;
}

void	*ft_minimap(t_data *data)
{
	void	*map;
	int		*minimap;
	int		i;
	int		x;
	int		y;

	map = mlx_new_image(data->mlx, 200, 200);
	minimap = (int *)mlx_get_data_addr(map, &i, &i, &i);
	if (!minimap)
		return (NULL);
	i = 0;
	while (i < 200 * 200 + 200)
		minimap[i++] = 0;
	i = 0;
	x = 0;
	while (x < 200)
	{
		y = -1;
		while (++y < 200)
			ft_printmap(minimap, data, x, y);
		x++;
	}
	return (map);
}

/*
	fonction dans boucle loop hook
*/

int	update(t_data *data)
{
	int		x;
	void	*map;

	x = 0;
	gameplay(data);
	ft_raycast(data, x);
	map = ft_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, map, 20, 20);
	mlx_destroy_image(data->mlx, map);
	return (0);
}

/*
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
	if (!map)
		return (0);
	int i = 0;
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		printf("\n");
		i++;
	}
	parsing_map(map, &info);
	if (init_all(&data, &info, map) < 0)
		return (-1);
	keyboard(&data);
	mlx_loop_hook(data.mlx, &update, &data);
	mlx_loop(data.mlx);
	return (0);
}
