/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:46:54 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 09:23:50 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	background(t_xRenderer *renderer, t_set set)
{	
	mlx_set_render_color(renderer, set.cell);
	mlx_draw_fill_rect(renderer,
		mlx_get_rect(0, 0, set.resolution.w, set.resolution.h >> 1));
	mlx_set_render_color(renderer, set.floor);
	mlx_draw_fill_rect(renderer,
		mlx_get_rect(0,
			set.resolution.h >> 1,
			set.resolution.w,
			set.resolution.h >> 1));
}
