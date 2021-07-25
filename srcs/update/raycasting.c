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

void	rayCasting(t_P1 player, char **map, float rayAngle, int i, t_rays *rays)
{
	rayAngle = normalizeAngle(rayAngle);

	rays[i].down = rayAngle > 0 && rayAngle < PI;
	rays[i].up = !rays[i].down;
	rays[i].right = rayAngle < 0.5 * PI || rayAngle > 1.5 * PI;
	rays[i].left = !rays[i].right;

	float xintercept, yintercept;
	float xstep, ystep;

	int	foundHorzWallHit = 0;
	float horzWallHitX = 0;
	float horzWallHitY = 0;	
	int	horzWallContent = 0;

	yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
	yintercept += rays[i].down ? TILE_SIZE : 0;

	xintercept = player.x + (yintercept -player.y) / tan(rayAngle);

	ystep = TILE_SIZE;
	ystep *= rays[i].up ? -1 : 1;

	xstep = TILE_SIZE / tan(rayAngle);
	xstep *= (rays[i].left && xstep > 0) ? -1 : 1;
	xstep *= (rays[i].right && xstep < 0) ? -1 : 1;

	float nextHorzTouchX = xintercept;
	float nextHorzTouchY = yintercept;

	while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH && nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT)
	{
		float xToCheck = nextHorzTouchX;
		float yToCheck = nextHorzTouchY + (rays[i].up ? -1 : 0);

		if (hasWall(map, xToCheck, yToCheck))
		{
			horzWallHitX = nextHorzTouchX;
			horzWallHitY = nextHorzTouchY;
			horzWallContent = map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
			foundHorzWallHit = 1;
			break ;
		} else
		{
			nextHorzTouchX += xstep;
			nextHorzTouchY += ystep;
		}
	}

	int	foundVertWallHit = 0;
	float vertWallHitX = 0;
	float vertWallHitY = 0;	
	int	vertWallContent = 0;

	xintercept = floor(player.x / TILE_SIZE) * TILE_SIZE;
	xintercept += rays[i].right ? TILE_SIZE : 0;

	yintercept = player.y + (xintercept - player.x) * tan(rayAngle);

	xstep = TILE_SIZE;
	xstep *= rays[i].left ? -1 : 1;

	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= (rays[i].up && ystep > 0) ? -1 : 1;
	ystep *= (rays[i].down  && ystep < 0) ? -1 : 1;

	float nextVertTouchX = xintercept;
	float nextVertTouchY = yintercept;

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
			nextVertTouchX += xstep;
			nextVertTouchY += ystep;
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
