#include "../includes/so_long.h"

void create_object(t_so_long **game, char obj, int x, int y)
{
    if (obj == '0')
        mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->background, x * (*game)->mult, y * (*game)->mult);
    else if (obj == '1')
        mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->border, x * (*game)->mult, y * (*game)->mult);
    else if (obj == 'E')
        mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->exit, x * (*game)->mult, y * (*game)->mult);
    else if (obj == 'N')
        mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->enemies[0], x * (*game)->mult, y * (*game)->mult);
    else if (obj == 'C')
    {
        (*game)->coin_count++;
        mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->coin[0], x * (*game)->mult, y * (*game)->mult);
    }
    else if (obj == 'P')
    {
        mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player[0], x * (*game)->mult, y * (*game)->mult);
        (*game)->player_x = x;
        (*game)->player_y = y;
    }
}

int ft_check_map(t_so_long **game)
{
    char    checker[4];
    int x;
    int y;

    x = 0;
    while (x < 3)
        checker[x++] = 0;
    y = -1;
    while(++y < (*game)->max_y)
    {
        x = -1;
        while(++x < (*game)->max_x)
        {
            if((*game)->str[y][x] == 'P')
                checker[0]++;
            else if ((*game)->str[y][x] == 'C')
                checker[1]++;
            else if ((*game)->str[y][x] == 'E')
                checker[2]++;
        }
    }
    if (checker[0] != 1 || checker[1] == 0 || checker[2] == 0)
        return (0);
    return (1);
}

int ft_create_map(t_so_long **game)
{
    int x;
    int y;

    (*game)->picture_size = (*game)->max_x;
    (*game)->coin_count = 0;
    (*game)->mlx = mlx_init();
    (*game)->mlx_win = mlx_new_window((*game)->mlx, (*game)->max_x * (*game)->mult, (*game)->max_y * (*game)->mult, "canodis");
    ft_init_xpm(&(*game)); 
    int a = 0;
    y = -1;
    while (++y < (*game)->max_y)
    {
        x = -1;
        while (++x < (*game)->max_x)
        {
            create_object(&(*game), (*game)->str[y][x], x, y);
        }
    }
    return (ft_check_map(&(*game)));
}