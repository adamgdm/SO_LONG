/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:51:39 by agoujdam          #+#    #+#             */
/*   Updated: 2023/05/01 23:23:36 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ends_with_ber(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 1;
	while (str[len])
		len++;
	if (len < 4)
		return (0);
	while (i <= 3)
	{
		if (str[len - i] != ".ber"[4 - i])
			return (0);
		i++;
	}
	if (len == 4)
		return (0);
	return (1);
}

int	ft_name_test(char *av)
{
	int	fd;

	if (!ft_ends_with_ber(av))
		return (0);
	fd = open(av, O_RDONLY);
	close(fd);
	if (fd == -1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		line_count;
	void	*mlx_inst;

	line_count = 0;
	if (ac == 2)
	{
		if (!ft_name_test(av[1]))
		{
			ft_printf("Error : Name of the file is wrong!\n");
			return (0);
		}
		if (ft_check_map(av[1], &line_count))
		{
			mlx_inst = mlx_init();
			ft_bismillah(av[1], mlx_inst, line_count);
		}
	}
	else
		ft_printf("Error : Wrong argument count\n");
	return (0);
}
