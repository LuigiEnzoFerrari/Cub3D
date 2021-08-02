/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_trgb_to_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:47:16 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 20:47:17 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_extension.h"

int	mlx_get_hex_trgb(uint8_t t, uint8_t r, uint8_t g, uint8_t b)
{
	return ((t << 24) | (r << 16) | (g << 8) | (b));
}
