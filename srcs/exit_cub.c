#include "cub.h"

void	exit_cub_settings(t_sval *val, t_inv inv)
{
	if (inv.ch)
		ft_putendl_fd("\n\ninvalid command line\n\n", 0);
	else if (inv.tex)
		ft_putendl_fd("\n\ninvalid texture\n\n", 0);
	else if (inv.res)
		ft_putendl_fd("\n\ninvalid resolution\n\n", 0);
	else if (inv.rgb)
		ft_putendl_fd("\n\ninvalid rgb color\n\n", 0);
	else if (inv.empty)
		ft_putendl_fd("\n\nemptyfile\n\n", 0);
	else if (inv.dkey)
		ft_putendl_fd("\n\ndouble command line\n\n", 0);
	free_all(val);
	exit(0);
}
