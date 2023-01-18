#include "../includes/cub3D.h"

/*
	convert_color recupere la ligne du fichier contenant les valeurs R, G et B,
	et nous renvoie la valeur de la couleur en long int grace a la formule :
	R * 65536 + G * 256 + B

	return (-1) =  probleme de malloc

*/
long int	convert_color(char *line)
{
	long int	result;
	char		**tmp;

	result = 0;
	tmp = ft_split(line, ',');
	if (!tmp)
		return (-1);
	result = ft_atoi(tmp[0]) * 65536 + ft_atoi(tmp[1]) * 256 + ft_atoi(tmp[2]);
	return (free(tmp[2]), free(tmp[1]), free(tmp[0]), free(tmp), result);
}
