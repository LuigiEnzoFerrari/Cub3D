/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:53:36 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 22:04:48 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static double	normalizeAngle(double angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

static void	rayDirection(double rayAngle, t_rays *rays)
{
	rays->angle = normalizeAngle(rayAngle);
	rays->down = rays->angle > 0 && rays->angle < PI;
	rays->up = !rays->down;
	rays->right = rays->angle < 0.5 * PI || rays->angle > 1.5 * PI;
	rays->left = !rays->right;
}

static void	rayCasting(t_vars vars, double rayAngle, t_rays *rays)
{
	t_casting	cast[2];

	rayDirection(rayAngle, rays);
	foundWallHoriz(vars, rays, &cast[0]);
	foundWallVert(vars, rays, &cast[1]);
	minimumDistance(vars, rays, cast);
}

void	raysCasting(t_vars *vars)
{
	double	angle;
	int		i;

	i = 0;
	while (i < vars->set.resolution.w)
	{
		angle = vars->player.rAngle + atan((i - (vars->set.resolution.w >> 1))
				/ vars->player.dist);
		rayCasting(*vars, angle, &vars->rays[i]);
		angle += vars->player.fov / vars->set.resolution.w;
		i++;
	}
}
