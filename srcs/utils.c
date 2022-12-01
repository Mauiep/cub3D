#include "../includes/cub3D.h"

//compte le nombre de ligne de la map
int	count_line_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
