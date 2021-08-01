/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:57:17 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/31 21:47:05 by lenzo-pe         ###   ########.fr       */
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
	t_xFPoint	newP;
	double		moveStep;

	vars->player.rAngle += vars->player.tD * vars->player.tS;
	vars->player.rAngle = normalizeAngle(vars->player.rAngle);
	moveStep = vars->player.wDFB * vars->player.wS;
	newP.x = vars->player.x + cos(vars->player.rAngle) * moveStep;
	newP.y = vars->player.y + sin(vars->player.rAngle) * moveStep;
	if (!hasWall(vars->set, newP.x, newP.y))
	{
		vars->player.x = newP.x;
		vars->player.y = newP.y;
	}
	moveStep = vars->player.wDLR * vars->player.wS;
	newP.x = vars->player.x + cos(vars->player.rAngle + 0.5 * PI) * moveStep;
	newP.y = vars->player.y + sin(vars->player.rAngle + 0.5 * PI) * moveStep;
	if (!hasWall(vars->set, newP.x, newP.y))
	{
		vars->player.x = newP.x;
		vars->player.y = newP.y;
	}
}
