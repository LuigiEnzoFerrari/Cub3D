#include "cub.h"

void	load_textures(t_vars *vars)
{
	int		w;
	int		h;

	vars->tex.img = mlx_xpm_file_to_image(vars->mlx, vars->set.tex.east, &w, &h);
	if (!vars->tex.img)
	{
		ft_putendl_fd("No texture was fount", 1);
		exit(0);
	}
	vars->tex.addr = (int32_t *)mlx_get_data_addr(vars->tex.img, &vars->tex.bpp,
		&vars->tex.s_line, &vars->tex.endian);
}

void	set_window(t_set *set, void *mlx)
{
	int	max_width;
	int	max_height;

	mlx_get_screen_size(mlx, &max_width, &max_height);
	if (set->resolution.w > max_width)
		set->resolution.w = max_width;
	if (set->resolution.h > max_height)
		set->resolution.h = max_height;
	set->map_size.x = ft_strlen(*set->map);
	set->map_size.y = ft_arraylen(set->map);
}

void	free_set(t_set *set)
{
	free(set->tex.east);
	free(set->tex.west);
	free(set->tex.north);
	free(set->tex.south);
	free(set->tex.sprit);
}

void trying(t_vars *vars)
{
	uint32_t color = (uint32_t)vars->tex.addr;
	mlx_set_render_color(&vars->renderer, color);
	mlx_put_pixel(&vars->renderer, 10, 10);
	mlx_render_present(vars->mlx, vars->window, vars->renderer.img);
	for (int x = 0; x < TILE_SIZE; x++)
	{
		for (int y = 0; y < TILE_SIZE; y++)
		{
			uint32_t color = vars->tex.addr[(y * TILE_SIZE) + x];
			mlx_set_render_color(&vars->renderer, color);
			mlx_put_pixel(&vars->renderer, x, y);
		}
	}
}

void	init_all(t_vars *vars, int argc, char **argv)
{
	vars->set = settings(argc, argv);
	vars->rays = malloc(sizeof(t_rays) * vars->set.resolution.w);
	vars->set.pixel = (uint32_t *)malloc(sizeof(uint32_t) * (uint32_t)TILE_SIZE * (uint32_t)TILE_SIZE);

	//temp

	for (int x = 0; x < TILE_SIZE; x++) {
		for (int y = 0; y < TILE_SIZE; y++) {
			vars->set.pixel[(TILE_SIZE * y) + x] = (x % 8 && y % 8) ? 0x000000ff : 0x00000000;
		}
	}
	ft_putarraydelim_fd(vars->set.map, '\n', 1);
	// ft_arrayfree(vars->set.map);
	// free(vars->set.pixel);
	set_player(&vars->player, vars->set);
	vars->mlx = mlx_init();
	set_window(&vars->set, vars->mlx);
	vars->window = mlx_new_window(vars->mlx, vars->set.resolution.w,
		vars->set.resolution.h, "3DCub");
	vars->renderer = mlx_create_renderer(vars->mlx, vars->set.resolution.w,
		vars->set.resolution.h);

	load_textures(vars);

	// trying(vars);
	free_set(&vars->set);
}
