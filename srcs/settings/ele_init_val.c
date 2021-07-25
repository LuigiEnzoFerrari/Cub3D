#include "cub.h"

static void	init_checkv(t_check *cvalues)
{
	cvalues->sprit = false;
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
	init_TEX(&val->set.tex);
	init_RES(&val->set.resolution);
}
