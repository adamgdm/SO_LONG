/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_Check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:24:45 by agoujdam          #+#    #+#             */
/*   Updated: 2023/05/02 20:06:25 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_char_count(char *str)
{
	int		fd;
	int		line_count;
	char	buf[1];

	line_count = 0;
	fd = open(str, O_RDONLY);
	ft_negative_fd(str, fd);
	if (!read(fd, buf, 1))
		return (line_count);
	if (buf[0] != '\n')
		line_count++;
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			line_count++;
	}
	return (line_count);
}

int	ft_check_edges(char *name, int lines, int line_count)
{
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	line_count++;
	while (line)
	{
		if (ft_check_for_ones(line, lines, line_count))
		{
			close(fd);
			ft_printf("Error : The map must be sealed using 1s!\n");
			return (0);
		}
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (1);
		}
		line_count++;
	}
	return (1);
}

int	ft_check_characters(char *name)
{
	int		i;
	int		fd;
	char	*line;
	int		j;

	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0 * ft_printf("Error : Check the characters!\n"));
	while (line)
	{
		i = 0;
		j = ft_strlen(line);
		while (i < j)
		{
			if (!ft_check_zocep(line, i, j))
			{
				close(fd);
				return (0 * ft_printf("Error : Check the characters!\n"));
			}
			i++;
		}
		line = get_next_line(fd);
	}
	return (1);
}

int	ft_check_map(char *name, int *lc)
{
	char	**map;
	int		e_presence;

	e_presence = 0;
	*lc = ft_check_char_count(name);
	if (*lc < 3)
		return (0 * ft_printf("Error : Invalid Map!\n"));
	if (ft_check_last_line(name))
		return (0);
	if (!ft_check_edges(name, *lc, 0))
		return (0);
	if (!ft_check_characters(name))
		return (0);
	map = ft_fill_map(name, *lc);
	if (!ft_check_p_and_e(map))
		return (ft_free(map, *lc, -1));
	ft_fill_the_shit(map, ft_cloc_x(map, 'P'), ft_cloc_y(map, 'P'),
		&e_presence);
	if (ft_check_c(map, 'C') || !e_presence || ft_check_c(map, 'P'))
		return (ft_printf("Error : Invalid Map!\n") * ft_free(map, *lc, -1));
	ft_free(map, *lc, -1);
	return (1);
}
