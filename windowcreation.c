#include "so_long.h"

void close_window(void* mlx_inst, void* win_inst)
{
    mlx_destroy_window(mlx_inst, win_inst);
    exit(0);
}

void ft_check_print(int a, int i)
{
    if (a != i)
        printf("Counter = %d\n", i);
}
int key_hook(int keycode, t_params* params)
{
    void* mlx_inst = (*params).mlx_inst;
    void* win_inst = (*params).win_inst;
    char*** map = (char ***) (*params).map;
    static int i;
    indexes a;

    a.x = i;
    if (keycode == 53 || keycode == 2)
    {
        mlx_destroy_window(mlx_inst, win_inst);
        exit(0);
    }
    if (keycode == 126)
        i += ft_move_up(map, ft_cloc_x(*map, 'P'), ft_cloc_y(*map, 'P'), params);
    else if (keycode == 125)
        i += ft_move_down(map, ft_cloc_x(*map, 'P'), ft_cloc_y(*map, 'P'), params);
    else if (keycode == 123)
        i += ft_move_left(map, ft_cloc_x(*map, 'P'), ft_cloc_y(*map, 'P'), params);
    else if (keycode == 124)
        i += ft_move_right(map, ft_cloc_x(*map, 'P'), ft_cloc_y(*map, 'P'), params);
    ft_check_print(a.x, i);
    ft_put_images(*map, a,win_inst,mlx_inst);
    return (0);
}

int close_hook(t_params* params)
{
    void* mlx_inst = (*params).mlx_inst;
    void* win_inst = (*params).win_inst;

    close_window(mlx_inst, win_inst);
    return (0);
}

int check_images_loaded(indexes a)
{
    if (!a.Collectible || !a.Wall || !a.Empty_Space || !a.Player || !a.Exit) {
        printf("AAA\n");
        exit (0);
    }
    return 1;
}

void ft_put_images(char **map, indexes a, void *win_inst, void *mlx_inst)
{
    a.p = 75;
    a.Collectible = mlx_xpm_file_to_image(mlx_inst, "Images/C.xpm", &a.p, &a.p);
    a.Wall = mlx_xpm_file_to_image(mlx_inst, "Images/W.xpm", &a.p, &a.p);
    a.Empty_Space = mlx_xpm_file_to_image(mlx_inst, "Images/ES.xpm", &a.p, &a.p);
    a.Player = mlx_xpm_file_to_image(mlx_inst, "Images/P.xpm", &a.p, &a.p);
    a.Exit = mlx_xpm_file_to_image(mlx_inst, "Images/E.xpm", &a.p, &a.p);
    if (!ft_check_c(map, 'C'))
        a.Exit = mlx_xpm_file_to_image(mlx_inst, "Images/DO.xpm", &a.p, &a.p);
    check_images_loaded(a);
    a.x = 0;
    a.y = 0;
    while (map[a.y] != 0)
    {
        while(map[a.y][a.x] != 0)
        {
            if (map[a.y][a.x] == '0')
                mlx_put_image_to_window(mlx_inst, win_inst, a.Empty_Space,75*a.x,75*a.y);
            else if (map[a.y][a.x] == '1')
                mlx_put_image_to_window(mlx_inst, win_inst, a.Wall,75*a.x,75*a.y);
            else if (map[a.y][a.x] == 'P')
                mlx_put_image_to_window(mlx_inst, win_inst, a.Player,75*a.x,75*a.y);
            else if (map[a.y][a.x] == 'C')
                mlx_put_image_to_window(mlx_inst, win_inst, a.Collectible,75*a.x,75*a.y);
            else if (map[a.y][a.x] == 'E')
                mlx_put_image_to_window(mlx_inst, win_inst, a.Exit,75*a.x,75*a.y);
            a.x++;
        }
        a.y++;
        a.x = 0;
    }
}

void ft_bismillah(char *name, void* mlx_inst, int line_count)
{
    t_params    params;
    void *win_inst;
    int pixels;
    char **map;
    indexes a;

    a.mlx_inst = mlx_inst;
    pixels = 75;
    line_count = ft_check_char_count(name,0,0);
    map = ft_fill_map(name, line_count);
    if (!mlx_inst)
        return ;
    win_inst = mlx_new_window(mlx_inst, pixels*ft_strlen_no_nw(map[0]) ,pixels*ft_strline(map), "SO LONG");
    a.win_inst = win_inst;
    params.mlx_inst = mlx_inst;
    params.win_inst = win_inst;
    params.map = (void *)&map;
    mlx_hook(a.win_inst, 2, 0, key_hook, &params);
    mlx_hook(a.win_inst, 17, 0, close_hook, &params);
    ft_put_images(map, a, a.win_inst, mlx_inst);
    mlx_loop(mlx_inst);
}
