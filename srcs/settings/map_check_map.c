/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:32:18 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:58:11 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	map_lines(char **map)
{
	while (*map)
	{
		if (!map_line(*map))
			return (0);
		map++;
	}
	return (1);
}

int	closing(char **map, size_t a)
{
	size_t	i;
	char	**ptr;

	i = 0;
	while (*(*(map + i) + a) == ' ')
		i++;
	if (*(*(map + i) + a) != '1')
		return (0);
	ptr = (map + i);
	i++;
	while (*(map + i))
	{
		if (*(*(map + i) + a) == '1')
			ptr = (map + i);
		i++;
	}
	ptr++;
	while (*ptr)
	{
		if (*((*ptr) + a) != ' ')
			return (0);
		ptr++;
	}
	return (1);
}

int	is_close(char **map)
{
	size_t	a;

	a = 0;
	while (*((*map) + a))
	{
		if (!closing(map, a))
			return (0);
		a++;
	}
	return (1);
}

static int	map_colomns(char **map)
{
	if (has_white_colomns(map))
	{
		ft_putendl_fd("Splited Map", 0);
		return (0);
	}
	if (!is_close(map))
	{
		ft_putendl_fd("Invalid Map", 0);
		return (0);
	}
	if (!map_column(map))
	{
		ft_putendl_fd("Must be close by walls", 0);
		return (0);
	}
	return (1);
}

void	check_map(t_sval *val, int fd)
{
	if (!map_lines(val->set.map))
	{
		val->str = NULL;
		ft_putendl_fd("Must be close by walls", 0);
		exit_elements(val, fd);
	}
	if (!map_colomns(val->set.map))
	{
		val->str = NULL;
		exit_elements(val, fd);
	}
}
