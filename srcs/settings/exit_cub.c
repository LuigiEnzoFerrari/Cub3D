#include "cub.h"

static void	free_textures(t_sval *val)
{
	if (val->cvalues.south)
		free(val->set.tex.south);
	if (val->cvalues.north)
		free(val->set.tex.north);
	if (val->cvalues.east)
		free(val->set.tex.east);
	if (val->cvalues.west)
		free(val->set.tex.west);
	if (val->cvalues.sprit)
		free(val->set.tex.sprit);
}

void	exit_cub_settings(t_sval *val, t_inv inv, int fd)
{
	if (inv.ch)
		ft_putendl_fd("Invalid command line\n", 0);
	else if (inv.tex)
		ft_putendl_fd("Invalid texture\n", 0);
	else if (inv.res)
		ft_putendl_fd("Invalid resolution\n", 0);
	else if (inv.rgb)
		ft_putendl_fd("Invalid rgb color\n", 0);
	else if (inv.empty)
		ft_putendl_fd("Empty file\n", 0);
	else if (inv.dkey)
		ft_putendl_fd("Double command line\n", 0);
	free_textures(val);
	close(fd);
	exit(0);
}

void	exit_elements(t_sval *val, int fd)
{
	if (val->str)
		free(val->str);
	free_textures(val);
	close(fd);
	exit(0);
}
