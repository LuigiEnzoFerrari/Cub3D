#include "cub.h"

void	init_all(void)
{
	t_sval	val;
	t_vars	vars;
	t_xLine	line;

	line.x0 = 50;
	line.y0 = 50;
	line.x1 = 330;
	line.y1 = 200;


	settings(&val);
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 800, 600, "3DCub");
	vars.img.img = mlx_new_image(vars.mlx, 800, 600);
	vars.img.addr = mlx_get_data_addr(
									vars.img.img,
									&vars.img.bpp,
									&vars.img.s_line,
									&vars.img.endian);
	mlx_put_pixel(&vars.img, 400, 300, 0x00ff0000);

	mlx_draw_fill_rect(&vars.img,
	mlx_get_rect(50, 60, 60, 50),
	0x00ff0000);

	mlx_draw_line(&vars.img,
	mlx_get_line(20, 20, 500, 20),
	0x00ff0000);

	mlx_put_image_to_window(vars.mlx, vars.window, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
}
