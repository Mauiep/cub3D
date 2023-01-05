#include "../includes/cub3D.h"

//localise le player position et stock dans variable + stock direction camera
void    my_position(t_data *data)
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
                    data->pos_x = i;
                    data->pos_y = j;
                    data->direction = data->map[i][j];
                }
            j++;
        }
        i++;
    }
}