/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:53:22 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 13:31:23 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_foundWallVert(t_vars vars, t_rays *rays, t_inter *a)
{
	a->intercept.x = floor(vars.player.x / TILE_SIZE) * TILE_SIZE;
	if (rays->right)
		a->intercept.x += TILE_SIZE;
	a->intercept.y = vars.player.y + (a->intercept.x - vars.player.x)
		* tan(rays->angle);
	a->step.x = TILE_SIZE;
	if (rays->left)
		a->step.x = -a->step.x;
	a->step.y = TILE_SIZE * tan(rays->angle);
	if (rays->up && a->step.y > 0)
		a->step.y = -a->step.y;
	if (rays->down && a->step.y < 0)
		a->step.y = -a->step.y;
}

static void	lookingWall(t_set set, t_rays *rays, t_casting *cast, t_inter a)
{
	t_xFPoint	toCheck;

	while (a.intercept.x >= 0 && a.intercept.x <= TILE_SIZE * set.map_size.x
		&& a.intercept.y >= 0 && a.intercept.y <= TILE_SIZE * set.map_size.y)
	{
		toCheck.x = a.intercept.x;
		toCheck.y = a.intercept.y;
		if (rays->left)
			toCheck.x -= 1;
		if (hasWall(set.map, toCheck.x, toCheck.y))
		{
			cast->wallHit.x = a.intercept.x;
			cast->wallHit.y = a.intercept.y;
			cast->wallContent = set.map[(int)floor(toCheck.y / TILE_SIZE)]
			[(int)floor(toCheck.x / TILE_SIZE)];
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

void	foundWallVert(t_vars vars, t_rays *rays, t_casting *cast)
{
	t_inter	a;

	cast->hit = 0;
	cast->wallHit.x = 0;
	cast->wallHit.y = 0;
	cast->wallContent = 0;
	set_foundWallVert(vars, rays, &a);
	lookingWall(vars.set, rays, cast, a);
}
