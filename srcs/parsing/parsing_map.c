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

//parsing complet de la map
void	parsing_map(char **map)
{
	if (!check_carac(map) || !check_double_start(map) || !check_floor(map)
		|| !check_floor_2(map) || !check_start(map) || !check_start_2(map))
	{
		free_map(map);
		printf("Error map\n");
		exit(0);
	}
}
