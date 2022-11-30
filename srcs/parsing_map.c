#include "../includes/cub3D.h"

//calcule le nombre de ligne de la map
int	nbr_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i - 1);
}

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
	while(map[i])
	{
		j = 0;
		while(map[i][j])
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

//check si un espace est bien colle a '1' pour map
//sauf pour le premier et dernier carac d'une ligne
int	check_space_wall(char **map)
{
	int	i;
	size_t	j;

	i = 0;
	while(map[i])
	{
		j = 1;
		while(j < ft_strlen(map[i]))
		{
			if ((map[i][j] == ' ' && (map[i][j - 1] != ' '
				&& map[i][j - 1] != '1')) || (map[i][j] == ' '
				&& (map[i][j + 1] != ' ' && map[i][j + 1] != '1')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//pour chaque ligne check si ca demarre et fini par '1' ou ' ' pour map
int	check_first_last(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' && map[i][0] != ' ')
			return (0);
		else if (map[i][ft_strlen(map[i] - 1)] != ' '
			&& map[i][ft_strlen(map[i] - 1)] != '1')
			return (0);
		i++;
	}
	return (1);
}

//check si premiere et derniere ligne n'ont que des '1' ou ' ' pour map
int	check_first_last_2(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = nbr_line(map);
	while (map[0][i])
	{
		if (map[0][i] != ' ' && map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[j][i])
	{
		if (map[j][i] != ' ' && map[j][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

//check si au dessus ou en dessous d'un espace se trouve un '1' ou ' ' pour map
//sauf pour derniere et premiere ligne
int	check_space_wall_2(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = nbr_line(map);
	while(i < k)
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == ' ' && (map[i - 1][j] != ' '
				&& map[i - 1][j] != '1'))
				return (0);
			else if (map[i][j] == ' ' && (map[i + 1][j] != ' '
				&& map[i + 1][j] != '1'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//check pr premiere ligne si un ' ' et colle a '1' ou ' ' en dessous
//pareil pr derniere ligne au dessus
int	check_space_wall_3(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = nbr_line(map);
	(void)j;
	while (map[0][i])
	{
		if (map[0][i] == ' ' && (map[1][i] != ' ' && map[1][i] != '1'))
			return (0);
		i++;
	}
	while (map[j][i])
	{
		if (map[j][i] == ' ' && (map[j - 1][i] != ' ' && map[j - 1][i] != '1'))
			return (0);
		i++;
	}
	return (1);
}

//parsing complet de la map
void	parsing_map(char **map)
{
	if (!check_carac(map))
	{
		free_map(map);
		printf("Error map carac\n");
		exit(0);
	}
	else if (!check_first_last(map))
	{
		free_map(map);
		printf("Error map check first/last\n");
		exit(0);
	}
	else if (!check_first_last_2(map))
	{
		free_map(map);
		printf("Error map check first/last 2\n");
		exit(0);
	}
	else if (!check_space_wall(map))
	{
		free_map(map);
		printf("Error map space wall\n");
		exit(0);
	}
	else if (!check_space_wall_2(map))
	{
		free_map(map);
		printf("Error map space wall 2\n");
		exit(0);
	}
	else if (!check_space_wall_3(map))
	{
		free_map(map);
		printf("Error map space wall 3\n");
		exit(0);
	}
}