/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:47:04 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 20:47:05 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_extension.h"

void	mlx_put_pixel(t_xRenderer *renderer, int x, int y)
{
	char	*dst;

	dst = renderer->addr + (y * renderer->s_line + x * (renderer->bpp >> 3));
	*(uint32_t *)dst = renderer->color;
}
