/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:32:26 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 10:32:27 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	map_column_aux(char **map, size_t x, size_t y)
{
	while (map[y][x] == ' ')
		y++;
	if (map[y][x] != '1')
		return (0);
	while (map[y])
	{
		if (!map[y + 1])
			break ;
		if (map[y + 1][x] == ' ')
		{
			if (map[y][x] != '1')
				return (0);
			y++;
			while (map[y][x] == ' ')
			{
				y++;
				if (!map[y])
					return (1);
			}
			if (map[y][x] != '1')
				return (0);
		}
		y++;
	}
	return (1);
}

int	map_column(char **map)
{
	size_t	x;

	x = 0;
	while (*((*map) + x))
	{
		if (!map_column_aux(map, x, 0))
			return (0);
		x++;
	}
	return (1);
}
