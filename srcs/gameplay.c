#include "../includes/cub3D.h"

//attribue nouvelle position une fois que le personnage a avancer
void    new_pos(t_data *data)
{
    if (data->direction == 'N')
        data->map[data->pos_x - 1][data->pos_y] = 'N';
    if (data->direction == 'S')
        data->map[data->pos_x + 1][data->pos_y] = 'S';
    if (data->direction == 'W')
        data->map[data->pos_x][data->pos_y - 1] = 'W';
    if (data->direction == 'E')
        data->map[data->pos_x][data->pos_y + 1] = 'E';
    data->map[data->pos_x][data->pos_y] = '0';
}

//attribue nouvelle direction du personnage
//A 90 DEGRES POUR L'INSTANT (NEED CHANGEMENT) !!!!
void    new_direction(t_data *data)
{
    if ((data->direction == 'N' && data->dir_right)
        || (data->direction == 'S' && data->dir_left))
        data->map[data->pos_x][data->pos_y] = 'E';
    if ((data->direction == 'W' && data->dir_right)
        || (data->direction == 'E' && data->dir_left))
        data->map[data->pos_x][data->pos_y] = 'S';
    if ((data->direction == 'S' && data->dir_right)
        || (data->direction == 'N' && data->dir_left))
        data->map[data->pos_x][data->pos_y] = 'W';
    if ((data->direction == 'E' && data->dir_right)
        || (data->direction == 'W' && data->dir_left))
        data->map[data->pos_x][data->pos_y] = 'N';
}

//identifie si personnage avance ou se tourne
void    move_player(t_data *data)
{
    if (data->move)
        new_pos(data);
    else if (data->dir_left || data->dir_right)
        new_direction(data);
}

//gameplay dans loop hook
void    gameplay(t_data *data)
{
    my_position(data);
    move_player(data);
    data->move = 0;
    data->dir_left = 0;
    data->dir_right = 0;
}