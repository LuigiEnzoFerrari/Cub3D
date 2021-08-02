/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:32:22 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 20:20:20 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_line(char *map_line)
{
	while (*map_line == ' ')
		map_line++;
	while (*map_line)
	{
		if (map_line[1] == ' ')
		{
			if (*map_line++ != '1')
				return (0);
			while (*map_line == ' ')
				map_line++;
			if (*map_line == '\0')
				return (1);
			else if (*map_line != '1')
				return (0);
		}
		if (map_line[1] == '\0' && *map_line != '1')
			return (0);
		map_line++;
	}
	return (1);
}

int	hasWhiteColomns(char **str)
{
	size_t	i;

	i = 0;
	while (!iswhite(str, i))
	{
		if (*(*str + i) == '\0')
			return (0);
		i++;
	}
	return (1);
}
