/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:53:22 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:43:37 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_found_wall_vert(t_vars vars, t_rays *rays, t_inter *a)
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

static void	looking_wall(t_set set, t_rays *rays, t_casting *cast, t_inter a)
{
	t_xfpoint	to_check;

	while (a.intercept.x >= 0 && a.intercept.x <= TILE_SIZE * set.map_size.x
		&& a.intercept.y >= 0 && a.intercept.y <= TILE_SIZE * set.map_size.y)
	{
		to_check.x = a.intercept.x;
		to_check.y = a.intercept.y;
		if (rays->left)
			to_check.x -= 1;
		if (has_wall(set, to_check.x, to_check.y))
		{
			cast->wall_hit.x = a.intercept.x;
			cast->wall_hit.y = a.intercept.y;
			cast->wall_content = set.map[(int)floor(to_check.y / TILE_SIZE)]
			[(int)floor(to_check.x / TILE_SIZE)];
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

void	found_wall_vert(t_vars vars, t_rays *rays, t_casting *cast)
{
	t_inter	a;

	cast->hit = 0;
	cast->wall_hit.x = 0;
	cast->wall_hit.y = 0;
	cast->wall_content = 0;
	set_found_wall_vert(vars, rays, &a);
	looking_wall(vars.set, rays, cast, a);
}
