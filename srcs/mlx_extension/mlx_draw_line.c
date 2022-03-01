/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:46:51 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:26:01 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_extension.h"

static int	mlx_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static t_bline	mlx_set_bresenham_value(t_xline line)
{
	t_bline	bresenham;

	bresenham.sy = -1;
	bresenham.sx = -1;
	if (line.x0 < line.x1)
		bresenham.sx = 1;
	if (line.y0 < line.y1)
		bresenham.sy = 1;
	bresenham.dx = mlx_abs(line.x1 - line.x0);
	bresenham.dy = -mlx_abs(line.y1 - line.y0);
	bresenham.err = bresenham.dx + bresenham.dy;
	return (bresenham);
}

void	mlx_draw_line(t_xrenderer *renderer, t_xline line)
{
	t_bline	bresenham;

	bresenham = mlx_set_bresenham_value(line);
	while (1)
	{
		mlx_put_pixel(renderer, line.x0, line.y0);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		bresenham.e2 = 2 * bresenham.err;
		if (bresenham.e2 >= bresenham.dy)
		{
			bresenham.err += bresenham.dy;
			line.x0 += bresenham.sx;
		}
		if (bresenham.e2 <= bresenham.dx)
		{
			bresenham.err += bresenham.dx;
			line.y0 += bresenham.sy;
		}
	}
}
