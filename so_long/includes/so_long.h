/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 02:38:07 by tnard             #+#    #+#             */
/*   Updated: 2021/12/14 11:54:15 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlbx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct so_long
{
	char	**str;
	int		mult;
	int		max_x;
	int		max_y;
	int		player_x;
	int		player_y;
	int		picture_size;
	int		coin_count;
	int		player_move;
	int		enemies_speed;
	int		anim_count;
	int		anim_enemies;
	int		anim_coin;
	int		anim_player;
	void	*border;
	void	*background;
	void	*player[6];
	void	*enemies[4];
	void	*exit;
	void	*coin[6];
	void	*mlx;
	void	*mlx_win;
}				t_so_long;

typedef struct map_check
{
	int		max_x;
	int		max_y;
	int		count_x;
	int		x;
	int		y;
}				t_map_check;

int 			ft_init_map(t_so_long **game, char *map);
char			*ft_get_file(int fd, int size, int len);
char			**ft_split_fs(char *str, char *charset, int *ln);
int 			ft_wall_controller(t_so_long **game , t_map_check **check);
int				ft_create_map(t_so_long **game);
void			ft_init_xpm(t_so_long **game);
int				ft_key_events(int keycode, t_so_long **game);
int    			ft_animator(t_so_long **game);

#endif
