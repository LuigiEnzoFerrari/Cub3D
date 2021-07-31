/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:00:29 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/31 18:19:01 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

uint32_t	colorIntesity(uint32_t color, float intensity)
{
	uint32_t	t;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	t = ((color & (0xff << 24)) * intensity);
	r = ((color & (0xff << 16)) * intensity);
	g = ((color & (0xff << 8)) * intensity);
	b = ((color & (0xff)) * intensity);
	return ((t & (0xff << 24)) | (r  & (0xff << 16)) | (g & (0xff << 8)) | b);
}

static void	texOffSet(t_rays rays, t_xPoint *offSet)
{
		if (rays.isVert)
			offSet->x = (int)rays.wallHitY % TILE_SIZE;
		else
			offSet->x = (int)rays.wallHitX % TILE_SIZE;
}

static int	*get_texture_addr(t_ximg *tex, t_rays rays)
{
	int *dest;

	dest = 0x00000000;
	if (rays.up && !rays.isVert)
		dest = tex[NO].addr;
	else if (rays.down && !rays.isVert)
		dest = tex[SO].addr;
	else if (rays.left && rays.isVert)
		dest = tex[WE].addr;
	else if (rays.right && rays.isVert)
		dest = tex[EA].addr;
	return (dest);
}

static void	lineWall(t_vars *vars, t_proj pro, t_xPoint res)
{
	t_xPoint	offSet;
	int			distop;
	int			*tex;
	uint32_t	colorTex;

	texOffSet(vars->rays[res.x], &offSet);
	tex = get_texture_addr(vars->tex, vars->rays[res.x]);
	res.y = pro.topPixel;
	while (res.y < pro.bottomPixel)
	{
		distop = res.y + (pro.stripHeight >> 1) - (vars->set.resolution.h >> 1);
		offSet.y = distop * ((double)TILE_SIZE / pro.stripHeight);
		colorTex = tex[(TILE_SIZE * offSet.y) + offSet.x];
		if (vars->rays[res.x].isVert)
			colorTex = colorIntesity(colorTex, 0.5);
		mlx_set_render_color(&vars->renderer, colorTex);
		mlx_put_pixel(&vars->renderer, res.x, res.y);
		res.y++;
	}
}

void	projection(t_vars *vars, t_rays *rays, t_P1 player, t_set set)
{
	t_proj		pro;
	t_xPoint	res;

	res.x = 0;
	while (res.x < set.resolution.w)
	{
		pro.perDistance = rays[res.x].distance
			* cos(rays[res.x].angle - player.rAngle);
		pro.height = (TILE_SIZE / pro.perDistance) * player.dist;
		pro.stripHeight = (int)pro.height;
		pro.topPixel = (set.resolution.h >> 1) - (pro.stripHeight >> 1);
		if (pro.topPixel < 0)
			pro.topPixel = 0;
		pro.bottomPixel = (set.resolution.h >> 1) + (pro.stripHeight >> 1);
		if (pro.bottomPixel > set.resolution.h)
			pro.bottomPixel = set.resolution.h;
		lineWall(vars, pro, res);
		res.x++;
	}
}
