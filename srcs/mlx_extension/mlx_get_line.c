/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:46:59 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/28 22:47:15 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_extension.h"

t_xline	mlx_get_line(int x0, int y0, int x1, int y1)
{
	t_xline	line;

	line.x0 = x0;
	line.x1 = x1;
	line.y0 = y0;
	line.y1 = y1;
	return (line);
}
