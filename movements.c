#include "so_long.h"

int    ft_move_up(char*** maps, int x, int y, void* param)
{
    t_params *params = (t_params*) param; 
    char** map;
    char c;

    map = (*maps);
    if (y > 0)
    {
        c = map[y - 1][x];
        if (c == '1' || (c == 'E' && ft_check_c(map,'C')))
            return (0);
        if (c == 'E' && !ft_check_c(map, 'C'))
            close_hook(params);
        if (c == '0' || c == 'C')
        {
            map[y - 1][x] = 'P';
            map[y][x] = '0';
        }
        return(1);
    }
    return (0);
}

int ft_move_right(char*** maps, int x, int y, void* param)
{
    t_params *params = (t_params*) param; 
    char** map;
    char c;

    map = (*maps);
    if (y < ft_strlen_no_nw(map[0]))
    {
        c = map[y][x + 1];
        if (c == '1' || (c == 'E' && ft_check_c(map,'C')))
            return (0);
        if (c == 'E' && !ft_check_c(map, 'C'))
            close_hook(params);
        if (c == '0' || c == 'C')
        {
            map[y][x + 1] = 'P';
            map[y][x] = '0';
        }
        return (1);
    }
    return (0);
}

int    ft_move_down(char*** maps, int x, int y, void* param)
{
    t_params *params = (t_params*) param; 
    char** map;
    char c;

    map = (*maps);
    if (y < ft_strline(map))
    {
        c = map[y + 1][x];
        if (c == '1' || (c == 'E' && ft_check_c(map,'C')))
            return (0);
        if (c == 'E' && !ft_check_c(map, 'C'))
            close_hook(params);
        if (c == '0' || c == 'C')
        {
            map[y + 1][x] = 'P';
            map[y][x] = '0';
        }
        return (1);
    }
    return (0);
}

int    ft_move_left(char*** maps, int x, int y, void* param)
{
    t_params *params = (t_params *) param; 
    char** map;
    char c;

    map = (*maps);
    if (x > 0)
    {
        c = map[y][x - 1];
        if (c == '1' || (c == 'E' && ft_check_c(map,'C')))
            return (0);
        if (c == 'E' && !ft_check_c(map, 'C'))
            close_hook(params);
        if (c == '0' || c == 'C')
        {
            map[y][x - 1] = 'P';
            map[y][x] = '0';
        }
        return (1);
    }
    return (0);
}