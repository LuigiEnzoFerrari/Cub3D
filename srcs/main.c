/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:06:04 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:41:54 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	input(t_vars *vars)
{
	mlx_hook(vars->window, 2, 1l << 0, key_pressed, vars);
	mlx_hook(vars->window, 3, 1l << 1, key_released, vars);
	mlx_hook(vars->window, 33, 1l << 17, key_exit, vars);
	mlx_loop_hook(vars->mlx, render, vars);
}

void	update(t_vars *vars)
{
	player(vars);
	rays_casting(vars);
}

int	render(t_vars *vars)
{
	background(&vars->renderer, vars->set);
	projection(vars, vars->rays, vars->player, vars->set);
	map(vars);
	mlx_render_present(vars->mlx, vars->window, vars->renderer.img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_all(&vars, argc, argv);
	update(&vars);
	render(&vars);
	input(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
