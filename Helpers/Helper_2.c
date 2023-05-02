/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:28:01 by agoujdam          #+#    #+#             */
/*   Updated: 2023/05/02 20:23:38 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_cloc_x(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				return (j);
			j++;
		}
		i++;
		j = 0;
	}
	return (-1);
}

int	ft_cloc_y(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				return (i);
			j++;
		}
		i++;
		j = 0;
	}
	return (-1);
}

int	ft_check_last_line(char *str)
{
	int		fd;
	int		line_count;
	char	buf[1];
	char	c;

	line_count = 0;
	fd = open(str, O_RDONLY);
	ft_negative_fd(str, fd);
	if (!read(fd, buf, 1))
		return (ft_printf("Error : Invalid Map!\n"));
	while (read(fd, buf, 1))
	{
		c = buf[0];
		if (buf[0] == '\n')
			line_count++;
	}
	if (c == '\n')
		return (ft_printf("Error : Check lines!\n"));
	return (0);
}

int	ft_strline(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
