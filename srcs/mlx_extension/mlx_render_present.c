#include "mlx_extension.h"

void	mlx_render_present(void *mlx, void *win, void *img)
{
	mlx_put_image_to_window(mlx, win, img, 0, 0);
}
