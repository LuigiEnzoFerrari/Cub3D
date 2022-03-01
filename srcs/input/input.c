/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:27:40 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/28 22:56:05 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_exit(t_vars *vars)
{
	size_t	n;

	n = vars->set.resolution.w;
	mlx_destroy_window(vars->mlx, vars->window);
	mlx_destroy_image(vars->mlx, vars->renderer.img);
	free(vars->rays);
	exit(0);
	return (0);
}

int	key_pressed(int event, t_vars *vars)
{
	if (event == KEY_ESC)
		key_exit(vars);
	if (event == KEY_W)
		vars->player.walk_direction_fb = 1;
	if (event == KEY_S)
		vars->player.walk_direction_fb = -1;
	if (event == KEY_D)
		vars->player.walk_direction_lr = 1;
	if (event == KEY_A)
		vars->player.walk_direction_lr = -1;
	if (event == KEY_RIGHT)
		vars->player.turn_direction = 1;
	if (event == KEY_LEFT)
		vars->player.turn_direction = -1;
	update(vars);
	return (0);
}

int	key_released(int event, t_vars *vars)
{
	if (event == KEY_W)
		vars->player.walk_direction_fb = 0;
	if (event == KEY_S)
		vars->player.walk_direction_fb = 0;
	if (event == KEY_D)
		vars->player.walk_direction_lr = 0;
	if (event == KEY_A)
		vars->player.walk_direction_lr = 0;
	if (event == KEY_RIGHT)
		vars->player.turn_direction = 0;
	if (event == KEY_LEFT)
		vars->player.turn_direction = 0;
	return (0);
}
