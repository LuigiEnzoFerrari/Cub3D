/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:55:51 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/28 10:56:24 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rays(t_vars *vars)
{
	mlx_set_render_color(&vars->renderer, 0x00ff0000);
	for (int i = 0; i < NUM_RAY; i++)
	{
		mlx_draw_line(&vars->renderer,
		mlx_get_line(
			MINIMAP_SCALE * vars->player.x,
			MINIMAP_SCALE * vars->player.y, 
			MINIMAP_SCALE * vars->rays[i].wallHitX,
			MINIMAP_SCALE * vars->rays[i].wallHitY));
	}
}
