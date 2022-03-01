/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_init_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:32:07 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/28 22:45:29 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_res(t_res *res)
{
	res->h = 0;
	res->w = 0;
}

void	init_tex(t_tex *tex)
{
	tex->east = NULL;
	tex->south = NULL;
	tex->west = NULL;
	tex->north = NULL;
}

static void	init_checkv(t_check *cvalues)
{
	cvalues->south = false;
	cvalues->north = false;
	cvalues->west = false;
	cvalues->east = false;
	cvalues->floor = false;
	cvalues->color = false;
	cvalues->resol = false;
	cvalues->inv.map = false;
	cvalues->inv.dkey = false;
	cvalues->inv.empty = false;
	cvalues->inv.rgb = false;
	cvalues->inv.res = false;
	cvalues->inv.tex = false;
	cvalues->inv.ch = false;
}

void	init_val(t_sval *val)
{
	val->cmap.player = false;
	val->cmap.dplayer = false;
	val->cmap.x_split = false;
	val->cmap.y_split = false;
	init_checkv(&val->cvalues);
	init_tex(&val->set.tex);
	init_res(&val->set.resolution);
}
