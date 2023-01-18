#include "../includes/cub3D.h"

/*

    Definit "au depart" les valeurs pour l'angle + init


    Par defaut on initialise tout a 0 donc cette
    fonction peut etre evite
*/

void    direction_zero(t_data *data, char orientation)
{
    if (orientation == 'N' || orientation == 'S')
    {
        data->dir_y = 0;
        data->plane_x = 0;
    }
    else if (orientation == 'E' || orientation == 'W')
    {
        data->dir_x = 0;
        data->plane_y = 0;
    }
}

void    orientation_player(t_data *data, char orientation)
{
    if (orientation == 'N')
    {
        data->dir_x = -1;
        data->plane_y = 0.66;
    }
    else if (orientation == 'S')
    {
        data->dir_x = 1;
        data->plane_y = -0.66;
    }
    else if (orientation == 'E')
    {
        data->dir_y = 1;
        data->plane_x = 0.66;
    }
    else if (orientation == 'W')
    {
        data->dir_y = -1;
        data->plane_x = -0.66;
    }
    direction_zero(data, orientation);
}

/*
    Cette fonction cherche la position du joueur dans la map
    et le stock dans la structure data (pos_x, pos_y)
    On recupere aussi la direction (NEED EXPLICATION SUR CETTE PARTIE)
*/

void    init_position(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
                || data->map[i][j] == 'W' || data->map[i][j] == 'E')
            {
                data->pos_x = i + 0.0005;
                data->pos_y = j + 0.0005;
                orientation_player(data, data->map[i][j]);
                data->map[i][j] = 0;
            }
            j++;
        }
        i++;
    }
}