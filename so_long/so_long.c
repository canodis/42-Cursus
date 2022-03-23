#include "includes/so_long.h"

void ft_close(t_so_long **game, int x)
{
	mlx_destroy_image((*game)->mlx, (*game)->border);
	mlx_destroy_image((*game)->mlx, (*game)->background);
	mlx_destroy_image((*game)->mlx, (*game)->exit);

	x = 0;
	while (x < 3)
		mlx_destroy_image((*game)->mlx, (*game)->enemies[x++]);
	x = 0;
	while (x < 6)
		mlx_destroy_image((*game)->mlx, (*game)->coin[x++]);
	x = 0;
	while (x < 6)
		mlx_destroy_image((*game)->mlx, (*game)->player[x++]);
	mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
	mlx_destroy_display((*game)->mlx);
	x = 0;
	while (x < (*game)->max_y)
		free((*game)->str[x++]);
	free((*game)->str);
	free((*game)->mlx);
}

int UsageError(void)
{
    printf("Eksik veya fazla arguman girisi.\nKullanimi : ./solong harita.xpm\n");
    return (0);
}

int ft_check_name(char *arg)
{
    char *find;

    find = ft_strrchr(arg, '.');
    if(ft_strncmp(arg, find, ft_strlen(find)) == 0)
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    t_so_long *game;

    game = malloc(sizeof(t_so_long));
    if (!game)
        return (0);
    if (argc != 2)
        return(UsageError());
    game->mult = 50;
    if(ft_check_name(argv[1]) && ft_init_map(&game, argv[1])!= 0)
    {  
        game->player_move = 0;
        game->anim_count = 0;
        game->anim_player = 0;
        game->anim_enemies = 0;
        mlx_key_hook(game->mlx_win, ft_key_events, &game);
        mlx_loop_hook(game->mlx, ft_animator, &game);
        mlx_loop(game->mlx);
        ft_close(&game, 0);

    }
    else
        printf("\33[2K\rerror");
    free(game);
	return (1);
}