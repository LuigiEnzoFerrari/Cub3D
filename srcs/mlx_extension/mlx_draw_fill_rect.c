/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_fill_rect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:46:47 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/28 22:48:07 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_extension.h"

void	mlx_draw_fill_rect(t_xrenderer *renderer, t_xrect rect)
{
	int	dx;
	int	dy;
	int	x_temp;

	dx = rect.x + rect.w;
	dy = rect.y + rect.h;
	x_temp = rect.x;
	while (rect.y < dy)
	{
		while (rect.x < dx)
		{
			mlx_put_pixel(renderer, rect.x, rect.y);
			rect.x++;
		}
		rect.y++;
		rect.x = x_temp;
	}
}
