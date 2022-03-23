#include "../includes/so_long.h"

void	*ft_open_xpm(t_so_long **game, char *str)
{
	return (mlx_xpm_file_to_image((*game)->mlx, str, &(*game)->picture_size, &(*game)->picture_size));
}

static void ft_open_coin(t_so_long **game)
{
    (*game)->coin[0] = ft_open_xpm(&(*game), "./img/coin/0.xpm");
    (*game)->coin[1] = ft_open_xpm(&(*game), "./img/coin/1.xpm");
    (*game)->coin[2] = ft_open_xpm(&(*game), "./img/coin/2.xpm");
    (*game)->coin[3] = ft_open_xpm(&(*game), "./img/coin/3.xpm");
    (*game)->coin[4] = ft_open_xpm(&(*game), "./img/coin/4.xpm");
    (*game)->coin[5] = ft_open_xpm(&(*game), "./img/coin/5.xpm");

}

static void ft_open_player(t_so_long **game)
{
    (*game)->player[0] = ft_open_xpm(&(*game), "./img/player/0.xpm");
    (*game)->player[1] = ft_open_xpm(&(*game), "./img/player/1.xpm");
    (*game)->player[2] = ft_open_xpm(&(*game), "./img/player/2.xpm");
    (*game)->player[3] = ft_open_xpm(&(*game), "./img/player/3.xpm");
    (*game)->player[4] = ft_open_xpm(&(*game), "./img/player/4.xpm");
    (*game)->player[5] = ft_open_xpm(&(*game), "./img/player/5.xpm");
}

static void ft_open_enemies(t_so_long **game)
{
    (*game)->enemies[0] = ft_open_xpm(&(*game), "./img/enemies/0.xpm");
    (*game)->enemies[1] = ft_open_xpm(&(*game), "./img/enemies/1.xpm");
    (*game)->enemies[2] = ft_open_xpm(&(*game), "./img/enemies/2.xpm");
}

void    ft_init_xpm(t_so_long **game)
{
    (*game)->border = ft_open_xpm(&(*game), "./img/border.xpm");
    (*game)->background = ft_open_xpm(&(*game), "./img/background.xpm");
    (*game)->exit = ft_open_xpm(&(*game), "./img/exit.xpm");
    ft_open_enemies(&(*game));
    ft_open_coin(&(*game));
    ft_open_player(&(*game));
}