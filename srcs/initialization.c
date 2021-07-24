#include "cub.h"

void	set_player(t_P1 *player)
{
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->w = 5;
	player->h = 5;
	player->walkDirection = 0;
	player->turnDirection = 0;
	player->turnSpeed = 5 * (PI / 180);
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

void	drawRects(t_vars *vars)
{
	mlx_set_render_color(&vars->renderer,
	mlx_get_hex_trgb(vars->set.cell.t, vars->set.cell.r, vars->set.cell.g, vars->set.cell.b));
	mlx_draw_fill_rect(&vars->renderer,
	mlx_get_rect( 50, 50, 50, 50));
	mlx_render_present(vars->mlx, vars->window, vars->renderer.img);


	mlx_set_render_color(&vars->renderer,
	mlx_get_hex_trgb(vars->set.floor.t, vars->set.floor.r, vars->set.floor.g, vars->set.floor.b));
	mlx_draw_fill_rect(&vars->renderer,
	mlx_get_rect( 200, 50, 50, 50));
	mlx_render_present(vars->mlx, vars->window, vars->renderer.img);
}

void	init_all(t_vars *vars)
{
	vars->set = settings();

	ft_putarraydelim_fd(vars->set.map, '\n', 1);
	// set_player(&vars->player);

	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "3DCub");
	vars->renderer = mlx_create_renderer(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	drawRects(vars);
	mlx_loop(vars->mlx);
	// vars->window = mlx_new_window(vars->mlx, vars->set.resolution.h,
	// vars->set.resolution.w, "3DCub");
	// vars->renderer = mlx_create_renderer(vars->mlx, vars->set.resolution.h,
	// vars->set.resolution.w);
	free_set(&vars->set);
	ft_arrayfree(vars->set.map);
}
