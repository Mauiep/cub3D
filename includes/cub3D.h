#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct  s_info
{
        int     no;
        int     so;
        int     we;
        int     ea;
        int     f;
        int     c;
        int     index;
}               t_info;

typedef struct  s_data
{
        char    **map;
        void    *mlx;
        void    *win;
        void    *img;
        char    *addr;
        int     bpp;
        int     ll;
        int     end;
        char    *NO;
        char    *SO;
        char    *WE;
        char    *EA;
        char    *F;
        char    *C;
}               t_data;


//parsing
int	file_is_cub(char *av);
void	parsing_map(char **map, t_info *info);
int	check_carac(char **map);
int	check_start_2(char **map);
int	check_start(char **map);
int	check_floor_2(char **map);
int	check_floor(char **map);
int	check_double_start(char **map);
int check_elem_map(char **map, t_info *info);
int index_map(char **map);

//init data
void    init_data(t_data *data, t_info *info, char **map);

//creation map
char	**make_map(char **file);
void    get_map(t_data *data, t_info *info, char **map);

//free
void	free_map(char **map);

//utils
int     count_line_map(char **map);

#endif
