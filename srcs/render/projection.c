/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:00:29 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 10:01:38 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	projection(t_vars *vars, t_rays *rays, t_P1 player, t_set set)
{
	double	perpDistance;
	double	distanceProjPlane;
	double	projectedWallHeight;
	int		i;
	int		y;
	int		wallStripHeight;
	int		wallTopPixel;
	int		wallBottomPixel;

	i = 0;
	mlx_set_render_color(&vars->renderer, 0x00131313);
	while (i < set.resolution.w)
	{
		perpDistance = rays[i].distance
			* cos(rays[i].rayAngle - player.rAngle);
		distanceProjPlane = (set.resolution.w >> 1) / tan(player.fov / 2);
		projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;

		wallStripHeight = (int)projectedWallHeight;

		wallTopPixel = (set.resolution.h >> 1) - (wallStripHeight >> 1);
		if (wallTopPixel < 0)
			wallTopPixel = 0;
		wallBottomPixel = (set.resolution.h >> 1) + (wallStripHeight >> 1);
		if (wallBottomPixel > set.resolution.h)
			wallBottomPixel = set.resolution.h;
		y = wallTopPixel;
		while (y < wallBottomPixel)
		{
			mlx_put_pixel(&vars->renderer, i, y);
			y++;
		}
		i++;
	}
}
