#include <stdlib.h>

static int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int		i_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int		is_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

long int		ft_atoi_base(char *str, char *base)
{
	long int	atoi;
	int			neg;

	atoi = 0;
	neg = 1;
	while (*str == '\t' || *str == '\v' || *str == '\r' || *str == '\n'
			|| *str == '\f' || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = neg * -1;
		str++;
	}
	while (is_base(*str, base))
	{
		atoi = atoi * ft_strlen(base) + i_base(*str, base);
		str++;
	}
	return (atoi * neg);
}