#include "cub.h"

void	set_player(t_P1 *player)
{
	player->x = 6 * TILE_SIZE + (TILE_SIZE >> 1);
	player->y = 6 * TILE_SIZE + (TILE_SIZE >> 1);
	player->r = 20;
	player->walkDirection = 0;
	player->turnDirection = 0;
	player->turnSpeed = 5 * (PI / 180);
	player->walkSpeed = 5;
	player->rAngle = PI / 2;
	player->fov = PI / 3;
}

void	set_window(t_set *set)
{
	set->map_size.x = ft_strlen(*set->map);
	set->map_size.y = ft_arraylen(set->map);
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
	vars->rays = malloc(sizeof(t_rays) * vars->set.resolution.w);
	set_player(&vars->player);
	free_set(&vars->set);
	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, vars->set.resolution.w,
		vars->set.resolution.h, "3DCub");
	vars->renderer = mlx_create_renderer(vars->mlx, vars->set.resolution.w,
		vars->set.resolution.h);
}
