#include "../includes/cub3D.h"

void    ft_raycast(t_data *data)
{
    int     x;
    double  cameraX;

    x = 0;
    while (x < 1280)
    {
        cameraX = 2 * x / (double)1280 - 1;
        raydirX = data->dir_x + data->plane_x * cameraX;
        raydirY = data->dir_y + data->plane_y * cameraX;
        x++;
    }
}