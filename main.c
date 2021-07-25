#include "cub.h"

int	hasWall(char **map, float x, float y)
{
	int indexGridX;
	int indexGridY;

	indexGridX = floor(x / TILE_SIZE);
	indexGridY = floor(y / TILE_SIZE);
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return 1;
	return map[indexGridY][indexGridX] != '0';
}

void	renderPlayer(t_vars *vars)
{
	mlx_set_render_color(&vars->renderer, 0x00ffffff);
	mlx_draw_fill_rect(&vars->renderer,
	mlx_get_rect(vars->player.x * MINIMAP_SCALE,
				vars->player.y * MINIMAP_SCALE,
				vars->player.w * MINIMAP_SCALE,
				vars->player.h * MINIMAP_SCALE));

	// mlx_draw_line(&vars->renderer,
	// mlx_get_line(MINIMAP_SCALE * vars->player.x,
	// 			MINIMAP_SCALE * vars->player.y,
	// 			MINIMAP_SCALE * vars->player.x + cos(vars->player.rotationAngle) * 40,
	// 			MINIMAP_SCALE * vars->player.y + sin(vars->player.rotationAngle) * 40));
}

void	renderPro(t_vars *vars, t_rays *rays, t_P1 player)
{
	mlx_set_render_color(&vars->renderer, 0x00131313);
	for (int i = 0; i < NUM_RAY; i++)
	{
		float	perpDistance = rays[i].distance * cos(rays[i].rayAngle - player.rotationAngle);
		float	distanceProjPlane = (WINDOW_WIDTH >> 1) / tan(player.fov / 2);
		float	projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;

		int	wallStripHeight = (int)projectedWallHeight;

		int	wallTopPixel = (WINDOW_HEIGHT >> 1) - (wallStripHeight >> 1);
		wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

		int	wallBottomPixel = (WINDOW_HEIGHT >> 1) + (wallStripHeight >> 1);
		wallBottomPixel = wallBottomPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottomPixel;

		for (int y = wallTopPixel; y < wallBottomPixel; y++)
		{
			mlx_put_pixel(&vars->renderer, i, y);
		}
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
			MINIMAP_SCALE * vars->rays[i].wallHitX,
			MINIMAP_SCALE * vars->rays[i].wallHitY));
	}
}

void	renderBack(t_xRenderer *renderer, int cell, int floor)
{	
	mlx_set_render_color(renderer, cell);
	mlx_draw_fill_rect(renderer,
	mlx_get_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT >> 1));
	mlx_set_render_color(renderer, floor);
	mlx_draw_fill_rect(renderer,
	mlx_get_rect(0, WINDOW_HEIGHT >> 1, WINDOW_WIDTH, WINDOW_HEIGHT >> 1));
}

void	raysCasting(t_P1 player, char **map, t_rays *rays)
{
	float	angle;
	size_t	i;
	
	angle = player.rotationAngle - (player.fov / 2);
	i = 0;
	while (i < NUM_RAY)
	{
		rayCasting(player, map, angle, i, rays);
		angle += player.fov / NUM_RAY;
		i++;
	}
}

void	update(t_vars *vars)
{
	movePlayer(vars);
	raysCasting(vars->player, vars->set.map, vars->rays);
}

void	render(t_vars *vars)
{
	renderBack(&vars->renderer, vars->set.cell, vars->set.floor);
	renderMap(&vars->renderer, vars->set.map);
	renderPlayer(vars);
	renderRays(vars);
	renderPro(vars, vars->rays, vars->player);
	mlx_render_present(vars->mlx, vars->window, vars->renderer.img);
}

int	main(void)
{
	t_vars vars;

	init_all(&vars);
	// update(&vars);
	// render(&vars);
	// input(&vars);
	// mlx_loop(vars.mlx);
	return (0);
}
