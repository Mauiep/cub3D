#include "../../includes/cub3D.h"

int	check_file(t_data *data)
{
	int		fd;

	fd = open(data->so, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open(data->no, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open(data->ea, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open(data->we, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}