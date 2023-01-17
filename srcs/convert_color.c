#include "../includes/cub3D.h"

//invers tab
void	ft_rev_tab(char *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while (i < size / 2)
	{
		swap = tab[size - 1 - i];
		tab[size - i - 1] = tab[i];
		tab[i] = swap;
		i++;
	}
}

//rempli le tab en hexa
long int	ft_filine_length_tab(char *tab, long int num, char *base_to)
{
	int			neg;
	int			base_len;
	long int	i;

	base_len = ft_strlen(base_to);
	neg = 0;
	i = 0;
	if (num < 0)
	{
		neg = 1;
		num = -num;
	}
	if (num == 0)
		tab[i++] = base_to[num % base_len];
	while (num)
	{
		tab[i++] = base_to[num % base_len];
		num = num / base_len;
	}
	if (neg)
		tab[i++] = '-';
	return (i);
}

//convert la value color C ou F de decimal a hexa
char	*ft_convert_base(char *nbr, char *base_to)
{
	long int	num;
	int			i;
	char		*tab;

	i = 0;
	tab = malloc(sizeof(char) * 34);
	if (!tab)
		return (NULL);
	num = ft_atoi(nbr);
	i = ft_filine_length_tab(tab, num, base_to);
	ft_rev_tab(tab, i);
	tab[i] = '\0';
	free(nbr);
	return (tab);
}
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
