/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:53:36 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 13:35:02 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static double	normalize_angle(double angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

static void	ray_direction(double ray_angle, t_rays *rays)
{
	rays->angle = normalize_angle(ray_angle);
	rays->down = (rays->angle > 0 && rays->angle < PI);
	rays->up = !rays->down;
	rays->right = (rays->angle < 0.5 * PI || rays->angle > 1.5 * PI);
	rays->left = !rays->right;
}

static void	ray_casting(t_vars vars, double ray_angle, t_rays *rays)
{
	t_casting	cast[2];

	ray_direction(ray_angle, rays);
	found_wall_horiz(vars, rays, &cast[0]);
	found_wall_vert(vars, rays, &cast[1]);
	minimum_distance(vars, rays, cast);
}

void	rays_casting(t_vars *vars)
{
	double	angle;
	int		i;

	i = 0;
	while (i < vars->set.resolution.w)
	{
		angle = vars->player.rotation_angle
			+ atan((i - (vars->set.resolution.w >> 1)) / vars->player.dist);
		ray_casting(*vars, angle, &vars->rays[i]);
		angle += vars->player.fov / vars->set.resolution.w;
		i++;
	}
}
