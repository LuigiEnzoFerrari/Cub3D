/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:57:17 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/28 11:19:11 by lenzo-pe         ###   ########.fr       */
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

void	movePlayer(t_vars *vars)
{
	t_xFPoint	newPlayer;
	float		moveStep;

	vars->player.rotationAngle += vars->player.turnDirection * vars->player.turnSpeed;
	vars->player.rotationAngle = normalizeAngle(vars->player.rotationAngle);
	moveStep = vars->player.walkDirection * vars->player.walkSpeed;
	newPlayer.x = vars->player.x + cos(vars->player.rotationAngle) * moveStep;
	newPlayer.y = vars->player.y + sin(vars->player.rotationAngle) * moveStep;
	if (!hasWall(vars->set.map, newPlayer.x, newPlayer.y, vars->set))
	{
		vars->player.x = newPlayer.x;
		vars->player.y = newPlayer.y;
	}
	moveStep = vars->player.walkDirectiontwo * vars->player.walkSpeed;
	newPlayer.x = vars->player.x + cos(vars->player.rotationAngle + 0.5 * PI) * moveStep;
	newPlayer.y = vars->player.y + sin(vars->player.rotationAngle + 0.5 * PI) * moveStep;
	if (newPlayer.x != newPlayer.x)
		newPlayer.x = 0;
	if (newPlayer.y != newPlayer.y)
		newPlayer.y = 0;
	if (!hasWall(vars->set.map, newPlayer.x, newPlayer.y, vars->set))
	{
		vars->player.x = newPlayer.x;
		vars->player.y = newPlayer.y;
	}
}
