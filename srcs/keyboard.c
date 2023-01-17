#include "../includes/cub3D.h"

/*
    ft_exit va etre appele par le hook numero 17 (clic sur la croix)
*/
int     ft_exit(t_data *data)
{
    free_data(data);
    exit(0);
    return (0);
}

/*
    Cette fonction indique a notre structure quel touche "utile" est pressee
    (ex: dir_left => le personnage tourne sur lui meme vers gauche)
*/
int     key_pressed(int key, t_data *data)
{
    printf("key = %d\n", key);
    if (key == 65307) //53 before
        ft_exit(data);
    else if (key == 122) //13 before
    {
        printf("avant\n");
        data->move = 1;
    }
    else if (key == 100) //0 before
    {
        printf("left\n");
        data->dir_left = 1;
    } 
    else if (key == 113) //1 before
    {
        printf("right\n");
        data->dir_right = 1;
    }
    else
        return (0);
    return (1);
}

/*
    On initialise les hook : touche pressee et clic sur la croix
*/
void    keyboard(t_data *data)
{
    mlx_hook(data->win, 2, 1L<<0, key_pressed, data);
    mlx_hook(data->win, 17, 0, ft_exit, data);
}