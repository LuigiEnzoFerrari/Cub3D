/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerPosition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:51:25 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 10:06:09 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	playerPosition(t_vars *vars)
{
	mlx_set_render_color(&vars->renderer, 0x00ffffff);
	mlx_draw_circle(&vars->renderer,
		mlx_get_circle(vars->player.x * MINIMAP_SCALE,
			vars->player.y * MINIMAP_SCALE,
			vars->player.r * MINIMAP_SCALE));
}
