/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:46:55 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 20:57:23 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_extension.h"

t_xCircle	mlx_get_circle(int x, int y, int r)
{
	t_xCircle	circle;

	circle.x = x;
	circle.y = y;
	circle.r = r;
	return (circle);
}
