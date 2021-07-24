#include "cub.h"

void	movePlayer(t_vars *vars)
{
	vars->player.rotationAngle += vars->player.turnDirection * vars->player.turnSpeed;


	float	moveStep;
	float	newPlayerX;
	float	newPlayerY;

	moveStep = vars->player.walkDirection * vars->player.walkSpeed;
	newPlayerX = vars->player.x + cos(vars->player.rotationAngle) * moveStep;
	newPlayerY = vars->player.y + sin(vars->player.rotationAngle) * moveStep;
	if (!hasWall(vars->set.map, newPlayerX, newPlayerY))
	{
		vars->player.x = newPlayerX;
		vars->player.y = newPlayerY;
	}

}
