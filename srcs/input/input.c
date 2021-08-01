/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:27:40 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 18:24:53 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	mlx_destroy_image(vars->mlx, vars->renderer.img);
	exit(0);
	return (0);
}

int	key_pressed(int event, t_vars *vars)
{
	if (event == KEY_ESC)
		key_exit(vars);
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

int	key_released(int event, t_vars *vars)
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
