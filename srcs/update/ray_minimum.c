/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_minimum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:45:44 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 10:26:48 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static double	distPoints(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

static void	horzGreater(t_rays *rays, t_casting *cast, t_xFPoint dist)
{
	rays->distance = dist.y;
	rays->wallHitX = cast->wallHit.x;
	rays->wallHitY = cast->wallHit.y;
	rays->wallHitContent = cast->wallContent;
	rays->wasHisVerical = 1;
}

static void	vertGreater(t_rays *rays, t_casting *cast, t_xFPoint dist)
{
	rays->distance = dist.x;
	rays->wallHitX = cast->wallHit.x;
	rays->wallHitY = cast->wallHit.y;
	rays->wallHitContent = cast->wallContent;
	rays->wasHisVerical = 0;
}

void	minimumDistance(t_vars vars, t_rays *rays, t_casting *cast)
{
	t_xFPoint	dist;

	dist.x = FLT_MAX;
	if (cast[0].hit)
		dist.x = distPoints(vars.player.x, vars.player.y,
				cast[0].wallHit.x, cast[0].wallHit.y);
	dist.y = FLT_MAX;
	if (cast[1].hit)
		dist.y = distPoints(vars.player.x, vars.player.y,
				cast[1].wallHit.x, cast[1].wallHit.y);
	if (dist.y < dist.x)
		horzGreater(rays, &cast[1], dist);
	else
		vertGreater(rays, &cast[0], dist);
}
