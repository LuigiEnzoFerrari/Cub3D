#include "mlx_extension.h"

static void mlx_put4_pixel(t_xRenderer *renderer, int cx, int cy, int x, int y)
{
	mlx_put_pixel(renderer, cx + x, cy + y);
	if (x != 0)
		mlx_put_pixel(renderer, cx - x, cy + y);
	if (y != 0)
		mlx_put_pixel(renderer, cx + x, cy - y);
	if (x != 0 && y != 0)
		mlx_put_pixel(renderer, cx - x, cy - y);
}

static void mlx_put8_pixel(t_xRenderer *renderer, int cx, int cy, int x, int y)
{
	mlx_put4_pixel(renderer, cx, cy, x, y);
	if (x != y)
		mlx_put4_pixel(renderer, cx, cy, y, x);
}

void	mlx_draw_circle(t_xRenderer *renderer, t_xCircle circle)
{
	int	error;
	int	x;
	int y;


	error = -circle.r;
	x = circle.r;
	y = 0;
	while (x >= y)
	{
		mlx_put8_pixel(renderer, circle.x, circle.y, x, y);
		error += y;
		y++;
		error += y;
		if (error >= 0)
		{
			x--;
			error -= x;
			error -= x;
		}
	}
}