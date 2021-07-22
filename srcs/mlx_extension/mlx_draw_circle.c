#include "mlx_extension.h"

static void mlx_put4_pixel(t_data *img, int cx, int cy, int x, int y, int color)
{
	mlx_put_pixel(img, cx + x, cy + y, color);
	if (x != 0)
		mlx_put_pixel(img, cx - x, cy + y, color);
	if (y != 0)
		mlx_put_pixel(img, cx + x, cy - y, color);
	if (x != 0 && y != 0)
		mlx_put_pixel(img, cx - x, cy - y, color);
}

static void mlx_put8_pixel(t_data *img, int cx, int cy, int x, int y, int color)
{
	mlx_put4_pixel(img, cx, cy, x, y, color);
	if (x != y)
		mlx_put4_pixel(img, cx, cy, y, x, color);
}

void	mlx_draw_circle(t_data *img, t_xCircle circle, int color)
{
	int	error;
	int	x;
	int y;


	error = -circle.r;
	x = circle.r;
	y = 0;
	while (x >= y)
	{
		mlx_put8_pixel(img, circle.x, circle.y, x, y, color);
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