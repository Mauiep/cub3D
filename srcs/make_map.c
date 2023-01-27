#include "../includes/cub3D.h"

/*
	Cette fonction decoupe le contenu du tableau map pour
	ne mettre que la map sans les autres elements dans la structure
*/

void	get_map(t_data *data, t_info *info, char **map)
{
	int	i;
	int	j;

	j = 0;
	i = info->index;
	data->map = NULL;
	data->map = malloc(sizeof(char *) * count_line_map(map));
	while (map[i])
	{
		data->map[j] = ft_strdup(map[i]);
		i++;
		j++;
	}
	data->map[j] = NULL;
	free_map(map);
}

static char	*convert_map(char **file)
{
	int		fd;
	char	*str;
	char	*line;

	fd = open(*file, O_RDONLY);
	str = ft_strdup("");
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		str = ft_strjoin(str, line);
		if (!str)
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	return (str);
}

char	**make_map(char **file)
{
	char	*str;
	char	**map;

	str = convert_map(file);
	map = ft_split(str, '\n');
	free(str);
	return (map);
}
