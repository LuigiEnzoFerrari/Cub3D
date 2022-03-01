/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:46:55 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/28 22:46:45 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_extension.h"

t_xcircle	mlx_get_circle(int x, int y, int r)
{
	t_xcircle	circle;

	circle.x = x;
	circle.y = y;
	circle.r = r;
	return (circle);
}
