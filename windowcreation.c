/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowcreation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:44:15 by agoujdam          #+#    #+#             */
/*   Updated: 2023/05/02 20:28:54 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	ft_check_print(int a, int i)
{
	if (a != i)
		ft_printf("Counter = %d\n", i);
}

void	*ft_rt(char **map, int a, void *mlx_inst)
{
	int	p;

	p = 75;
	if (a == 1)
		return (ft_check_img(mlx_xpm_file_to_image(mlx_inst, "Textures/C.xpm",
					&p, &p)));
	else if (a == 2)
		return (ft_check_img(mlx_xpm_file_to_image(mlx_inst, "Textures/W.xpm",
					&p, &p)));
	else if (a == 3)
		return (ft_check_img(mlx_xpm_file_to_image(mlx_inst, "Textures/ES.xpm",
					&p, &p)));
	else if (a == 4)
		return (ft_check_img(mlx_xpm_file_to_image(mlx_inst, "Textures/P.xpm",
					&p, &p)));
	else if (a == 5 && ft_check_c(map, 'C'))
		return (ft_check_img(mlx_xpm_file_to_image(mlx_inst, "Textures/E.xpm",
					&p, &p)));
	else if (a == 5 && !ft_check_c(map, 'C'))
		return (ft_check_img(mlx_xpm_file_to_image(mlx_inst, "Textures/DO.xpm",
					&p, &p)));
	return (0);
}

int	ft_mp(t_indexes a, void *img, int x, int y)
{
	return (mlx_put_image_to_window(a.mlx_inst, a.win_inst, img, x, y));
}

void	ft_put_images(char **map, t_indexes a, void *wi, void *mi)
{
	a.x = 0;
	a.y = 0;
	a.win_inst = wi;
	a.mlx_inst = mi;
	while (map[a.y] != 0)
	{
		while (map[a.y][a.x] != 0)
		{
			if (map[a.y][a.x] == '0')
				ft_mp(a, ft_rt(map, 3, mi), 75 * a.x, 75 * a.y);
			if (map[a.y][a.x] == '1')
				ft_mp(a, ft_rt(map, 2, mi), 75 * a.x, 75 * a.y);
			if (map[a.y][a.x] == 'P')
				ft_mp(a, ft_rt(map, 4, mi), 75 * a.x, 75 * a.y);
			if (map[a.y][a.x] == 'C')
				ft_mp(a, ft_rt(map, 1, mi), 75 * a.x, 75 * a.y);
			if (map[a.y][a.x] == 'E')
				ft_mp(a, ft_rt(map, 5, mi), 75 * a.x, 75 * a.y);
			a.x++;
		}
		a.y++;
		a.x = 0;
	}
}

void	ft_bismillah(char *name, void *mlx_inst, int line_count)
{
	t_params	params;
	void		*win_inst;
	int			pixels;
	char		**map;
	t_indexes	a;

	a.mlx_inst = mlx_inst;
	pixels = 75;
	map = ft_fill_map(name, line_count);
	if (!mlx_inst)
		return ;
	win_inst = mlx_new_window(mlx_inst, pixels * ft_strlen_no_nw(map[0]), pixels
			* ft_strline(map), "SO LONG");
	a.win_inst = win_inst;
	params.mlx_inst = mlx_inst;
	params.win_inst = win_inst;
	params.map = (void *)&map;
	ft_put_images(map, a, a.win_inst, mlx_inst);
	mlx_hook(a.win_inst, 2, 0, ft_key_hook, &params);
	mlx_hook(a.win_inst, 17, 0, ft_close_hook, &params);
	ft_printf("Counter = 0\n");
	mlx_loop(mlx_inst);
}
