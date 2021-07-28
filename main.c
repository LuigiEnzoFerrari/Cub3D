#include "cub.h"

void	update(t_vars *vars)
{
	movePlayer(vars);
	raysCasting(vars);
}

void	render(t_vars *vars)
{
	background(&vars->renderer, vars->set);
	projection(vars, vars->rays, vars->player, vars->set);
	minimap(&vars->renderer, vars->set.map, vars->set);
	playerPosition(vars);
	rays(vars);
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
