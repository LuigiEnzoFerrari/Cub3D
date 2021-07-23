#include "cub.h"

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

// void	prjection()
// {
// 	for (int i = 0; i < NUM_RAY; i++)
// 	{
// 		float	distanceProjPlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
// 		float	projectedWallHeight = (TILE_SIZE / rays[i].distance) * distanceProjPlane;

// 		int	wallStripHeight = (int)projectedWallHeight;
// 		int	wallTopPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
// 		wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

// 		int	wallBottomPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
// 		wallBottomPixel = wallBottomPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottomPixel;

// 		for (int y = walltopPixel; y < wallBottomPixel; y++)
// 		{
			
// 		}
// 	}
// }

void	renderRays(t_vars *vars)
{
	mlx_set_render_color(&vars->renderer, 0x00ff0000);
	for (int i = 0; i < NUM_RAY; i++)
	{
		mlx_draw_line(&vars->renderer,
		mlx_get_line(
			MINIMAP_SCALE * vars->player.x,
			MINIMAP_SCALE * vars->player.y, 
			MINIMAP_SCALE * vars->rays[i].wallHitX,
			MINIMAP_SCALE * vars->rays[i].wallHitY));
	}
}

void	renderBack(t_xRenderer *renderer)
{
	mlx_set_render_color(renderer, 0x8B008B);
	mlx_draw_fill_rect(renderer,
	mlx_get_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
}
void	castAllRays(t_P1 player, char **map, t_rays *rays)
{
	float rayAngle = player.rotationAngle - (FOV_ANGLE / 2);
	for (int stripId = 0; stripId < NUM_RAY; stripId++)
	{
		rayCasting(player, map, rayAngle, stripId, rays);
		rayAngle += FOV_ANGLE / NUM_RAY;
	}
}

void	update(t_vars *vars)
{
	movePlayer(vars);
	castAllRays(vars->player, vars->set.map, vars->rays);
}

void	render(t_vars *vars)
{
	renderBack(&vars->renderer);
	renderMap(&vars->renderer, vars->set.map);
	renderPlayer(vars);
	renderRays(vars);
	mlx_render_present(vars->mlx, vars->window, vars->renderer.img);
}

int	main(void)
{
	t_vars vars;

	init_all(&vars);
	update(&vars);
	render(&vars);
	input(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
