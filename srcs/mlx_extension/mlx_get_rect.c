#include "mlx_extension.h"

t_xRect	mlx_get_rect(int x, int y, int w, int h)
{
	t_xRect	rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return (rect);
}