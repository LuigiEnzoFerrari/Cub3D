#include "cub.h"

static void	set_player(t_P1 *player)
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

void	init_all(t_vars *vars)
{

	vars->set = settings();
	free_set(&vars->set);
	ft_putarraydelim_fd(vars->set.map, '\n', 1);
	set_player(&vars->player);


	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "3DCub");
	vars->renderer = mlx_create_renderer(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
}
