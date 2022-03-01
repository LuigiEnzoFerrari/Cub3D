/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_renderer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:46:37 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/28 22:48:07 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_extension.h"

t_xrenderer	mlx_create_renderer(void *mlx, int size_x, int size_y)
{
	t_xrenderer	renderer;

	renderer.img = mlx_new_image(mlx, size_x, size_y);
	renderer.addr = mlx_get_data_addr(renderer.img,
			&renderer.bpp, &renderer.s_line, &renderer.endian);
	return (renderer);
}
