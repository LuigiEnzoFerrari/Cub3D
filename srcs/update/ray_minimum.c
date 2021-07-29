/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_minimum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:45:44 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 09:45:45 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static double	distPoints(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
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
	{
		rays->distance = dist.y;
		rays->wallHitX = cast[1].wallHit.x;
		rays->wallHitY = cast[1].wallHit.y;
		rays->wallHitContent = cast[1].wallContent;
		rays->wasHisVerical = 1;
	}
	else
	{
		rays->distance = dist.x;
		rays->wallHitX = cast[0].wallHit.x;
		rays->wallHitY = cast[0].wallHit.y;
		rays->wallHitContent = cast[0].wallContent;
		rays->wasHisVerical = 0;
	}
}
