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
	float	moveStep;
	float	newPlayerX;
	float	newPlayerY;

	vars->player.rotationAngle += vars->player.turnDirection * vars->player.turnSpeed;
	vars->player.rotationAngle = normalizeAngle(vars->player.rotationAngle);
	moveStep = vars->player.walkDirection * vars->player.walkSpeed;
	newPlayerX = vars->player.x + cos(vars->player.rotationAngle) * moveStep;
	newPlayerY = vars->player.y + sin(vars->player.rotationAngle) * moveStep;
	if (!hasWall(vars->set.map, newPlayerX, newPlayerY))
	{
		vars->player.x = newPlayerX;
		vars->player.y = newPlayerY;
	}
	moveStep = vars->player.walkDirectiontwo * vars->player.walkSpeed;
	newPlayerX = vars->player.x + cos(vars->player.rotationAngle + 0.5 * PI) * moveStep;
	newPlayerY = vars->player.y + sin(vars->player.rotationAngle + 0.5 * PI) * moveStep;
	if (!hasWall(vars->set.map, newPlayerX, newPlayerY))
	{
		vars->player.x = newPlayerX;
		vars->player.y = newPlayerY;
	}
}
