#include "cube.h"

static void	init_RES(t_RES *res)
{
	res->h = 0;
	res->w = 0;
}

static void	init_TEX(t_TEX *tex)
{
	tex->east = NULL;
	tex->south = NULL;
	tex->sprit = NULL;
	tex->west = NULL;
	tex->north = NULL;
}

static void	init_checkv(t_check *cvalues)
{
	cvalues->all = false;
	cvalues->south = false;
	cvalues->north = false;
	cvalues->west = false;
	cvalues->east = false;
	cvalues->floor = false;
	cvalues->color = false;
	cvalues->resol = false;
	cvalues->inv.map = false;
	cvalues->inv.empty = false;
	cvalues->inv.all = false;
	cvalues->inv.rgb = false;
	cvalues->inv.res = false;
	cvalues->inv.tex = false;
	cvalues->inv.ch = false;
}

static void	init_RGBA(t_RGBA *rgba)
{
	rgba->r = 0;
	rgba->g = 0;
	rgba->b = 0;
	rgba->a = 0;
}

void	init_val(t_sval *val)
{
	init_checkv(&val->cvalues);
	init_TEX(&val->tex);
	init_RGBA(&val->color);
	init_RGBA(&val->folor);
	init_RES(&val->resolution);
}
