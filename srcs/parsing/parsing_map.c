/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admaupie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:37:44 by admaupie          #+#    #+#             */
/*   Updated: 2023/02/24 23:37:45 by admaupie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//verif si file == .cub + verif != dossier
int	file_is_cub(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".cub", len) != 0)
		return (0);
	return (1);
}

//check les carac valable dans la map
int	check_carac(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//check ligne par ligne si c'est un element de la map
int	check_elem_map(char **map, t_info *info)
{
	int	i;

	i = 0;
	while (map[i] && (info->c < 1 || info->f < 1 || info->ea < 1
			|| info->no < 1 || info->so < 1 || info->we < 1))
	{
		if (!check_elem_line(map[i], info))
			return (0);
		i++;
	}
	if (!nbr_elem(info))
		return (0);
	if (!check_color_elem(map, i))
		return (0);
	info->index = i;
	return (1);
}

//init les info a 0
void	init_info(t_info *info)
{
	info->no = 0;
	info->so = 0;
	info->we = 0;
	info->ea = 0;
	info->f = 0;
	info->c = 0;
	info->index = 0;
}

//parsing des elements de la map + parsing map
void	parsing_map(char **map, t_info *info)
{
	int		i;

	init_info(info);
	if (!check_elem_map(map, info))
		ft_error(0, map);
	i = info->index;
	if (!check_carac(map + i) || !check_double_start(map + i)
		|| !check_start(map + i) || !check_start_2(map + i)
		|| !check_floor(map + i) || !check_floor_2(map + i))
		ft_error(1, map);
}
