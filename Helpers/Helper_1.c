/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:30:40 by agoujdam          #+#    #+#             */
/*   Updated: 2023/05/02 20:42:02 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen_no_nw(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			j++;
		i++;
	}
	return (i - j);
}

int	ft_check_for_ones(char *line, int lines, int line_count)
{
	int	i;
	int	j;
	int	return_value;

	i = 0;
	j = ft_strlen_no_nw(line);
	return_value = 0;
	if (line_count == 1 || lines == line_count)
	{
		while (i < j)
		{
			if (line[i] != '1')
				return_value = 1;
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[ft_strlen_no_nw(line) - 1] != '1')
			return_value = 1;
	}
	free(line);
	return (return_value);
}

int	ft_check_zocep(char *line, int i, int j)
{
	if (line[i] != 'P' && line[i] != 'C' && line[i] != '0' && line[i] != '1'
		&& line[i] != 'E' && line[i] > ' ')
	{
		free(line);
		return (0);
	}
	else if (i == j - 1)
		free(line);
	return (1);
}

void	ft_negative_fd(char *str, int fd)
{
	if (fd < 0)
	{
		close(fd);
		ft_printf("Error : No File %s!\n", str);
		exit(0);
	}
}
