/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:27:40 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 11:20:26 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	exit_game(t_vars *vars)
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
		vars->player.wDFB = 1;
	if (event == KEY_S)
		vars->player.wDFB = -1;
	if (event == KEY_D)
		vars->player.wDLR = 1;
	if (event == KEY_A)
		vars->player.wDLR = -1;
	if (event == KEY_RIGHT)
		vars->player.tD = 1;
	if (event == KEY_LEFT)
		vars->player.tD = -1;
	update(vars);
	render(vars);
	return (0);
}

static int	key_released(int event, t_vars *vars)
{
	if (event == KEY_W)
		vars->player.wDFB = 0;
	if (event == KEY_S)
		vars->player.wDFB = 0;
	if (event == KEY_D)
		vars->player.wDLR = 0;
	if (event == KEY_A)
		vars->player.wDLR = 0;
	if (event == KEY_RIGHT)
		vars->player.tD = 0;
	if (event == KEY_LEFT)
		vars->player.tD = 0;
	return (0);
}

void	input(t_vars *vars)
{
	mlx_hook(vars->window, 2, 1l << 0, key_pressed, vars);
	mlx_hook(vars->window, 3, 1l << 1, key_released, vars);
	mlx_hook(vars->window, 33, 1l << 17, exit_game, vars);
}
