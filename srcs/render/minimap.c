/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:21:33 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 15:37:08 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_tile_color(t_xRenderer *renderer, char c)
{
	if (c == '1')
		mlx_set_render_color(renderer, 0x00ffffff);
	else
		mlx_set_render_color(renderer, 0x00000000);
}

static void	paintRow(t_xRenderer *renderer, char *map, int y)
{
	size_t	i;
	int		x;

	x = 0;
	i = 0;
	y *= TILE_SIZE;
	while (*(map + i))
	{
		if (*(map + i) == ' ')
		{
			i++;
			continue ;
		}
		x = i * TILE_SIZE;
		set_tile_color(renderer, *(map + i));
		mlx_draw_fill_rect(renderer,
			mlx_get_rect(x * MINIMAP_SCALE,
				y * MINIMAP_SCALE,
				TILE_SIZE * MINIMAP_SCALE,
				TILE_SIZE * MINIMAP_SCALE));
		x++;
		i++;
	}
}

void	minimap(t_xRenderer *renderer, char **map, t_set set)
{
	int	y;

	y = 0;
	set.map_size.x = 0;
	while (*(map + y))
	{
		paintRow(renderer, *(map + y), y);
		y++;
	}
}
