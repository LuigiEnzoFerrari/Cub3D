#include "mlx_extension.h"

void	mlx_draw_fill_rect(t_data *img, t_xRect rect, int color)
{
	int	dx;
	int	dy;
	int	x_temp;

	dx = rect.x + rect.w;
	dy = rect.y + rect.h;
	x_temp = rect.x;
	while (rect.y < dy)
	{
		while (rect.x < dx)
		{
			mlx_draw_line(img, mlx_get_line(rect.x, rect.y, dx, rect.y), color);
			rect.x++;
		}
		rect.y++;
		rect.x = x_temp;
	}
}
