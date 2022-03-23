#include "../includes/so_long.h"

static int ft_check_in(char c, char *find)
{
    int trigger;

    trigger = 0;
    while(*find)
    {
        if (c == *find)
            trigger = 0;
        find++;
    }
    if (trigger = 0)
        return (0);
    return (1);
}

int ft_wall_controller(t_so_long **game , t_map_check **check)
{
    while(++(*check)->y < (*check)->max_y)
    {
        (*check)->x = -1;
        (*check)->count_x = 0;
        while(++(*check)->x < (*check)->max_x
        && ft_check_in((*game)->str[(*check)->y][(*check)->x],"10EPCN"))
        {
            if((*check)->y == 0 || (*check)->y == (*check)->max_y - 1
            && (*game)->str[(*check)->y][(*check)->x] == '1')
                (*check)->count_x++;
        }
        if(((*check)->y == 0 || (*check)->y == (*check)->max_y -1)
        && (*check)->count_x < (*check)->max_x)
            return (0);
        if((*game)->str[(*check)->y][0] != '1' || (*game)->str[(*check)->y][(*check)->max_x-1] != '1')
            return (0);
        if ((*check)->x != (*check)->max_x)
            return (0);
    }
    return (1);
}