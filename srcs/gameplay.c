#include "../includes/cub3D.h"

//attribue nouveline_lengthe position une fois que le personnage a avancer
// /!\ EN COURS DE CHANGEMENT !!!!
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

//attribue nouveline_lengthe direction du personnage
//OK A PRIORI !!!
void    rotation_player(t_data *data, double old_dir_x, double old_plane_x)
{
    if (data->dir_right)
    {
        data->dir_x = data->dir_x * cos(-data->speedrot) - data->dir_y * sin(-data->speedrot);
        data->dir_y = old_dir_x * cos(-data->speedrot) - data->dir_y * sin(-data->speedrot);
        data->plane_x = data->plane_x * cos(-data->speedrot) - data->plane_y * sin(-data->speedrot);
        data->plane_y = old_plane_x * cos(-data->speedrot) - data->plane_y * sin(-data->speedrot);
    }
    else if (data->dir_left)
    {
        data->dir_x = data->dir_x * cos(data->speedrot) - data->dir_y * sin(data->speedrot);
        data->dir_y = old_dir_x * cos(data->speedrot) - data->dir_y * sin(data->speedrot);
        data->plane_x = data->plane_x * cos(data->speedrot) - data->plane_y * sin(data->speedrot);
        data->plane_y = old_plane_x * cos(-data->speedrot) - data->plane_y * sin(data->speedrot);
    }
}

/*

    Check si il y'a un mur devant le player avant d'avancer
    /!\ BROUILLON A CHANGER
    erreur normal puisque de pos_x est devenu float

*/

int     wall_move(t_data *data)
{
    if (data->direction == 'N'
        && data->map[data->pos_x - 1][data->pos_y] == '1')
        return (0);
    if (data->direction == 'S'
        && data->map[data->pos_x + 1][data->pos_y] == '1')
        return (0);
    if (data->direction == 'E'
        && data->map[data->pos_x][data->pos_y + 1] == '1')
        return (0);
    if (data->direction == 'W'
        && data->map[data->pos_x][data->pos_y - 1] == '1')
        return (0);
    return (1);
}

//identifie si personnage avance ou se tourne
void    move_player(t_data *data)
{
    if (data->move && wall_move(data))
        new_pos(data);
    else if (data->dir_left || data->dir_right)
        rotation_player(data, data->dir_x, data->plane_x);
}

//gameplay dans loop hook
void    gameplay(t_data *data)
{
    my_position(data); // /!\ a deplacer puisque info necessaire uniquement au lancement
    data->speedrot = 0.05; // a mettre dans un init
    data->speedmove = 0.05; // pareil
    move_player(data);
    data->move = 0;
    data->dir_left = 0;
    data->dir_right = 0;
}