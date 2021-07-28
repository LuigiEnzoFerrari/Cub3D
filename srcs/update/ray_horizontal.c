/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horizontal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:46:20 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/28 10:41:48 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_foundWallHoriz(t_vars vars, t_rays *rays, t_inter *a)
{
	a->intercept.y = floor(vars.player.y
			/ vars.set.tile_size) * vars.set.tile_size;
	if (rays->down)
		a->intercept.y += vars.set.tile_size;
	a->intercept.x = vars.player.x + (a->intercept.y - vars.player.y)
		/ tan(rays->rayAngle);
	a->step.y = vars.set.tile_size;
	if (rays->up)
		a->step.y = -a->step.y;
	a->step.x = vars.set.tile_size / tan(rays->rayAngle);
	if (rays->left && a->step.x > 0)
		a->step.x = -a->step.x;
	if (rays->right && a->step.x < 0)
		a->step.x = -a->step.x;
}

static void	lookingWall(t_set set, t_rays *rays, t_casting *cast, t_inter a)
{
	t_xFPoint	toCheck;

	while (a.intercept.x >= 0 && a.intercept.x <= set.resolution.w
		&& a.intercept.y >= 0 && a.intercept.y <= set.resolution.h)
	{
		toCheck.x = a.intercept.x;
		toCheck.y = a.intercept.y;
		if (rays->up)
			toCheck.y -= 1;
		if (hasWall(set.map, toCheck.x, toCheck.y, set))
		{
			cast->wallHit.x = a.intercept.x;
			cast->wallHit.y = a.intercept.y;
			cast->wallContent = set.map[(int)floor(toCheck.y
					/ set.tile_size)][(int)floor(toCheck.x / set.tile_size)];
			cast->hit = 1;
			break ;
		}
		else
		{
			a.intercept.x += a.step.x;
			a.intercept.y += a.step.y;
		}
	}
}

void	foundWallHoriz(t_vars vars, t_rays *rays, t_casting *cast)
{
	t_inter	a;

	cast->hit = 0;
	set_foundWallHoriz(vars, rays, &a);
	lookingWall(vars.set, rays, cast, a);
}
