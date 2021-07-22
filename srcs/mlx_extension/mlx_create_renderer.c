#include "mlx_extension.h"

t_xRenderer	mlx_create_renderer(void *mlx, int size_x, int size_y)
{
	t_xRenderer renderer;

	renderer.img = mlx_new_image(mlx, size_x, size_y);
	renderer.addr = mlx_get_data_addr(renderer.img,
									&renderer.bpp,
									&renderer.s_line,
									&renderer.endian);
	return (renderer);
}
