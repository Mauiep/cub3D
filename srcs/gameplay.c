#include "../includes/cub3D.h"

/*
    Change valeur pos_x et pos_y selon si le personnage avance, recul, marche a droite ou a gauche
    -> move_back_foward -> avance ou recul
    -> move_right_left -> marche lateralement a droite ou a gauche
    -> les "if" verifie si collision avec mur avant le deplacement
*/
void    move_back_foward(t_data *data)
{
    printf("keypress Avancer :%d  Reculer : %d\n", data->move_forward, data->move_back);
    if (data->move_forward)
    {
        if (data->map[(int)(data->pos_x + data->dir_x * data->speedmove)][(int)data->pos_y] == '0')
            data->pos_x += data->dir_x * data->speedmove;
        if (data->map[(int)data->pos_x][(int)(data->pos_y + data->dir_y * data->speedmove)] == '0')
            data->pos_y += data->dir_y * data->speedmove;
    }
    if (data->move_back)
    {
        if (data->map[(int)(data->pos_x - data->dir_x * data->speedmove)][(int)data->pos_y] == '0')
            data->pos_x -= data->dir_x * data->speedmove;
        if (data->map[(int)data->pos_x][(int)(data->pos_y - data->dir_y * data->speedmove)] == '0')
            data->pos_y -= data->dir_y * data->speedmove;
    }
    printf("posX=%f posY=%f\n", data->pos_x, data->pos_y);
}

void    move_right_left(t_data *data)
{
    printf("keypress Droite :%d  Gauche : %d\n", data->move_right, data->move_left);
    if (data->move_right)
    {
        if (data->map[(int)(data->pos_x + data->dir_y * data->speedmove)][(int)data->pos_y] == '0')
            data->pos_x += data->dir_y * data->speedmove;
        if (data->map[(int)data->pos_x][(int)(data->pos_y + data->dir_x * data->speedmove)] == '0')
            data->pos_y += data->dir_x * data->speedmove;
    }
    if (data->move_left)
    {
        if (data->map[(int)(data->pos_x - data->dir_y * data->speedmove)][(int)data->pos_y] == '0')
            data->pos_x -= data->dir_y * data->speedmove;
        if (data->map[(int)data->pos_x][(int)(data->pos_y - data->dir_x * data->speedmove)] == '0')
            data->pos_y -= data->dir_x * data->speedmove;
    }
    printf("posX=%f posY=%f\n", data->pos_x, data->pos_y);
}

/*
    Change dir_x, dir_y, plane_x et plane_y pour la nouvelle orientation du player avec les fleches
    /!\ A TEST AVEC AFFICHAGE
*/
void    rotation_player(t_data *data, double old_dir_x, double old_plane_x)
{
    printf("keypress Rotation Droite :%d  Rotation Gauche : %d\n", data->rot_right, data->rot_left);
    if (data->rot_right)
    {
        data->dir_x = data->dir_x * cos(-data->speedrot) - data->dir_y * sin(-data->speedrot);
        data->dir_y = old_dir_x * cos(-data->speedrot) + data->dir_y * sin(-data->speedrot);
        data->plane_x = data->plane_x * cos(-data->speedrot) - data->plane_y * sin(-data->speedrot);
        data->plane_y = old_plane_x * cos(-data->speedrot) + data->plane_y * sin(-data->speedrot);
    }
    else if (data->rot_left)
    {
        data->dir_x = data->dir_x * cos(data->speedrot) - data->dir_y * sin(data->speedrot);
        data->dir_y = old_dir_x * cos(data->speedrot) + data->dir_y * sin(data->speedrot);
        data->plane_x = data->plane_x * cos(data->speedrot) - data->plane_y * sin(data->speedrot);
        data->plane_y = old_plane_x * cos(-data->speedrot) + data->plane_y * sin(data->speedrot);
    }
    printf("dirX=%f dirY=%f\n", data->dir_x, data->dir_y);
}

/*
    Verifie au prealable ce que va faire le personnage
*/
void    move_player(t_data *data)
{
    if (data->move_forward || data->move_back)
        move_back_foward(data);
    else if (data->move_right || data->move_left)
        move_right_left(data);
    else if (data->rot_left || data->rot_right)
        rotation_player(data, data->dir_x, data->plane_x);
}

//gameplay dans loop hook
void    gameplay(t_data *data)
{
     // /!\ a deplacer puisque info necessaire uniquement au lancement
    data->speedrot = 0.05; // a mettre dans un init
    data->speedmove = 0.05; // pareil
    move_player(data);
    data->move_forward = 0;
    data->move_back = 0;
    data->move_right = 0;
    data->move_left = 0;
    data->rot_left = 0;
    data->rot_right = 0;
}