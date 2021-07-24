#include "mlx_extension.h"


void	mlx_draw_fill_rect(t_xRenderer *renderer, t_xRect rect)
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
			mlx_put_pixel(renderer, rect.x, rect.y);
			rect.x++;
		}
		rect.y++;
		rect.x = x_temp;
	}
}
