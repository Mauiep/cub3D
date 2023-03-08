/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admaupie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:35:59 by admaupie          #+#    #+#             */
/*   Updated: 2023/02/24 23:36:00 by admaupie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
	<!>
	j'ai passe toutes ces fonctions de void en int pour pouvoir communiquer
	les erreurs de malloc
	<!>



	Recupere les valeurs de couleurs du fichier dans la structure.
	color_f pour F qui correspond au sol.
	color_c pour C qui correspond au ciel.
*/
static int	get_color(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'F')
	{
		while (line[i] == 'F' || line[i] == ' ')
			i++;
		data->color_f = convert_color(line + i);
		if (data->color_f == -1)
			return (-1);
	}
	i = 0;
	if (line[i] == 'C')
	{
		while (line[i] == 'C' || line[i] == ' ')
			i++;
		data->color_c = convert_color(line + i);
		if (data->color_c == -1)
			return (-1);
	}
	return (1);
}

/*
	Recupere le path du mur Ouest "WE" et Est "EA"
*/
static int	get_east_west(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'W')
	{
		while (line[i] == 'W' || line[i] == 'E' || line[i] == ' ')
			i++;
		data->we = ft_strdup(line + i);
		if (!data->we)
			return (-1);
	}
	i = 0;
	if (line[i] == 'E')
	{
		while (line[i] == 'E' || line[i] == 'A' || line[i] == ' ')
			i++;
		data->ea = ft_strdup(line + i);
		if (!data->ea)
			return (-1);
	}
	return (1);
}

/*
	Recupere le path du mur Nord "NO" et Sud "SO"
*/

static int	get_north_south(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'N')
	{
		while (line[i] == 'N' || line[i] == 'O' || line[i] == ' ')
			i++;
		data->no = ft_strdup(line + i);
		if (!data->no)
			return (-1);
	}
	i = 0;
	if (line[i] == 'S')
	{
		while (line[i] == 'S' || line[i] == 'O' || line[i] == ' ')
			i++;
		data->so = ft_strdup(line + i);
		if (!data->so)
			return (-1);
	}
	return (1);
}

/*
	get_textures va verifier si la ligne contient :
	NO : pour les murs nord
	SO : pour les murs sud
	EA : pour les murs est
	WE : pour les murs ouest
	F : pour la couleur du sol
	C : pour la couleur du ciel
	Lance la fonction correspondante pour mettre la valeur dans la structure.
	
	QUESTION ?? Est ce qu'on a/doit verifier si plusieurs valeurs NO existent.
*/

static int	get_textures(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N' || line[i] == 'S')
	{
		if (get_north_south(data, line + i) == -1)
			return (-1);
	}
	else if (line[i] == 'W' || line[i] == 'E')
	{
		if (get_east_west(data, line + i) == -1)
			return (-1);
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		if (get_color(data, line + i) == -1)
			return (-1);
	}
	return (1);
}

/*
	get_elem_map va envoyer les lignes du fichier une par une a get_textures
*/
int	get_elem_map(t_data *data, t_info *info, char **map)
{
	int	i;

	i = 0;
	while (i < info->index)
	{
		if (get_textures(data, map[i]) == -1)
			return (free_map(map), -1);
		i++;
	}
	if (check_file(data) == -1)
		return (-1);
	return (1);
}
