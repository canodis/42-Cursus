#include "../includes/so_long.h"

static void ft_move(t_so_long **game, int x, int y, int next)
{
    (*game)->anim_player = 0;
    mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->background, 
    (*game)->player_x * (*game)->mult, (*game)->player_y * (*game)->mult);
    mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player[(*game)->anim_player],
    ((*game)->player_x + x) * (*game)->mult, ((*game)-> player_y + y) * (*game)->mult);
    (*game)->str[(*game)->player_y][(*game)->player_x] = '0';
    (*game)->str[(*game)->player_y + y][(*game)->player_x + x] = 'P';
    (*game)->player_x+= x;
    (*game)->player_y+= y;
    (*game)->player_move++;
	ft_printf("\33[2K\rHamle sayisi : %i", (*game)->player_move);
}

static void ft_ismove(t_so_long **game, int x, int y)
{
    if((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == '0')
        ft_move(&(*game), x, y, 1);
    else if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == 'C')
    {
        ft_move(&(*game), x, y, 1);
        (*game)->coin_count--;
    }
    else if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == 'E')
    {
        if((*game)->coin_count == 0)
        {
            ft_printf("\n*_*Tebrikler*_*\n");
            mlx_loop_end((*game)->mlx);
        }
        else
            ft_printf("\rAga körmüsün daha %i tane toplanacak obje var", (*game)->coin_count);
           
    }
    else if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == 'N')
    {
        ft_printf("\nKaybettin :)\n");
        mlx_loop_end((*game)->mlx);
    }
    else
        ft_printf("\rKoskoca duvari görmüyon mu ?");

}

int ft_key_events(int keycode, t_so_long **game)
{
    if (keycode == KEY_ESC)
	{
		mlx_loop_end((*game)->mlx);
		return (0);
	}
    else if (keycode == KEY_A)
        ft_ismove(&(*game), -1 , 0);
    else if (keycode == KEY_D)
        ft_ismove(&(*game), 1, 0);
    else if (keycode == KEY_W)
        ft_ismove(&(*game), 0, -1);
    else if (keycode == KEY_S)
        ft_ismove(&(*game), 0, 1);
    return (0);
}