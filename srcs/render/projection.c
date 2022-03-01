/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:00:29 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:28:47 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

static uint32_t	color_intesity(uint32_t color, float intensity)
{
	uint32_t	t;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	t = ((color & (0xff << 24)) * intensity);
	r = ((color & (0xff << 16)) * intensity);
	g = ((color & (0xff << 8)) * intensity);
	b = ((color & (0xff)) * intensity);
	return ((t & (0xff << 24)) | (r & (0xff << 16)) | (g & (0xff << 8)) | b);
}

static void	tex_off_set(t_rays rays, t_xpoint *off_set)
{
	if (rays.is_vert)
		off_set->x = (int)rays.wall_hit_y % TILE_SIZE;
	else
		off_set->x = (int)rays.wall_hit_x % TILE_SIZE;
}

static int	*get_texture_addr(t_ximg *tex, t_rays rays)
{
	int	*dest;

	dest = 0x00000000;
	if (rays.up && !rays.is_vert)
		dest = tex[NO].addr;
	else if (rays.down && !rays.is_vert)
		dest = tex[SO].addr;
	else if (rays.left && rays.is_vert)
		dest = tex[WE].addr;
	else if (rays.right && rays.is_vert)
		dest = tex[EA].addr;
	return (dest);
}

static void	line_wall(t_vars *vars, t_proj pro, t_xpoint res)
{
	t_xpoint	off_set;
	int			distop;
	int			*tex;
	uint32_t	color_tex;

	tex_off_set(vars->rays[res.x], &off_set);
	tex = get_texture_addr(vars->tex, vars->rays[res.x]);
	res.y = pro.top_pixel;
	while (res.y < pro.bottom_pixel)
	{
		distop = res.y + (pro.strip_height >> 1)
			- (vars->set.resolution.h >> 1);
		off_set.y = distop * ((double)TILE_SIZE / pro.strip_height);
		color_tex = tex[(TILE_SIZE * off_set.y) + off_set.x];
		if (vars->rays[res.x].is_vert)
			color_tex = color_intesity(color_tex, 0.5);
		mlx_set_render_color(&vars->renderer, color_tex);
		mlx_put_pixel(&vars->renderer, res.x, res.y);
		res.y++;
	}
}

void	projection(t_vars *vars, t_rays *rays, t_P1 player, t_set set)
{
	t_proj		pro;
	t_xpoint	res;

	res.x = 0;
	while (res.x < set.resolution.w)
	{
		pro.per_distance = rays[res.x].distance
			* cos(rays[res.x].angle - player.rotation_angle);
		pro.height = (TILE_SIZE / pro.per_distance) * player.dist;
		pro.strip_height = (int)pro.height;
		pro.top_pixel = (set.resolution.h >> 1) - (pro.strip_height >> 1);
		if (pro.top_pixel < 0)
			pro.top_pixel = 0;
		pro.bottom_pixel = (set.resolution.h >> 1) + (pro.strip_height >> 1);
		if (pro.bottom_pixel > set.resolution.h)
			pro.bottom_pixel = set.resolution.h;
		line_wall(vars, pro, res);
		res.x++;
	}
}
