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
long int	ft_fill_tab(char *tab, long int num, char *base_to)
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
	i = ft_fill_tab(tab, num, base_to);
	ft_rev_tab(tab, i);
	tab[i] = '\0';
	free(nbr);
	return (tab);
}

//convert valeur color F et C en hexa pour data->
//CHECK FREE !!!!!!!!!!! --> CHECK FT_STRJOIN == FREE S1 // FREE S2
//LEAKS OK A PRIORI !!!
char	*convert_color(char *line)
{
	char	*str;
	char	*convert;
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(line, ',');
	str = malloc(sizeof(char) * 5);
	str[0] = '0';
	str[1] = 'x';
	str[2] = '0';
	str[3] = '0';
	str[4] = '\0';
	while (tmp[i])
	{
		convert = ft_convert_base(tmp[i], "0123456789ABCDEF");
		str = ft_strjoin(str, convert);
		free(convert);
		i++;
	}
	free(tmp);
	return (str);
}
