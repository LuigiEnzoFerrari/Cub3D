#include "mlx_extension.h"

void	mlx_put_pixel(t_xRenderer *renderer, int x, int y)
{
	char	*dst;

	dst = renderer->addr + (y * renderer->s_line + x * (renderer->bpp >> 3));
	*(uint32_t *)dst = renderer->color;
}
