/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FillMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:03:26 by agoujdam          #+#    #+#             */
/*   Updated: 2023/05/02 20:55:20 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free(char **map, int line_count, int fd)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		free(map[i]);
		i++;
	}
	free(map);
	close(fd);
	return (0);
}

char	**ft_fill_map(char *name, int line_count)
{
	char	**map;
	int		i;
	int		fd;

	map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (0);
	i = 0;
	fd = open(name, O_RDONLY, 777);
	while (i < line_count)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			ft_free(map, line_count, fd);
			ft_printf("Error : Check the characters!\n");
			return (0);
		}
		i++;
	}
	map[line_count] = 0;
	close(fd);
	return (map);
}

int	ft_check_c(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == c)
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}

int	ft_check_p_and_e(char **map)
{
	int	p_count;
	int	e_count;
	int	c_count;

	p_count = ft_check_c(map, 'P');
	e_count = ft_check_c(map, 'E');
	c_count = ft_check_c(map, 'C');
	if (p_count != 1)
		return (0 * ft_printf("Error : There are more than 2 or no players!\n"));
	if (e_count != 1)
		return (0 * ft_printf("Error : There are more than 2 or no exits!\n"));
	if (c_count == 0)
		return (0 * ft_printf("Error : No Collectibles in Map!\n"));
	else
		return (1);
}

/*void	printCharMap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n");
}
*/
void	ft_fill_the_shit(char **map, int x, int y, int *e_presence)
{
	if (y < 0 || y > ft_strline(map))
		return ;
	if (x < 0 || x > ft_strlen_no_nw(map[y]))
		return ;
	if (map[y][x] != 'C' && map[y][x] != '0' && map[y][x] != 'P'
		&& map[y][x] != 'E')
		return ;
	if (map[y][x] == 'E')
	{
		*e_presence = 1;
		return ;
	}
	map[y][x] = 'K';
	ft_fill_the_shit(map, x - 1, y, e_presence);
	ft_fill_the_shit(map, x + 1, y, e_presence);
	ft_fill_the_shit(map, x, y - 1, e_presence);
	ft_fill_the_shit(map, x, y + 1, e_presence);
}
