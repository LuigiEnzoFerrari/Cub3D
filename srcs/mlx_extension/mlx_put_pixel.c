#include "mlx_extension.h"

void	mlx_put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->s_line + x * (img->bpp >> 3));
	*(uint32_t *)dst = color;
}