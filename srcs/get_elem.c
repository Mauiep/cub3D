#include "../includes/cub3D.h"

//save l'elem F ou C dans une variable
void	get_in_struct_3(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'F')
	{
		while (line[i] == 'F' || line[i] == ' ')
			i++;
		data->f = convert_color(line + i);
	}
	i = 0;
	if (line[i] == 'C')
	{
		while (line[i] == 'C' || line[i] == ' ')
			i++;
		data->c = convert_color(line + i);
	}
}

//save l'elem WE ou EA dans une variable
void	get_in_struct_2(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'W')
	{
		while (line[i] == 'W' || line[i] == 'E' || line[i] == ' ')
			i++;
		data->we = ft_strdup(line + i);
	}
	i = 0;
	if (line[i] == 'E')
	{
		while (line[i] == 'E' || line[i] == 'A' || line[i] == ' ')
			i++;
		data->ea = ft_strdup(line + i);
	}
}

//save l'elem NO ou SO dans une variable
void	get_in_struct(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'N')
	{
		while (line[i] == 'N' || line[i] == 'O' || line[i] == ' ')
			i++;
		data->no = ft_strdup(line + i);
	}
	i = 0;
	if (line[i] == 'S')
	{
		while (line[i] == 'S' || line[i] == 'O' || line[i] == ' ')
			i++;
		data->so = ft_strdup(line + i);
	}
}

//verif l'id de l'elem
void	get_textures(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N')
		get_in_struct(data, line + i);
	if (line[i] == 'S')
		get_in_struct(data, line + i);
	if (line[i] == 'W')
		get_in_struct_2(data, line + i);
	if (line[i] == 'E')
		get_in_struct_2(data, line + i);
	if (line[i] == 'F')
		get_in_struct_3(data, line + i);
	if (line[i] == 'C')
		get_in_struct_3(data, line + i);
}

//check pr chaque ligne quel elem map c'est
void	get_elem_map(t_data *data, t_info *info, char **map)
{
	int	i;

	i = 0;
	while (i < info->index)
	{
		get_textures(data, map[i]);
		i++;
	}
}
