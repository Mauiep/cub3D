#include "../includes/cub3D.h"

//exit
int     ft_exit(t_data *data)
{
    free_data(data);
    exit(0);
    return (0);
}

//attribue touche avec l'action (ex: dir_left => le personnage tourne sur lui meme vers gauche)
int     key_pressed(int key, t_data *data)
{
    if (key == 53)
        ft_exit(data);
    else if (key == 13)
        data->move = 1;
    else if (key == 0)
        data->dir_left = 1;
    else if (key == 2)
        data->dir_right = 1;
    else
        return (0);
    return (1);
}

//init keyboard hook
void    keyboard(t_data *data)
{
    mlx_hook(data->win, 2, 0, key_pressed, data);
    mlx_hook(data->win, 17, 0, ft_exit, data);
}