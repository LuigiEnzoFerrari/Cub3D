#include "cub.h"

static int exit_game(t_vars *vars) //temporary
{
		mlx_destroy_window(vars->mlx, vars->window);
		mlx_destroy_image(vars->mlx, vars->renderer.img);
		exit(0);
		return (0);
}

static int	key_pressed(int event, t_vars *vars)
{
	if (event == KEY_ESC)
		exit_game(vars);
	if (event == KEY_W)
		vars->player.walkDirection = 1;
	if (event == KEY_S)
		vars->player.walkDirection = -1;
	if (event == KEY_D)
		vars->player.walkDirectiontwo = 1;
	if (event == KEY_A)
		vars->player.walkDirectiontwo = -1;
	if (event == KEY_RIGHT)
		vars->player.turnDirection = 1;
	if (event == KEY_LEFT)
		vars->player.turnDirection = -1;
	update(vars);
	render(vars);
	return (0);
}

static int key_released(int event, t_vars *vars)
{
	if (event == KEY_W)
		vars->player.walkDirection = 0;
	if (event == KEY_S)
		vars->player.walkDirection = 0;
	if (event == KEY_D)
		vars->player.walkDirectiontwo = 0;
	if (event == KEY_A)
		vars->player.walkDirectiontwo = 0;
	if (event == KEY_RIGHT)
		vars->player.turnDirection = 0;
	if (event == KEY_LEFT)
		vars->player.turnDirection = 0;
	return (0);
}

void	input(t_vars *vars)
{
	mlx_hook(vars->window, 2, 1l << 0, key_pressed, vars);
	mlx_hook(vars->window, 3, 1l << 1, key_released, vars);
	mlx_hook(vars->window, 33, 1l << 17, exit_game, vars);
}
