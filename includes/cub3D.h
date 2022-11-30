#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

//parsing
int	file_is_cub(char *av);
void	parsing_map(char **map);
int	check_carac(char **map);
int	check_start_2(char **map);
int	check_start(char **map);
int	check_floor_2(char **map);
int	check_floor(char **map);
int	check_double_start(char **map);

//creation map
char	**make_map(char **file);

//free
void    free_map(char **map);

#endif
