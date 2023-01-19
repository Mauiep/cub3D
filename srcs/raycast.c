#include "../includes/cub3D.h"

/*
    Init raycasting
    /!\ PAS BESOIN DE TOUT METTRE DANS LA BOUCLE
*/

void    init_raycast(t_data *data)
{
    int     x;

    x = 0;
    while (x < 1280)
    {
        data->raycast.cameraX = 2 * x / (double)1280 - 1;
        data->raycast.raydirX = data->dir_x + data->plane_x * data->raycast.cameraX;
        data->raycast.raydirY = data->dir_y + data->plane_y * data->raycast.cameraX;
        data->raycast.mapX = (int)data->pos_x;
        data->raycast.mapY = (int)data->pos_y;
        data->raycast.hit = 0;
        x++;
    }
}

/*
    Calculer la direction et la sideDist initiale
*/

void    init_step(t_data *data)
{
    if (data->raycast.raydirX < 0)
    {
        data->raycast.stepX = -1;
        data->raycast.sideDistX = (data->pos_x - data->raycast.mapX) * data->raycast.deltaDistX;
    }
    else
    {
        data->raycast.stepX = 1;
        data->raycast.sideDistX = (data->raycast.mapX + 1.0 - data->pos_x) * data->raycast.deltaDistX;
    }
    if (data->raycast.raydirY < 0)
    {
        data->raycast.stepY = -1;
        data->raycast.sideDistY = (data->pos_y - data->raycast.mapY) * data->raycast.deltaDistY;
    }
    else
    {
        data->raycast.stepY = 1;
        data->raycast.sideDistY = (data->raycast.mapY + 1.0 - data->pos_y) * data->raycast.deltaDistY;
    }
}

/*
    DDA fonction
    Fonction qui permet de longer les murs quand on est colle a ce dernier (je crois mdr)
*/

void    perform_dda(t_data *data)
{
    while (data->raycast.hit == 0)
    {
        if (data->raycast.sideDistX < data->raycast.sideDistY)
        {
            data->raycast.sideDistX += data->raycast.deltaDistX;
            data->raycast.mapX += data->raycast.stepX;
            data->raycast.side = 0;
        }
        else
        {
            data->raycast.sideDistY += data->raycast.deltaDistY;
            data->raycast.mapY += data->raycast.stepY;
            data->raycast.side = 1;
        }
        if (data->map[data->raycast.mapX][data->raycast.mapY] > '0')
            data->raycast.hit = 1;
    }
}