/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:57:17 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 10:01:02 by lenzo-pe         ###   ########.fr       */
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

void	player(t_vars *vars)
{
	t_xFPoint	newPlayer;
	double		moveStep;

	vars->player.rAngle += vars->player.turnDirection
		* vars->player.turnSpeed;
	vars->player.rAngle = normalizeAngle(vars->player.rAngle);
	moveStep = vars->player.walkDirection * vars->player.walkSpeed;
	newPlayer.x = vars->player.x + cos(vars->player.rAngle) * moveStep;
	newPlayer.y = vars->player.y + sin(vars->player.rAngle) * moveStep;
	if (!hasWall(vars->set.map, newPlayer.x, newPlayer.y))
	{
		vars->player.x = newPlayer.x;
		vars->player.y = newPlayer.y;
	}
	moveStep = vars->player.walkDirectiontwo * vars->player.walkSpeed;
	newPlayer.x = vars->player.x + cos(vars->player.rAngle + 0.5 * PI)
		* moveStep;
	newPlayer.y = vars->player.y + sin(vars->player.rAngle + 0.5 * PI)
		* moveStep;
	if (!hasWall(vars->set.map, newPlayer.x, newPlayer.y))
	{
		vars->player.x = newPlayer.x;
		vars->player.y = newPlayer.y;
	}
}
