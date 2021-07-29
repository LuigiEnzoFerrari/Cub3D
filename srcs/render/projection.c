/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:00:29 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 15:36:34 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drawWallLine(t_xRenderer *renderer, t_xPoint res, int bottom)
{
	while (res.y < bottom)
	{
		mlx_put_pixel(renderer, res.x, res.y);
		res.y++;
	}
}

void	projection(t_vars *vars, t_rays *rays, t_P1 player, t_set set)
{
	t_proj		a;
	t_xPoint	res;

	res.x = 0;
	mlx_set_render_color(&vars->renderer, 0x00131313);
	while (res.x < set.resolution.w)
	{
		a.perDistance = rays[res.x].distance
			* cos(rays[res.x].angle - player.rAngle);
		a.projDistance = (set.resolution.w >> 1) / tan(player.fov / 2);
		a.projHeight = (TILE_SIZE / a.perDistance) * a.projDistance;
		a.stripHeight = (int)a.projHeight;
		a.topPixel = (set.resolution.h >> 1) - (a.stripHeight >> 1);
		if (a.topPixel < 0)
			a.topPixel = 0;
		a.bottomPixel = (set.resolution.h >> 1) + (a.stripHeight >> 1);
		if (a.bottomPixel > set.resolution.h)
			a.bottomPixel = set.resolution.h;
		res.y = a.topPixel;
		drawWallLine(&vars->renderer, res, a.bottomPixel);
		res.x++;
	}
}
