#include "mlx_extension.h"

static int	mlx_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static t_BLine mlx_set_Bresenham_value(t_xLine line)
{
	t_BLine	Bresenham;

	Bresenham.sy = -1;
	Bresenham.sx = -1;

	if (line.x0 < line.x1)
		Bresenham.sx = 1;
	if (line.y0 < line.y1)
		Bresenham.sy = 1;
	Bresenham.dx = mlx_abs(line.x1 - line.x0);
	Bresenham.dy = -mlx_abs(line.y1 - line.y0);
	Bresenham.err = Bresenham.dx + Bresenham.dy;
	return (Bresenham);
}

void	mlx_draw_line(t_data *img, t_xLine line, int color)
{
	// int dx;
	// int dy;
	// int sx;
	// int sy;
	// int err;
	// int e2;	/* error value e_xy */

	// sy = -1;
	// sx = -1;
	// if (line.x0 < line.x1)
	// 	sx = 1;
	// if (line.y0 < line.y1)
	// 	sy = 1;
	// dx = mlx_abs(line.x1 - line.x0);
	// dy = -mlx_abs(line.y1 - line.y0);
	// err = dx + dy;
	t_BLine Bresenham;

	Bresenham = mlx_set_Bresenham_value(line);
	while (666)
	{
		mlx_put_pixel(img, line.x0, line.y0, color);
		if (line.x0 == line.x1 && line.y0 == line.y1) 
			break;
		Bresenham.e2 = 2 * Bresenham.err;
		if (Bresenham.e2 >= Bresenham.dy)	/* e_xy+e_x > 0 */
		{
			Bresenham.err += Bresenham.dy;
			line.x0 += Bresenham.sx;
		}
		if (Bresenham.e2 <= Bresenham.dx)	/* e_xy+e_y < 0 */
		{
			Bresenham.err += Bresenham.dx;
			line.y0 += Bresenham.sy;
		}
	}
}
