#include "../includes/so_long.h"

static int ft_move_enemy(t_so_long **game, int x, int y, int z)
{
    mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
        (*game)->background, x * (*game)->mult, y * (*game)->mult);
    if((*game)->str[y][x + 1] == 'P' || (*game)->str[y][x - 1] == 'P')
        mlx_loop_end((*game)->mlx);
    else if ((*game)->str[y][x + 1] == '0')
    {
        (*game)->str[y][x] = '0';
		(*game)->str[y][x + 1] = 'N';
        mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->enemies[(*game)->anim_enemies],
        (x + 1) * (*game)->mult, y * (*game)->mult);
        return (1);
    }
    else
    {
		(*game)->str[y][x] = '0';
		while ((*game)->str[y][z] != '0' && z != (*game)->max_x)
			z++;
		(*game)->str[y][z] = 'N';
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->enemies[(*game)->anim_enemies],
			(z) * (*game)->mult, y * (*game)->mult);
    }
    return (0);
}

static void ft_ismove_enemies(t_so_long **game)
{
    int x;
    int y;

    y = -1;
    while(++y < (*game)->max_y)
    {
        x = 0;
        while(++x < (*game)->max_x)
            if ((*game)->str[y][x] == 'N')
                x += ft_move_enemy(&(*game),x ,y, 0);
    }
}

static void ft_change_sprites(t_so_long **game, int x, int y, char type)
{
    if (type == 'P')
    {
        mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player[(*game)->anim_player], x * (*game)->mult, y * (*game)->mult);
        if ((*game)->anim_player == 5)
			(*game)->anim_player = 0;
    }
    else if (type == 'N')
    {
        mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->enemies[(*game)->anim_enemies], x * (*game)->mult, y * (*game)->mult);
		if ((*game)->anim_enemies == 2)
			(*game)->anim_enemies = 0;
    }
    else if (type == 'C')
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->coin[(*game)->anim_coin], x * (*game)->mult, y * (*game)->mult);
		if ((*game)->anim_coin == 5)
			(*game)->anim_coin = 0;
	}
}

static void ft_anim(t_so_long **game)
{
    int x;
    int y;

    y = -1;
    while (++y < (*game)->max_y)
    {
        x = -1;
        while(++x < (*game)->max_x)
        {
            if ((*game)->str[y][x] == 'N')
                ft_change_sprites(&(*game), x, y, 'N');
            else if ((*game)->str[y][x] == 'P')
				ft_change_sprites(&(*game), x, y, 'P');
			else if ((*game)->str[y][x] == 'C')
				ft_change_sprites(&(*game), x, y, 'C');
        }
    }
    (*game)->anim_coin++;
    (*game)->anim_player++;
    (*game)->anim_enemies++;
}

int    ft_animator(t_so_long **game)
{
    (*game)->anim_count++;
    (*game)->enemies_speed++;

    if ((*game)->anim_count == 15000)
    {
        ft_anim(&(*game));
        (*game)->anim_count = 1;
    }
    if ((*game)->enemies_speed == 120000)
    {
        (*game)->enemies_speed = 0;
        ft_ismove_enemies(&(*game));
    }
    return (0);
}