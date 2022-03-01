/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:05:19 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:44:49 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_wall(int c)
{
	return (c == '1' || c == ' ');
}

int	has_wall(t_set set, double x, double y)
{
	uint32_t	gx;
	uint32_t	gy;

	if (x < 0 || x > set.map_size.x * TILE_SIZE
		|| y < 0 || y > set.map_size.y * TILE_SIZE)
		return (1);
	gx = floor(x / TILE_SIZE);
	gy = floor(y / TILE_SIZE);
	return (is_wall(set.map[gy][gx]));
}
