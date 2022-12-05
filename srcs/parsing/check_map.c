#include "../../includes/cub3D.h"

//check si ya seulement 1 start sur la map
int	check_double_start(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

//check si au dessus ou en dessous d'un '0' se trouve ' ' ou 0
int	check_floor_2(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && (map[i - 1][j] == ' '
				|| map[i - 1][j] == 0))
				return (0);
			if (map[i][j] == '0' && (map[i + 1][j] == ' '
				|| map[i + 1][j] == 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//check si a droite ou a gauche d'un '0' se trouve ' ' ou 0
int	check_floor(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && (map[i][j - 1] == ' '
				|| map[i][j - 1] == 0))
				return (0);
			if (map[i][j] == '0' && (map[i][j + 1] == ' '
				|| map[i][j + 1] == 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//check si a droite ou a gauche du start se trouve ' ' ou 0
int	check_start(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W') && (map[i][j + 1] == ' '
				|| map[i][j + 1] == 0))
				return (0);
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W') && (map[i][j - 1] == ' '
				|| map[i][j - 1] == 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//check si en dessous ou au desss d'un '0' se trouve ' ' ou 0
int	check_start_2(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W') && (map[i - 1][j] == ' '
				|| map[i - 1][j] == 0))
				return (0);
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W') && (map[i + 1][j] == ' '
				|| map[i + 1][j] == 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
