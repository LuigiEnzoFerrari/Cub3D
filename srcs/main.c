#include "cub.h"

void	update(t_vars *vars)
{
	player(vars);
	raysCasting(vars);
}

void	render(t_vars *vars)
{
	background(&vars->renderer, vars->set);
	projection(vars, vars->rays, vars->player, vars->set);
	map(vars);
	// sprites(vars, vars->rays, vars->player, vars->set);
	mlx_render_present(vars->mlx, vars->window, vars->renderer.img);
}

int	main(int argc, char **argv)
{
	t_vars vars;

	init_all(&vars, argc, argv);
	update(&vars);
	render(&vars);
	input(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
