#include "cub.h"

void	exit_cub_settings(t_sval *val, t_inv inv, int fd)
{
	if (inv.ch)
		ft_putendl_fd("\nInvalid command line\n", 0);
	else if (inv.tex)
		ft_putendl_fd("\nInvalid texture\n", 0);
	else if (inv.res)
		ft_putendl_fd("\nInvalid resolution\n", 0);
	else if (inv.rgb)
		ft_putendl_fd("\nInvalid rgb color\n", 0);
	else if (inv.empty)
		ft_putendl_fd("\nEmptyfile\n", 0);
	else if (inv.dkey)
		ft_putendl_fd("\nDouble command line\n", 0);
	free_all(val);
	close(fd);
	exit(0);
}

void	exit_elements(t_sval *val, int fd)
{
	if (val->str)
		free(val->str);
	free_all(val);
	close(fd);
	exit(0);
}
