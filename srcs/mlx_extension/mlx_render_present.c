/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render_present.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:47:07 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 20:47:08 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_extension.h"

void	mlx_render_present(void *mlx, void *win, void *img)
{
	mlx_put_image_to_window(mlx, win, img, 0, 0);
}
