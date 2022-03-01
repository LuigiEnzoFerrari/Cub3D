/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:57:17 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 12:09:14 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

double	part_one(t_vars *vars, t_xfpoint *new_position)
{
	double		move_step;

	vars->player.rotation_angle
		+= vars->player.turn_direction * vars->player.turn_step;
	vars->player.rotation_angle = normalize_angle(vars->player.rotation_angle);
	move_step = vars->player.walk_direction_fb * vars->player.walk_step;
	new_position->x = vars->player.x
		+ cos(vars->player.rotation_angle) * move_step;
	new_position->y = vars->player.y
		+ sin(vars->player.rotation_angle) * move_step;
	return (move_step);
}

void	player(t_vars *vars)
{
	t_xfpoint	new_position;
	double		move_step;

	new_position.x = 0;
	move_step = part_one(vars, &new_position);
	if (!has_wall(vars->set, new_position.x, new_position.y))
	{
		vars->player.x = new_position.x;
		vars->player.y = new_position.y;
	}
	move_step = vars->player.walk_direction_lr
		* vars->player.walk_step;
	new_position.x = vars->player.x
		+ cos(vars->player.rotation_angle + 0.5 * PI) * move_step;
	new_position.y = vars->player.y
		+ sin(vars->player.rotation_angle + 0.5 * PI) * move_step;
	if (!has_wall(vars->set, new_position.x, new_position.y))
	{
		vars->player.x = new_position.x;
		vars->player.y = new_position.y;
	}
}
