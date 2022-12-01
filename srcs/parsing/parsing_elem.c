#include "../../includes/cub3D.h"

//verifie si le nombre d'element est OK
int	nbr_elem(t_info *info)
{
	if (info->no != 1 || info->so != 1 || info->we != 1
		|| info->ea != 1 || info->f != 1 || info->c != 1)
		return (0);
	return (1);
}

//ajoute +1 chaque fois qu'il croise un element correct
int	id_elem(char *line, t_info *info)
{
	if (line[0] == 'N')
		info->no += 1;
	else if (line[0] == 'S')
		info->so += 1;
	else if (line[0] == 'W')
		info->we += 1;
	else if (line[0] == 'E')
		info->ea += 1;
	else if (line[0] == 'F')
		info->f += 1;
	else if (line[0] == 'C')
		info->c += 1;
	return (1);
}

//check la ligne et regarde quel element c'est
int	check_elem_line(char *line, t_info *info)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if ((line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		|| (line[i] == 'S' && line[i + 1] == 'O' && line [i + 2] == ' ')
		|| (line[i] == 'W' && line[i + 1] == 'E' && line [i + 2] == ' ')
		|| (line[i] == 'E' && line[i + 1] == 'A' && line [i + 2] == ' ')
		|| (line[i] == 'F' && line[i + 1] == ' ')
		|| (line[i] == 'C' && line[i + 1] == ' '))
		return (id_elem(line + i, info));
	else
		return (0);
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
	info->index = i;
	return (1);
}
