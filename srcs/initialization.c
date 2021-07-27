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
	player->fov = 60 * PI /180;
}

void	set_window(t_set *set)
{
	set->map_size.x = ft_strlen(*set->map);
	set->map_size.y = ft_arraylen(set->map);
	set->tile_size = floor(set->resolution.h / set->map_size.y);
	if (set->map_size.x > set->map_size.y)
		set->tile_size = floor(set->resolution.w / set->map_size.x);
	set->tile_size = 50;
}

void	free_set(t_set *set)
{
	free(set->tex.east);
	free(set->tex.west);
	free(set->tex.north);
	free(set->tex.south);
	free(set->tex.sprit);
}

void	init_all(t_vars *vars)
{
	vars->set = settings();
	set_window(&vars->set);
	vars->rays = malloc(sizeof(t_rays) * NUM_RAY);
	set_player(&vars->player);
	free_set(&vars->set);
	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "3DCub");
	vars->renderer = mlx_create_renderer(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
}
