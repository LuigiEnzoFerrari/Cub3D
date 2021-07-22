#include "cub.h"

void	renderPlayer(t_vars *vars)
{
	mlx_set_render_color(&vars->renderer, 0x00ff0000);
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

void	render(t_vars *vars)
{
	renderMap(&vars->renderer, vars->set.map);
	renderPlayer(vars);
}

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

// int remainderderf(int a, int b)
// {
// 	return (a % b);
// }

// float normalizeAngle(float angle)
// {
// 	angle = remainder(angle, TWO_PI);
// 	if (angle < 0)
// 		angle += TWO_PI;
// 	return (angle);
// }

// void	castRay(float rayAngle, int stripId)
// {
// 	rayAngle = normalizeAngle(rayAngle);

// 	int	isRayFacingDown = rayAngle > 0 && rayAngle < PI;
// 	int	isRayFacingUp = !isRayFacingDown;
// 	int	isRayFacingRight = rayAngle <  0.5 * PI || rayAngle > 1.5 * PI;
// 	int isRayFacingLeft = !isRayFacingRight;

// 	float xintercept, yintercept;
// 	float xstep, ystep;

// 	int	foundHorzWallHit = 0;
// 	float horzWallHitX = 0;
// 	float horzWallHitY = 0;	
// 	int	horzWallContent = 0;

// 	yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
// 	yintercept += isRayFacingDown ? TILE_SIZE : 0;

// 	xintercept = player.x + (yintercept -player.y) / tan(rayAngle);

// 	ystep = TILE_SIZE;
// 	ystep *= isRayFacingUp ? -1 : 1;

// 	xstep = TILE_SIZE / tan(rayAngle);
// 	xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
// 	xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

// 	float nextHorizTouchX = xintercept;
// 	float nextHorizTouchY = yintercept;

// 	while (nextHorizTouchX >= 0 && nextHorizTouchX <= WINDOW_WIDTH && nextHorizTouchY >= 0 && nextHorizTouchY <= WINDOW_HEIGHT)
// 	{
// 		float xToCheck = nextHorizTouchX;
// 		float yTocheck = nextHorizTouchY + (isRayFacingUp ? -1 : 0);

// 		if (mapHasWallAt(xToCheck, yTocheck))
// 		{
// 			horzWallHitX = nextHorizTouchX;
// 			horzWallHitY = nextHorizTouchY;
// 			horzWallContent = map[yTocheck / TILE_SIZE][x];
// 			foundHorzWallHit = 1;
// 		} else
// 		{
// 			nextHorizTouchY += ystep;
// 			nextHorizTouchX += xstep;
// 		}
// 	}
// }

// void	castAllRays()
// {
// 	float rayAngle = player.rotationAngle - (FOV_ANGLE / 2);
// 	for (int stripId = 0; stripId < NUM_RAY; stripId++)
// 	{
// 		castRay(rayAngle, stripId);
// 		rayAngle += FOV_ANGLE / NUM_RAY;
// 	}
// }

void	update(t_vars *vars)
{
	movePlayer(vars);
	// castAllRays();
}

void	setup(t_P1 *player)
{
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->w = 20;
	player->h = 20;
	player->walkDirection = 0;
	player->turnDirection = 0;
	player->turnSpeed = 30 * (PI / 180);
	player->walkSpeed = 5;
	player->rotationAngle = PI / 2;
}

void	free_set(t_set *set)
{
	free(set->tex.east);
	free(set->tex.west);
	free(set->tex.north);
	free(set->tex.south);
	free(set->tex.sprit);
}

void	init_all(void)
{
	t_vars	vars;

	vars.set = settings();
	free_set(&vars.set);
	ft_putarraydelim_fd(vars.set.map, '\n', 1);
	// ft_arrayfree(vars.set.map);
	setup(&vars.player);
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "3DCub");
	vars.renderer = mlx_create_renderer(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render(&vars);
	input(&vars);
	mlx_set_render_color(&vars.renderer, 0x00aa00aa);
	mlx_draw_circle(&vars.renderer,
	mlx_get_circle(400, 400, 60));
	mlx_put_image_to_window(vars.mlx,
					vars.window,
					vars.renderer.img,
					0, 0);
	mlx_loop(vars.mlx);
}
