/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:55:51 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 03:12:39 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rays(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_set_render_color(&vars->renderer, 0x00ff0000);
	while (i < vars->set.resolution.w)
	{
		mlx_draw_line(&vars->renderer,
			mlx_get_line(
				MINIMAP_SCALE * vars->player.x,
				MINIMAP_SCALE * vars->player.y,
				MINIMAP_SCALE * vars->rays[i].wallHitX,
				MINIMAP_SCALE * vars->rays[i].wallHitY));
		i += 16;
	}
}
