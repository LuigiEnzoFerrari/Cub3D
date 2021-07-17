#include "struct.h"

void	init_RES(t_RES *res)
{
	res->h = 0;
	res->w = 0;
}

void	init_TEX(t_TEX *tex)
{
	tex->east = NULL;
	tex->south = NULL;
	tex->sprit = NULL;
	tex->west = NULL;
	tex->north = NULL;
}

void	init_RGBA(t_RGBA *rgba)
{
	rgba->r = 0;
	rgba->g = 0;
	rgba->b = 0;
	rgba->a = 0;
}
