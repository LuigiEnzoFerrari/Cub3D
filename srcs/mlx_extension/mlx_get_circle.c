#include "mlx_extension.h"

t_xCircle	mlx_get_circle(int x, int y, int r)
{
	t_xCircle	circle;

	circle.x = x;
	circle.y = y;
	circle.r = r;
	return (circle);
}