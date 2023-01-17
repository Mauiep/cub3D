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
# include <math.h>

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
        int                             bits_per_pixel;
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
	char		**map;// tableau representant notre map, remplies de 0, 1 et P
	void		*mlx;// pointeur mlx
	void		*win;// pointeur sur notre fenetre cub3d
	void		*img;//	pointeur sur l'image qu'on affiche a l'ecran
	char		*addr;// addr est recuperee avec get_addr
	int			bits_per_pixel;// bits_per_pixel est recuperee avec get_addr
	int			line_length;// line_length est recuperee avec get_addr
	int			end;
	char		*no;// path MUR NORD
	char		*so;// path MUR SUD
	char		*we;// path MUR OUEST
	char		*ea;// path MUR EST
	long int	color_f;// couleur du sol
	long int	color_c;// couleur du ciel
	float			pos_x;// position x du personnage
	float			pos_y;// position y du personnage
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
	float			speedrot;
	float			speedmove;
	int			move;// touche direcionnel "AVANCER"
	char		direction;// /!\ plus necessaire
	int			dir_right;// touche de direction droite appuyee
	int			dir_left;// touche de direction gauche appuyee
	t_textures	tex;
}		t_data;

//parsing
int			file_is_cub(char *av);
void		parsing_map(char **map, t_info *info);
int			check_carac(char **map);
int			check_start_2(char **map);
int			check_start(char **map);
int			check_floor(char **map);
int			check_floor_2(char **map);
int			check_double_start(char **map);
int			check_elem_map(char **map, t_info *info);
int			check_color_elem(char **map, int index);
int			check_elem_line(char *line, t_info *info);
int			nbr_elem(t_info *info);
int			index_map(char **map);

//init data
int			init_data(t_data *data, t_info *info, char **map);
void		init_textures(t_data *data);
int			get_elem_map(t_data *data, t_info *info, char **map);
long int	convert_color(char *line);

//creation map
char		**make_map(char **file);
void		get_map(t_data *data, t_info *info, char **map);

//gameplay
void    	keyboard(t_data *data);
void    	gameplay(t_data *data);
void    	my_position(t_data *data);
//draw	
void		ft_pixel_put(t_data *data, int x, int y, int color);
void		draw_background(t_data *data);

//free
void		ft_error(int id, char **map);
void		ft_error_2(t_data *data, int index);
void		free_map(char **map);
void		free_data(t_data *data);

//utils
int			count_line_map(char **map);
int			ft_strcmp(char *s1, char *s2);

#endif
