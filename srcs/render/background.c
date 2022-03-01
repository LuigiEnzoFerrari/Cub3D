/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:46:54 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/28 22:48:07 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	background(t_xrenderer *renderer, t_set set)
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
