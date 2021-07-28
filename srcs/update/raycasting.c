#include "cub.h"

static float	normalizeAngle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

void	rayDirection(float rayAngle, t_rays *rays)
{
	rayAngle = normalizeAngle(rayAngle);
	rays->down = rayAngle > 0 && rayAngle < PI;
	rays->up = !rays->down;
	rays->right = rayAngle < 0.5 * PI || rayAngle > 1.5 * PI;
	rays->left = !rays->right;
}

void	rayCasting(t_vars vars, float rayAngle, t_rays *rays)
{
	t_casting	cast[2];

	rayDirection(rayAngle, rays);
	foundtWallHoriz(vars, rays, rayAngle, &cast[0]);
	foundWallVert(vars, rays, rayAngle, &cast[1]);
	minimumDistance(vars, rays, rayAngle, cast);
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
