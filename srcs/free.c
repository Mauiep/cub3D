#include "../includes/cub3D.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
}
