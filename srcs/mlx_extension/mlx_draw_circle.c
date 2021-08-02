/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_circle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:46:42 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 20:57:51 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_extension.h"

static void	mlx_put4_pixel(t_xRenderer *renderer, t_xPoint c, int x, int y)
{
	mlx_put_pixel(renderer, c.x + x, c.y + y);
	if (x != 0)
		mlx_put_pixel(renderer, c.x - x, c.y + y);
	if (y != 0)
		mlx_put_pixel(renderer, c.x + x, c.y - y);
	if (x != 0 && y != 0)
		mlx_put_pixel(renderer, c.x - x, c.y - y);
}

static void	mlx_put8_pixel(t_xRenderer *renderer, t_xPoint c, int x, int y)
{
	mlx_put4_pixel(renderer, c, x, y);
	if (x != y)
		mlx_put4_pixel(renderer, c, y, x);
}

void	mlx_draw_circle(t_xRenderer *renderer, t_xCircle circle)
{
	t_xPoint	c;
	int			error;
	int			x;
	int			y;

	error = -circle.r;
	c.x = circle.x;
	c.y = circle.y;
	y = 0;
	x = circle.r;
	while (x >= y)
	{
		mlx_put8_pixel(renderer, c, x, y);
		error += y;
		y++;
		error += y;
		if (error >= 0)
		{
			x--;
			error -= x;
			error -= x;
		}
	}
}
