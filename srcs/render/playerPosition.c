/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerPosition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:51:25 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 09:21:03 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	playerPosition(t_vars *vars)
{
	mlx_set_render_color(&vars->renderer, 0x00ffffff);
	mlx_draw_fill_rect(&vars->renderer,
		mlx_get_rect(vars->player.x * MINIMAP_SCALE,
			vars->player.y * MINIMAP_SCALE,
			vars->player.w * MINIMAP_SCALE,
			vars->player.h * MINIMAP_SCALE));
}
