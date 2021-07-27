#include "cub.h"

static float	normalizeAngle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

static float	distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
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
	rayDirection(rayAngle, rays);
	t_xFPoint	intercept;
	t_xFPoint	step;

	int	foundHorzWallHit = 0;
	float horzWallHitX = 0;
	float horzWallHitY = 0;	
	int	horzWallContent = 0;


	intercept.y = floor(vars.player.y / vars.set.tile_size) * vars.set.tile_size;
	if (rays->down)
		intercept.y += vars.set.tile_size;
	intercept.x = vars.player.x + (intercept.y - vars.player.y) / tan(rayAngle);
	step.y = vars.set.tile_size;
	if (rays->up)
		step.y = -step.y;
	step.x = vars.set.tile_size / tan(rayAngle);
	if (rays->left && step.x > 0)
		step.x = -step.x;
	if (rays->right && step.x < 0)
		step.x = -step.x;

	while (intercept.x >= 0 && intercept.x <= WINDOW_WIDTH && intercept.y >= 0 && intercept.y <= WINDOW_HEIGHT)
	{
		float xToCheck = intercept.x;
		float yToCheck = intercept.y + (rays->up ? -1 : 0);

		if (hasWall(vars.set.map, xToCheck, yToCheck, vars.set))
		{
			horzWallHitX = intercept.x;
			horzWallHitY = intercept.y;
			horzWallContent = vars.set.map[(int)floor(yToCheck / vars.set.tile_size)][(int)floor(xToCheck / vars.set.tile_size)];
			foundHorzWallHit = 1;
			break ;
		}
		else
		{
			intercept.x += step.x;
			intercept.y += step.y;
		}
	}

	int	foundVertWallHit = 0;
	float vertWallHitX = 0;
	float vertWallHitY = 0;
	int	vertWallContent = 0;

	intercept.x = floor(vars.player.x / vars.set.tile_size) * vars.set.tile_size;
	if (rays->right)
		intercept.x +=vars.set.tile_size;
	intercept.y = vars.player.y + (intercept.x - vars.player.x) * tan(rayAngle);
	step.x = vars.set.tile_size;
	if (rays->left)
		step.x = -step.x;
	step.y = vars.set.tile_size * tan(rayAngle);
	if (rays->up && step.y > 0)
		step.y = -step.y;
	if (rays->down  && step.y < 0)
		step.y = -step.y;

	while (intercept.x >= 0 && intercept.x <= WINDOW_WIDTH && intercept.y >= 0 && intercept.y <= WINDOW_HEIGHT)
	{
		float xToCheck = intercept.x + (rays->left ? -1 : 0);
		float yToCheck = intercept.y;

		if (hasWall(vars.set.map, xToCheck, yToCheck, vars.set))
		{
			vertWallHitX = intercept.x;
			vertWallHitY = intercept.y;
			vertWallContent = vars.set.map[(int)floor(yToCheck / vars.set.tile_size)][(int)floor(xToCheck / vars.set.tile_size)];
			foundVertWallHit = 1;
			break ;
		}
		else
		{
			intercept.x += step.x;
			intercept.y += step.y;
		}
	}
	float horzHitDistance = foundHorzWallHit
	? distanceBetweenPoints(vars.player.x, vars.player.y, horzWallHitX, horzWallHitY) : FLT_MAX;
	float vertHitDistance = foundVertWallHit
	? distanceBetweenPoints(vars.player.x, vars.player.y, vertWallHitX, vertWallHitY) : FLT_MAX;
	if (vertHitDistance < horzHitDistance)
	{
		rays->distance = vertHitDistance;
		rays->wallHitX = vertWallHitX;
		rays->wallHitY = vertWallHitY;
		rays->wallHitContent = vertWallContent;
		rays->wasHisVerical = 1;
	}
	else
	{
		rays->distance = horzHitDistance;
		rays->wallHitX = horzWallHitX;
		rays->wallHitY = horzWallHitY;
		rays->wallHitContent = horzWallContent;
		rays->wasHisVerical = 0;
	}
	rays->rayAngle = rayAngle;
	rays->down = rays->down;
	rays->up = rays->up;
	rays->left = rays->left;
	rays->right = rays->right;
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
