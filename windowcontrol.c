/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowcontrol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:54:36 by agoujdam          #+#    #+#             */
/*   Updated: 2023/05/02 20:36:35 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_params *p)
{
	char		***map;
	static int	i;
	t_indexes	a;

	map = (char ***)(*p).map;
	a.x = i;
	if (keycode == 53)
	{
		mlx_destroy_window((void *)(*p).mlx_inst, (void *)(*p).win_inst);
		exit(0);
	}
	if (keycode == 126 || keycode == 13)
		i += ft_move_up(map, ft_cloc_x(*map, 'P'), ft_cloc_y(*map, 'P'), p);
	else if (keycode == 125 || keycode == 1)
		i += ft_move_down(map, ft_cloc_x(*map, 'P'), ft_cloc_y(*map, 'P'), p);
	else if (keycode == 123 || keycode == 0)
		i += ft_move_left(map, ft_cloc_x(*map, 'P'), ft_cloc_y(*map, 'P'), p);
	else if (keycode == 124 || keycode == 2)
		i += ft_move_right(map, ft_cloc_x(*map, 'P'), ft_cloc_y(*map, 'P'), p);
	ft_check_print(a.x, i);
	ft_put_images(*map, a, (*p).win_inst, (*p).mlx_inst);
	return (0);
}

int	ft_close_hook(t_params *params)
{
	void	*mlx_inst;
	void	*win_inst;

	mlx_inst = (*params).mlx_inst;
	win_inst = (*params).win_inst;
	ft_close_window(mlx_inst, win_inst);
	return (0);
}

void	ft_close_window(void *mlx_inst, void *win_inst)
{
	mlx_destroy_window(mlx_inst, win_inst);
	exit(0);
}

void	*ft_check_img(void *a)
{
	if (!a)
	{
		ft_printf("Error : Image Corrupted or not found!\n");
		exit(0);
	}
	return (a);
}
