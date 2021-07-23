#include "cub.h"




t_rays rays;



int	hasWall(char **map, float x, float y)
{
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return 1;
	int indexGridX = floor(x / TILE_SIZE);
	int indexGridY = floor(y / TILE_SIZE);
	return map[indexGridY][indexGridX] != '0';
}

void	movePlayer(t_vars *vars)
{
	vars->player.rotationAngle += vars->player.turnDirection * vars->player.turnSpeed;
	float	moveStep = vars->player.walkDirection * vars->player.walkSpeed;
	float	newPlayerX = vars->player.x + cos(vars->player.rotationAngle) * moveStep;
	float	newPlayerY = vars->player.y + sin(vars->player.rotationAngle) * moveStep;
	if (!hasWall(vars->set.map, newPlayerX, newPlayerY))
	{
		vars->player.x = newPlayerX;
		vars->player.y = newPlayerY;
	}

}

void	renderPlayer(t_vars *vars)
{
	mlx_set_render_color(&vars->renderer, 0x00ffffff);
	mlx_draw_fill_rect(&vars->renderer,
	mlx_get_rect(vars->player.x * MINIMAP_SCALE,
				vars->player.y * MINIMAP_SCALE,
				vars->player.w * MINIMAP_SCALE,
				vars->player.h * MINIMAP_SCALE));

	mlx_draw_line(&vars->renderer,
	mlx_get_line(MINIMAP_SCALE * vars->player.x,
				MINIMAP_SCALE * vars->player.y,
				MINIMAP_SCALE * vars->player.x + cos(vars->player.rotationAngle) * 40,
				MINIMAP_SCALE * vars->player.y + sin(vars->player.rotationAngle) * 40));
}

float	normalizeAngle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

float	distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	castRay(t_P1 player, char **map, float rayAngle, int stripId)
{
	rayAngle = normalizeAngle(rayAngle);

	int	isRayFacingDown = rayAngle > 0 && rayAngle < PI;
	int	isRayFacingUp = !isRayFacingDown;
	int	isRayFacingRight = rayAngle <  0.5 * PI || rayAngle > 1.5 * PI;
	int isRayFacingLeft = !isRayFacingRight;

	float xintercept, yintercept;
	float xstep, ystep;

	int	foundHorzWallHit = 0;
	float horzWallHitX = 0;
	float horzWallHitY = 0;	
	int	horzWallContent = 0;

	yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
	yintercept += isRayFacingDown ? TILE_SIZE : 0;

	xintercept = player.x + (yintercept -player.y) / tan(rayAngle);

	ystep = TILE_SIZE;
	ystep *= isRayFacingUp ? -1 : 1;

	xstep = TILE_SIZE / tan(rayAngle);
	xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
	xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

	float nextHorzTouchX = xintercept;
	float nextHorzTouchY = yintercept;

	while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH && nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT)
	{
		float xToCheck = nextHorzTouchX;
		float yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);

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
	xintercept += isRayFacingRight ? TILE_SIZE : 0;

	yintercept = player.y + (xintercept - player.x) * tan(rayAngle);

	xstep = TILE_SIZE;
	xstep *= isRayFacingLeft ? -1 : 1;

	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= (isRayFacingUp && ystep > 0) ? -1 : 1;
	ystep *= (isRayFacingDown  && ystep < 0) ? -1 : 1;

	float nextVertTouchX = xintercept;
	float nextVertTouchY = yintercept;

	while (nextVertTouchX >= 0 && nextVertTouchX <= WINDOW_WIDTH && nextVertTouchY >= 0 && nextVertTouchY <= WINDOW_HEIGHT)
	{
		float xToCheck = nextVertTouchX + (isRayFacingLeft ? -1 : 0);
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
		float horzHitDinstance = foundHorzWallHit
		? distanceBetweenPoints(player.x, player.y, horzWallHitX, horzWallHitY) : FLT_MAX;
		float vertHitDinstance = foundVertWallHit
		? distanceBetweenPoints(player.x, player.y, vertWallHitX, vertWallHitY) : FLT_MAX;
		if (vertHitDinstance < horzHitDinstance)
		{
			rays[stripId].distance = vertHitDinstance;
			rays[stripId].wallHitX = vertWallHitX;
			rays[stripId].wallHitY = vertWallHitY;
			rays[stripId].wallHitContent = vertWallContent;
			rays[stripId].wasHisVerical = 1;
		}
		else
		{
			rays[stripId].distance = horzHitDinstance;
			rays[stripId].wallHitX = horzWallHitX;
			rays[stripId].wallHitY = horzWallHitY;
			rays[stripId].wallHitContent = horzWallContent;
			rays[stripId].wasHisVerical = 0;
		}
		rays[stripId].rayAngle = rayAngle;
		rays[stripId].isRayFacingDown = isRayFacingDown;
		rays[stripId].isRayFacingUp = isRayFacingUp;
		rays[stripId].isRayFacingLeft = isRayFacingLeft;
		rays[stripId].isRayFacingRight = isRayFacingRight;
}

void	castAllRays(t_P1 player, char **map)
{
	float rayAngle = player.rotationAngle - (FOV_ANGLE / 2);
	for (int stripId = 0; stripId < NUM_RAY; stripId++)
	{
		castRay(player, map, rayAngle, stripId);
		rayAngle += FOV_ANGLE / NUM_RAY;
	}
}

void	renderRays(t_vars *vars)
{
	mlx_set_render_color(&vars->renderer, 0x00ff0000);
	for (int i = 0; i < NUM_RAY; i++)
	{
		mlx_draw_line(&vars->renderer,
		mlx_get_line(
			MINIMAP_SCALE * vars->player.x,
			MINIMAP_SCALE * vars->player.y, 
			MINIMAP_SCALE * rays[i].wallHitX,
			MINIMAP_SCALE * rays[i].wallHitY));
	}
}

void	update(t_vars *vars)
{
	movePlayer(vars);
	castAllRays(vars->player, vars->set.map);
}

void	render(t_vars *vars)
{
	renderMap(&vars->renderer, vars->set.map);
	renderPlayer(vars);
	renderRays(vars);
}

int	main(void)
{
	t_vars vars;

	init_all(&vars);
	update(&vars);
	render(&vars);
	input(&vars);
	mlx_put_image_to_window(vars.mlx,
					vars.window,
					vars.renderer.img,
					0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
