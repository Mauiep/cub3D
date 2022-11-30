#include "../includes/cub3D.h"

//traitement fd -> char *
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

//traitement fd -> char * -> char **
char	**make_map(char **file)
{
	char	*str;
	char	**map;

	str = convert_map(file);
	map = ft_split(str, '\n');
	free(str);
	return (map);
}
