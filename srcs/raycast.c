#include "../includes/cub3D.h"

/*
    Fonction raycast
*/

void    ft_raycast(t_data *data)
{
    int     x;

    x = 0;
    while (x < 1280)
    {
        init_raycast(data, x);
        data->raycast.hit = 0;
        init_step(data);
        perform_dda(data);
        drawEnd_drawStart(data);
        if (data->raycast.side == 0)
        {
            data->raycast.wallX = data->pos_y + data->raycast.perpWallDist
                * data->raycast.raydirY;
        }
        else
        {    
            data->raycast.wallX = data->pos_x + data->raycast.perpWallDist
                * data->raycast.raydirX;
        }
        data->raycast.wallX -= floor(data->raycast.wallX);
        data->raycast.texX = (int)(data->raycast.wallX * (double)64);
        add_texture(data, x, data->raycast.drawStart);
        draw_map(data, x);
        x++;
    }
}

/*
    Init la direction du player
*/

void    init_step(t_data *data)
{
    if (data->raycast.raydirX < 0)
    {
        data->raycast.stepX = -1;
        data->raycast.sideDistX = (data->pos_x - data->raycast.mapX)
            * data->raycast.deltaDistX;
    }
    else
    {
        data->raycast.stepX = 1;
        data->raycast.sideDistX = (data->raycast.mapX + 1.0 - data->pos_x)
            * data->raycast.deltaDistX;
    }
    if (data->raycast.raydirY < 0)
    {
        data->raycast.stepY = -1;
        data->raycast.sideDistY = (data->pos_y - data->raycast.mapY)
            * data->raycast.deltaDistY;
    }
    else
    {
        data->raycast.stepY = 1;
        data->raycast.sideDistY = (data->raycast.mapY + 1.0 - data->pos_y)
            * data->raycast.deltaDistY;
    }
}

/*
    DDA fonction
    La méthode DDA (Digital Differential Analyzer) me permet de savoir où mon rayon touche le prochain wall.
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

/*
    Calculer la distance du rayon perpendiculaire (la distance euclidienne donnerait un effet de fish-eye!)
*/

void    drawEnd_drawStart(t_data *data)
{
    if (data->raycast.side == 0)
    {
        data->raycast.perpWallDist = (data->raycast.mapX - data->pos_x
            + (1 - data->raycast.stepX) / 2) / data->raycast.raydirX;
    }
    else
    {
        data->raycast.perpWallDist = (data->raycast.mapY - data->pos_y
            + (1 - data->raycast.stepY) / 2) / data->raycast.raydirY;
    }
    data->raycast.lineHeight = (int)(720 / data->raycast.perpWallDist);
    data->raycast.drawStart = -data->raycast.lineHeight / 2 + 720 / 2;
    if (data->raycast.drawStart < 0)
        data->raycast.drawStart = 0;
    data->raycast.drawEnd = data->raycast.lineHeight / 2 + 720 / 2;
    if (data->raycast.drawEnd >= 720)
        data->raycast.drawEnd = 720 - 1;
}

/*
    Fonction qui va add les textures au fur et a mesure
*/

void    add_texture(t_data *data, int x, int y)
{
    data->raycast.step = 1.0 * 64 / data->raycast.lineHeight;
    data->raycast.texPos = (data->raycast.drawStart - 720 / 2
        + data->raycast.lineHeight / 2) * data->raycast.step;
    if (data->raycast.side == 0 && data->raycast.raydirX > 0)
        data->raycast.texX = 64 - data->raycast.texX - 1;
    if (data->raycast.side == 1 && data->raycast.raydirY < 0)
        data->raycast.texX = 64 - data->raycast.texX - 1;
    while (y < data->raycast.drawEnd)
    {
        data->raycast.texY = (int)(data->raycast.texPos) & (64 - 1);
        data->raycast.texPos += data->raycast.step;
        draw_texture(data);
        data->buffer[y][x] = data->raycast.color;
        y++;
    }
}