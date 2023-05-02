/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:11:35 by agoujdam          #+#    #+#             */
/*   Updated: 2023/05/02 20:41:37 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "FT_PRINTF/ft_printf.h"

typedef struct s_indexs
{
	int		p;
	void	*collectible;
	void	*wall;
	void	*empty_space;
	void	*player;
	void	*exit;
	void	*mlx_inst;
	void	*win_inst;
	char	*ptr;
	int		x;
	int		y;
}			t_indexes;

typedef struct s_params
{
	void	*mlx_inst;
	void	*win_inst;
	void	***map;
}			t_params;

int			ft_free(char **map, int line_count, int fd);
char		**ft_fill_map(char *name, int line_count);
int			ft_check_c(char **map, char c);
int			ft_check_p_and_e(char **map);
void		ft_fill_the_shit(char **map, int x, int y, int *e_presence);
int			ft_check_char_count(char *str);
int			ft_check_edges(char *name, int lines, int line_count);
int			ft_check_characters(char *name);
int			ft_move_up(char ***maps, int x, int y, void *param);
int			ft_move_right(char ***maps, int x, int y, void *param);
int			ft_move_down(char ***maps, int x, int y, void *param);
int			ft_move_left(char ***maps, int x, int y, void *param);
int			ft_ends_with_ber(char *str);
int			ft_name_test(char *av);
int			ft_key_hook(int keycode, t_params *p);
int			ft_close_hook(t_params *params);
void		ft_close_window(void *mlx_inst, void *win_inst);
void		*ft_check_img(void *a);
void		ft_check_print(int a, int i);
void		*ft_rt(char **map, int a, void *mlx_inst);
int			ft_mp(t_indexes a, void *img, int x, int y);
void		ft_put_images(char **map, t_indexes a, void *wi, void *mi);
int			ft_strlen_no_nw(char *s);
int			ft_check_for_ones(char *line, int lines, int line_count);
int			ft_check_zocep(char *line, int i, int j);
void		ft_negative_fd(char *str, int fd);
int			ft_cloc_x(char **map, char c);
int			ft_cloc_y(char **map, char c);
int			ft_check_last_line(char *str);
int			ft_strline(char **map);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
void		ft_bismillah(char *name, void *mlx_inst, int line_count);
int			ft_check_map(char *name, int *line_count);

#endif
