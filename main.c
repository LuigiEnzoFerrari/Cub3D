#include "cub.h"


void	renderPlayer(t_vars *vars)
{
	mlx_set_render_color(&vars->renderer, 0x00ffffff);
	mlx_draw_fill_rect(&vars->renderer,
	mlx_get_rect(vars->player.x * MINIMAP_SCALE,
				vars->player.y * MINIMAP_SCALE,
				vars->player.w * MINIMAP_SCALE,
				vars->player.h * MINIMAP_SCALE));
}

void	renderPro(t_vars *vars, t_rays *rays, t_P1 player, int tile_size)
{
	mlx_set_render_color(&vars->renderer, 0x00131313);
	for (int i = 0; i < NUM_RAY; i++)
	{
		float	perpDistance = rays[i].distance * cos(rays[i].rayAngle - player.rotationAngle);
		float	distanceProjPlane = (WINDOW_WIDTH >> 1) / tan(player.fov / 2);
		float	projectedWallHeight = (tile_size / perpDistance) * distanceProjPlane;

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


void	update(t_vars *vars)
{
	movePlayer(vars);
	raysCasting(vars);
}

void	render(t_vars *vars)
{
	renderBack(&vars->renderer, vars->set.cell, vars->set.floor);
	renderPro(vars, vars->rays, vars->player, vars->set.tile_size);
	renderMap(&vars->renderer, vars->set.map, vars->set);
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
