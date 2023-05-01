# ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "Get_Next_Line/get_next_line.h"

typedef struct indexs {
    int p;
    void* Collectible;
    void* Wall;
    void* Empty_Space;
    void* Player;
    void* Exit;
    void		*mlx_inst;
    void		*win_inst;
    char *ptr;
    int x;
    int y;
} indexes;

typedef struct	s_params
{
  void		*mlx_inst;
  void		*win_inst;
  void		***map;
}		t_params;

void    ft_put_images(char **map, indexes a, void *win_inst, void *mlx_inst);
int    ft_move_up(char*** maps, int x, int y, void* param);
int    ft_move_down(char*** maps, int x, int y, void* param);
int    ft_move_right(char*** maps, int x, int y, void* param);
int    ft_move_left(char*** maps, int x, int y, void* params);

int ft_name_test(char *name, char* av);
int ft_ends_with_ber(char* str);
int ft_check_last_line(char **map);

int close_hook(t_params* params);

int ft_check_map(char *name, int *line_count);
int ft_check_char_count(char *str, int char_count, int line_count);
int ft_check_edges(char *name, int lines, int line_count);
int ft_check_characters(char *name);

int ft_check_for_ones(char *line, int lines, int line_count);
int	ft_strlen_no_nw(char *s);
int ft_check_zocep(char *line, int i, int j);

char **ft_fill_map(char* name, int line_count);
int ft_free(char **map, int line_count, int fd);
int ft_check_c(char **map, char c);
int ft_check_p_and_e(char **map);
void    ft_fill_the_shit(char **map, int x, int y, int *e_presence);
void printCharMap(char** map);

int ft_cloc_x(char **map, char c);
int ft_cloc_y(char **map, char c);

char *ft_cat(const char *str1, const char *str2);

void ft_bismillah(char *name, void* mlx_inst, int line_count);
int ft_strline(char **map);
 
#endif