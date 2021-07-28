/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:53:36 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/28 11:53:37 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static float	normalizeAngle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

static void	rayDirection(float rayAngle, t_rays *rays)
{
	rays->rayAngle = normalizeAngle(rayAngle);
	rays->down = rays->rayAngle > 0 && rays->rayAngle < PI;
	rays->up = !rays->down;
	rays->right = rays->rayAngle < 0.5 * PI || rays->rayAngle > 1.5 * PI;
	rays->left = !rays->right;
}

static void	rayCasting(t_vars vars, float rayAngle, t_rays *rays)
{
	t_casting	cast[2];

	rayDirection(rayAngle, rays);
	foundWallHoriz(vars, rays, &cast[0]);
	foundWallVert(vars, rays, &cast[1]);
	minimumDistance(vars, rays, cast);
}

void	raysCasting(t_vars *vars)
{
	float	angle;
	size_t	i;
	
	i = 0;
	angle = vars->player.rotationAngle - (vars->player.fov / 2);
	while (i < NUM_RAY)
	{
		rayCasting(*vars, angle, &vars->rays[i]);
		angle += vars->player.fov / NUM_RAY;
		i++;
	}
}
