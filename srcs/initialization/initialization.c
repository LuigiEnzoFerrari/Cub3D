#include "cub.h"

int		issprite(int c)
{
	return (c == '2');
}

static size_t	ft_arraynchar(char **map, int (f)(int))
{
	int		a;
	int		b;
	size_t	n;

	a = 0;
	n = 0;
	while (*(map + a))
	{
		b = 0;
		while (*(*(map + a) + b))
		{
			if (f(*(*(map + a) + b)))
				n++;
			b++;
		}
		a++;
	}
	return (n);
}

static void	s_postion(char **map, t_xFPoint *p, int (f)(int))
{
	int		a;
	int		b;
	size_t	i;

	a = 0;
	i = 0;
	while (*(map + a))
	{
		b = 0;
		while (*(*(map + a) + b))
		{
			if (f(*(*(map + a) + b)))
			{
				p[i].x = b;
				p[i].y = a;
				i++;
			}
			b++;
		}
		a++;
	}
}

void	set_sprites(t_set set, t_s *s)
{
	int	n;

	s[ITEM].n = ft_arraynchar(set.map, issprite);
	s[ITEM].p = malloc(sizeof(t_xFPoint) * s[ITEM].n);
	s_postion(set.map, s[ITEM].p, issprite);

	n = 0;
	while (n < s[ITEM].n)
	{
		s[ITEM].p[n].x = s[ITEM].p[n].x * TILE_SIZE + (TILE_SIZE >> 1);
		s[ITEM].p[n].y = s[ITEM].p[n].y * TILE_SIZE + (TILE_SIZE >> 1);
		ft_putnbr(n);
		ft_putstr(" spx ");
		ft_putnbr(s[ITEM].p[n].x);
		ft_putchar('\n');
		ft_putstr(" spy ");
		ft_putnbr(s[ITEM].p[n].y);
		ft_putchar('\n');
		n++;
	}
}

void	load_sprites(t_vars *vars, t_s *s)
{
	int		h;
	int		w;

	ft_memset(s, 0, sizeof(t_s));
	s[ITEM].s.img = mlx_xpm_file_to_image(vars->mlx, vars->set.tex.sprit, &w, &h);
	if (!s[ITEM].s.img)
	{
		ft_putendl_fd("No barrel was found", 0);
		exit(0);
	}
	s[ITEM].s.addr = (int32_t *)mlx_get_data_addr(s[ITEM].s.img, &s[ITEM].s.bpp,
		&s[ITEM].s.s_line, &s[ITEM].s.endian);
	set_sprites(vars->set, &s[ITEM]);
}

void	load_textures(t_vars *vars, t_ximg *tex)
{
	int		w;
	int		h;

	ft_memset(tex, 0, sizeof(t_ximg) * 4);
	tex[NO].img = mlx_xpm_file_to_image(vars->mlx, vars->set.tex.north, &w, &h);
	tex[SO].img = mlx_xpm_file_to_image(vars->mlx, vars->set.tex.south, &w, &h);
	tex[WE].img = mlx_xpm_file_to_image(vars->mlx, vars->set.tex.west, &w, &h);
	tex[EA].img = mlx_xpm_file_to_image(vars->mlx, vars->set.tex.east, &w, &h);
	if (!tex[NO].img || !tex[SO].img || !tex[WE].img || !tex[EA].img)
	{
		ft_putendl_fd("No texture was fount", 0);
		exit(0);
	}
	tex[NO].addr = (int32_t *)mlx_get_data_addr(tex[NO].img, &tex[NO].bpp,
		&tex[NO].s_line, &tex[NO].endian);
	tex[SO].addr = (int32_t *)mlx_get_data_addr(tex[SO].img, &tex[SO].bpp,
		&tex[SO].s_line, &tex[SO].endian);
	tex[WE].addr = (int32_t *)mlx_get_data_addr(tex[WE].img, &tex[WE].bpp,
		&tex[WE].s_line, &tex[WE].endian);
	tex[EA].addr = (int32_t *)mlx_get_data_addr(tex[EA].img, &tex[EA].bpp,
		&tex[EA].s_line, &tex[EA].endian);
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

void	init_all(t_vars *vars, int argc, char **argv)
{
	vars->set = settings(argc, argv);
	vars->rays = malloc(sizeof(t_rays) * vars->set.resolution.w);

	ft_putarraydelim_fd(vars->set.map, '\n', 1);
	set_player(&vars->player, vars->set);
	vars->mlx = mlx_init();
	set_window(&vars->set, vars->mlx);
	vars->window = mlx_new_window(vars->mlx, vars->set.resolution.w,
		vars->set.resolution.h, "3DCub");
	vars->renderer = mlx_create_renderer(vars->mlx, vars->set.resolution.w,
		vars->set.resolution.h);
	load_textures(vars, vars->tex);
	load_sprites(vars, vars->s);
	free_set(&vars->set);
}
