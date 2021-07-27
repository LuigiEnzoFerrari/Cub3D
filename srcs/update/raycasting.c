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

void	rayCasting(t_P1 player, char **map, float rayAngle, int i, t_rays *rays)
{
	t_xFPoint	intercept;
	t_xFPoint	step;

	int	foundHorzWallHit = 0;
	float horzWallHitX = 0;
	float horzWallHitY = 0;	
	int	horzWallContent = 0;

	rayDirection(rayAngle, &rays[i]);
	intercept.y = floor(player.y / TILE_SIZE) * TILE_SIZE;
	if (rays[i].down)
		intercept.y += TILE_SIZE;
	intercept.x = player.x + (intercept.y - player.y) / tan(rayAngle);

	step.y = TILE_SIZE;
	if (rays[i].up)
		step.y = -step.y;
	step.x = TILE_SIZE / tan(rayAngle);
	if (rays[i].left && step.x > 0)
		step.x = -step.x;
	if (rays[i].right && step.x < 0)
		step.x = -step.x;
	// step.x *= (rays[i].left && step.x > 0) ? -1 : 1;
	// step.x *= (rays[i].right && step.x < 0) ? -1 : 1;

	// float nextHorzTouchX = intercept.x;
	// float nextHorzTouchY = intercept.y;

	while (intercept.x >= 0 && intercept.x <= WINDOW_WIDTH && intercept.y >= 0 && intercept.y <= WINDOW_HEIGHT)
	{
		float xToCheck = intercept.x;
		float yToCheck = intercept.y + (rays[i].up ? -1 : 0);

		if (hasWall(map, xToCheck, yToCheck))
		{
			horzWallHitX = intercept.x;
			horzWallHitY = intercept.y;
			horzWallContent = map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
			foundHorzWallHit = 1;
			break ;
		} else
		{
			intercept.x += step.x;
			intercept.y += step.y;
		}
	}

	int	foundVertWallHit = 0;
	float vertWallHitX = 0;
	float vertWallHitY = 0;
	int	vertWallContent = 0;

	intercept.x = floor(player.x / TILE_SIZE) * TILE_SIZE;
	if (rays[i].right)
		intercept.x +=TILE_SIZE;
	intercept.y = player.y + (intercept.x - player.x) * tan(rayAngle);

	step.x = TILE_SIZE;
	if (rays[i].left)
		step.x = -step.x;
	step.y = TILE_SIZE * tan(rayAngle);
	if (rays[i].up && step.y > 0)
		step.y = -step.y;
	if (rays[i].down  && step.y < 0)
		step.y = -step.y;
	// step.y *= (rays[i].up && step.y > 0) ? -1 : 1;
	// step.y *= (rays[i].down  && step.y < 0) ? -1 : 1;

	float nextVertTouchX = intercept.x;
	float nextVertTouchY = intercept.y;

	while (nextVertTouchX >= 0 && nextVertTouchX <= WINDOW_WIDTH && nextVertTouchY >= 0 && nextVertTouchY <= WINDOW_HEIGHT)
	{
		float xToCheck = nextVertTouchX + (rays[i].left ? -1 : 0);
		float yToCheck = nextVertTouchY;

		if (hasWall(map, xToCheck, yToCheck))
		{
			vertWallHitX = nextVertTouchX;
			vertWallHitY = nextVertTouchY;
			vertWallContent = map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
			foundVertWallHit = 1;
			break ;
		}
		else
		{
			nextVertTouchX += step.x;
			nextVertTouchY += step.y;
		}
	}
	float horzHitDistance = foundHorzWallHit
	? distanceBetweenPoints(player.x, player.y, horzWallHitX, horzWallHitY) : FLT_MAX;
	float vertHitDistance = foundVertWallHit
	? distanceBetweenPoints(player.x, player.y, vertWallHitX, vertWallHitY) : FLT_MAX;
	if (vertHitDistance < horzHitDistance)
	{
		rays[i].distance = vertHitDistance;
		rays[i].wallHitX = vertWallHitX;
		rays[i].wallHitY = vertWallHitY;
		rays[i].wallHitContent = vertWallContent;
		rays[i].wasHisVerical = 1;
	}
	else
	{
		rays[i].distance = horzHitDistance;
		rays[i].wallHitX = horzWallHitX;
		rays[i].wallHitY = horzWallHitY;
		rays[i].wallHitContent = horzWallContent;
		rays[i].wasHisVerical = 0;
	}
	rays[i].rayAngle = rayAngle;
	rays[i].down = rays[i].down;
	rays[i].up = rays[i].up;
	rays[i].left = rays[i].left;
	rays[i].right = rays[i].right;
}
