#include "cub.h"


static int	key_pressed(int event, t_vars *vars)
{
	if (event == 65307)
	{
		// mlx_destroy_window(vars->mlx, vars->window);
		// mlx_destroy_image(vars->mlx, vars->renderer.img);
		exit(0);
	}
	if (event == KEY_UP)
		vars->player.walkDirection = 1;
	if (event == KEY_DOWN)
		vars->player.walkDirection = -1;
	if (event == KEY_LEFT)
		vars->player.turnDirection = 1;
	if (event == KEY_RIGHT)
		vars->player.turnDirection = -1;
	update(vars);
	render(vars);
	mlx_put_image_to_window(vars->mlx,
				vars->window,
				vars->renderer.img,
				0, 0);
	return (0);
}

static int key_released(int event, t_vars *vars)
{
	if (event == KEY_UP)
		vars->player.walkDirection = 0;
	if (event == KEY_DOWN)
		vars->player.walkDirection = 0;
	if (event == KEY_LEFT)
		vars->player.turnDirection = 0;
	if (event == KEY_RIGHT)
		vars->player.turnDirection = 0;
	vars->set.cell.a = 0;
	return (0);
}

void	input(t_vars *vars)
{
	mlx_hook(vars->window, 2, 1l << 0, key_pressed, vars);
	mlx_hook(vars->window, 3, 1l << 1, key_released, vars);	
}
