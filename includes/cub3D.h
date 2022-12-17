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

typedef struct s_info
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
	int	index;
}		t_info;

typedef struct s_img
{
        void                    *img;
        unsigned int    *addr;
        int                             ll;
        int                             bpp;
        int                             end;
}               t_img;

typedef struct s_textures
{
	t_img   no;
    t_img   so;
    t_img   we;
    t_img   ea;
}               t_textures;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	t_textures      tex;
}		t_data;

//parsing
int		file_is_cub(char *av);
void	parsing_map(char **map, t_info *info);
int		check_carac(char **map);
int		check_start_2(char **map);
int		check_start(char **map);
int		check_floor(char **map);
int		check_floor_2(char **map);
int		check_double_start(char **map);
int		check_elem_map(char **map, t_info *info);
int		check_color_elem(char **map, int index);
int		check_elem_line(char *line, t_info *info);
int		nbr_elem(t_info *info);
int		index_map(char **map);

//init data
void	init_data(t_data *data, t_info *info, char **map);
void	init_textures(t_data *data);
void	get_elem_map(t_data *data, t_info *info, char **map);
char	*convert_color(char *line);

//creation map
char	**make_map(char **file);
void	get_map(t_data *data, t_info *info, char **map);

//free
void	ft_error(int id, char **map);
void	ft_error_2(t_data *data, int index);
void	free_map(char **map);
void	free_data(t_data *data);

//utils
int		count_line_map(char **map);
int		ft_strcmp(char *s1, char *s2);

#endif
