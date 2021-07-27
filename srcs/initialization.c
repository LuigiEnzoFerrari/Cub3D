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
	float	tile_x;
	float	tile_y;

	tile_x = len_map(*set->map);
	tile_y = size_map(set->map);

	set->tile_size = tile_y;
	if (tile_x > tile_y)
		set->tile_size = tile_x;
	// printf("size_x: %d", set->tile_x);
	// printf("size_y: %d", set->tile_y);
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
