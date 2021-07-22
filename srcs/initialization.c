#include "cub.h"

const int map[MAP_ROWS][MAP_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

t_player player;

void	renderPlayer(t_data *img)
{
	mlx_draw_fill_rect(img,
	mlx_get_rect(player.x * MINIMAP_SCALE,
				player.y * MINIMAP_SCALE,
				player.w * MINIMAP_SCALE,
				player.h * MINIMAP_SCALE),
	mlx_trgb_to_hex(0, 255, 0, 0));

	mlx_draw_line(img,
	mlx_get_line(MINIMAP_SCALE * player.x,
				MINIMAP_SCALE * player.y,
				MINIMAP_SCALE * player.x + cos(player.rotationAngle) * 40,
				MINIMAP_SCALE * player.y + sin(player.rotationAngle) * 40),
				0x00ff0000);
}

void	renderMap(t_data *img) {
	int i;
	int j;
	int tileX;
	int tileY;
	int tileColor;

	i = 0;
	j = 0;
	while (i < MAP_ROWS) {
		while (j < MAP_COLS) {
			tileX = j * TILE_SIZE;
			tileY = i * TILE_SIZE;
			if (map[i][j] != 0)
				tileColor = 255;
			else
				tileColor = 0;
			mlx_draw_fill_rect(img,
			mlx_get_rect(tileX * MINIMAP_SCALE, 
					tileY * MINIMAP_SCALE,
					TILE_SIZE * MINIMAP_SCALE,
					TILE_SIZE * MINIMAP_SCALE),
			mlx_trgb_to_hex(0, tileColor, tileColor, tileColor));
			j++;
		}
		j = 0;
		i++;
	}
}

void	render(t_data *img)
{
	renderMap(img);
	renderPlayer(img);
}

int	hasWall(float x, float y)
{
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return 1;
	int indexGridX = floor(x / TILE_SIZE);
	int indexGridY = floor(y / TILE_SIZE);
	return map[indexGridY][indexGridX] != 0;
}

void	movePlayer()
{
	player.rotationAngle += player.turnDirection * player.turnSpeed;
	float	moveStep = player.walkDirection * player.walkSpeed;
	float	newPlayerX = player.x + cos(player.rotationAngle) * moveStep;
	float	newPlayerY = player.y + sin(player.rotationAngle) * moveStep;
	if (!hasWall(newPlayerX, newPlayerY))
	{
		player.x = newPlayerX;
		player.y = newPlayerY;
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

void	update()
{
	movePlayer();
	// castAllRays();
}

static int	mlx_key_down(int event, t_vars *vars)
{
	if (event == 65307)
	{
		// mlx_destroy_window(vars->mlx, vars->window);
		// mlx_destroy_image(vars->mlx, vars->img.img);
		exit(0);
	}
	if (event == KEY_UP)
		player.walkDirection = 1;
	if (event == KEY_DOWN)
		player.walkDirection = -1;
	if (event == KEY_LEFT)
		player.turnDirection = 1;
	if (event == KEY_RIGHT)
		player.turnDirection = -1;
	update();
	render(&vars->img);
	mlx_put_image_to_window(vars->mlx,
				vars->window,
				vars->img.img,
				0, 0);
	return (0);
}

static int mlx_key_up(int event, t_vars *vars)
{
	if (event == KEY_UP)
		player.walkDirection = 0;
	if (event == KEY_DOWN)
		player.walkDirection = 0;
	if (event == KEY_LEFT)
		player.turnDirection = 0;
	if (event == KEY_RIGHT)
		player.turnDirection = 0;
	return (0);
}

void	input(t_vars *vars)
{
	mlx_hook(vars->window, 2, 1l << 0, mlx_key_down, vars);
	mlx_hook(vars->window, 3, 1l << 1, mlx_key_up, vars);	
}

void	setup()
{
	player.x = WINDOW_WIDTH / 2;
	player.y = WINDOW_HEIGHT / 2;
	player.w = 20;
	player.h = 20;
	player.walkDirection = 0;
	player.turnDirection = 0;
	player.turnSpeed = 30 * (PI / 180);
	player.walkSpeed = 5;
	player.rotationAngle = PI / 2;
}

void	init_all(void)
{
	t_sval	val;
	t_vars	vars;

	settings(&val);
	// setup();
	// vars.mlx = mlx_init();
	// vars.window = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "3DCub");
	// vars.img.img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// vars.img.addr = mlx_get_data_addr(vars.img.img,
	// 								&vars.img.bpp,
	// 								&vars.img.s_line,
	// 								&vars.img.endian);
	// render(&vars.img);
	// input(&vars);

	// mlx_put_image_to_window(vars.mlx,
	// 				vars.window,
	// 				vars.img.img,
	// 				0, 0);
	// mlx_loop(vars.mlx);
}
