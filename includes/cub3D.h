/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admaupie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:58:41 by admaupie          #+#    #+#             */
/*   Updated: 2023/03/14 19:58:42 by admaupie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MHEIGHT   720
# define MHEIGHT_2 360
# define MWIDTH_2 640
# define MWIDTH 1280

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
	void		*img;
	int			*addr;
	int			ll;
	int			bits_per_pixel;
	int			end;
	int			img_width;
	int			img_height;
	int			*data;
}		t_img;

typedef struct s_textures
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
}		t_textures;

typedef struct s_raycast
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	int		color;

	int		n_draws;
	int		n_drawe;

}				t_raycast;

typedef struct s_data
{
	char		**map;
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			end;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	long int	color_f;
	long int	color_c;
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		speedrot;
	float		speedmove;
	int			move_forward;
	int			move_back;
	int			move_right;
	int			move_left;
	int			rot_right;
	int			rot_left;
	int			**texture;
	int			buffer[1280][720];
	t_textures	tex;
	t_raycast	raycast;
}		t_data;

/*
	Parsing
*/

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
int			check_file(t_data *data);

/*
	Init
*/

int			init_all(t_data *data, t_info *info, char **map);
int			init_data(t_data *data, t_info *info, char **map);
int			init_texture(t_data *data);
int			init_buffer(t_data *data);
int			load_texture(t_data *data);
int			get_elem_map(t_data *data, t_info *info, char **map);
long int	convert_color(char *line);

/*
	Creation map
*/

char		**make_map(char **file);
int			get_map(t_data *data, t_info *info, char **map);

/*
	Gameplay
*/

void		move_player(t_data *data);
void		keyboard(t_data *data);
void		init_position(t_data *data);

/*
	Draw
*/

void		ft_pixel_put(t_data *data, int x, int y, int color);
void		draw_background(t_data *data);
void		draw_map(t_data *data, int x);
void		draw_texture(t_data *data);

/*
	Raycast
*/

void		init_raycast(t_data *data, int x);
void		ft_raycast(t_data *data, int x);
void		perform_dda(t_data *data);
void		add_texture(t_data *data, int x, int y);
void		init_step(t_data *data);
void		draw_start_end(t_data *data);

/*
	Free + Error
*/

void		ft_error(int id, char **map);
void		ft_error_2(t_data *data, int index);
void		free_map(char **map);
void		free_all(t_data *data);
void		free_data(t_data *data);

/*
	Utils
*/

int			count_line_map(char **map);
int			ft_strcmp(char *s1, char *s2);

/*
	Mouse
*/

int			mouse_move(t_data *data);

#endif
