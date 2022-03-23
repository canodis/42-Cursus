#include "../includes/so_long.h"

int ft_init_map(t_so_long **game, char *map)
{
    t_map_check *check;
    char *map_str;
    int fd;

    check = malloc(sizeof(t_map_check));
    if(!check)
        return (0);
    fd = open(map, O_RDONLY);
    map_str  = ft_get_file(fd, 0, 0);//map'i map_str'nin içine alıyoruz
    (*game)->str = ft_split_fs(map_str, "\n", &check->max_y);//Map'i game->str'nin içine alıyoruz.
    free(map_str);
    close(fd);
    check->max_x = ft_strlen((*game)->str[0]);
    if (check->max_x == check->max_y)
    {
        ft_printf("\33[2K\rHarita dikdortgen olmalidir!");
        return (0);
    }
    check->y = -1;
    if(ft_wall_controller(&(*game), &check) == 0)
        return (0);
    (*game)->max_x = check->max_x;
	(*game)->max_y = check->max_y;
    free(check);
    return (ft_create_map(&(*game)));
}