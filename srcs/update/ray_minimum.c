/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_minimum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:45:44 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:40:23 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static double	dist_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

static void	horz_greater(t_rays *rays, t_casting *cast, t_xfpoint dist)
{
	rays->distance = dist.y;
	rays->wall_hit_x = cast->wall_hit.x;
	rays->wall_hit_y = cast->wall_hit.y;
	rays->wall_hit_content = cast->wall_content;
	rays->is_vert = 1;
}

static void	vert_greater(t_rays *rays, t_casting *cast, t_xfpoint dist)
{
	rays->distance = dist.x;
	rays->wall_hit_x = cast->wall_hit.x;
	rays->wall_hit_y = cast->wall_hit.y;
	rays->wall_hit_content = cast->wall_content;
	rays->is_vert = 0;
}

void	minimum_distance(t_vars vars, t_rays *rays, t_casting *cast)
{
	t_xfpoint	dist;

	dist.x = FLT_MAX;
	if (cast[0].hit)
		dist.x = dist_points(vars.player.x, vars.player.y,
				cast[0].wall_hit.x, cast[0].wall_hit.y);
	dist.y = FLT_MAX;
	if (cast[1].hit)
		dist.y = dist_points(vars.player.x, vars.player.y,
				cast[1].wall_hit.x, cast[1].wall_hit.y);
	if (dist.y < dist.x)
		horz_greater(rays, &cast[1], dist);
	else
		vert_greater(rays, &cast[0], dist);
}
