/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:00:29 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/30 20:08:21 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drawWallLine(t_xRenderer *renderer, t_xPoint res, int bottom, t_rays rays)
{

	if (rays.isVert)
		mlx_set_render_color(renderer, 0x00202020);
	else
		mlx_set_render_color(renderer, 0x00131313);
	while (res.y < bottom)
	{
		mlx_put_pixel(renderer, res.x, res.y);
		res.y++;
	}
}

void	projection(t_vars *vars, t_rays *rays, t_P1 player, t_set set)
{
	t_proj		a;
	t_xPoint	res;

	res.x = 0;
	// mlx_set_render_color(&vars->renderer, 0x00202020);
	while (res.x < set.resolution.w)
	{
		a.perDistance = rays[res.x].distance
			* cos(rays[res.x].angle - player.rAngle);
		a.projHeight = (TILE_SIZE / a.perDistance) * player.dist;
		a.stripHeight = (int)a.projHeight;
		a.topPixel = (set.resolution.h >> 1) - (a.stripHeight >> 1);
		if (a.topPixel < 0)
			a.topPixel = 0;
		a.bottomPixel = (set.resolution.h >> 1) + (a.stripHeight >> 1);
		if (a.bottomPixel > set.resolution.h)
			a.bottomPixel = set.resolution.h;
		int	texoffsetX;
		if (rays[res.x].isVert)
			texoffsetX = (int)rays[res.x].wallHitY % TILE_SIZE;
		else
			texoffsetX = (int)rays[res.x].wallHitX % TILE_SIZE;
		for (res.y = a.topPixel; res.y < a.bottomPixel; res.y++)
		{
			int	distfromtop = res.y + (a.stripHeight >>1) - (set.resolution.h >> 1);
			int	texoffsetY = distfromtop * ((double)TILE_SIZE / a.stripHeight);
			uint32_t tex = vars->tex.addr[(TILE_SIZE * texoffsetY) + texoffsetX];
			mlx_set_render_color(&vars->renderer, tex);
			mlx_put_pixel(&vars->renderer, res.x, res.y);
		}
		// res.y = a.topPixel;
		// drawWallLine(&vars->renderer, res, a.bottomPixel, rays[res.x]);
		res.x++;
	}
}
