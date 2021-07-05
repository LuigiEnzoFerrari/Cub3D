#include "cube.h"

static int	check_values(t_check cvalues)
{
	if (cvalues.south && cvalues.north
		&& cvalues.sprit && cvalues.east
		&& cvalues.west && cvalues.color
		&& cvalues.floor && cvalues.resol)
		return (1);
	return (0);
}

static int	check_invalid(t_inv inv)
{
	if (inv.ch || inv.res
		|| inv.rgb || inv.tex
		|| inv.map || inv.empty)
		return (1);
	return (0);
}

void	exit_cub_settings(t_sval *val, t_inv inv)
{
	if (inv.ch)
		ft_putendl_fd("\n\ninvalid command line\n\n", 1);
	else if (inv.tex)
		ft_putendl_fd("\n\ninvalid texture\n\n", 1);
	else if (inv.res)
		ft_putendl_fd("\n\ninvalid resolution\n\n", 1);
	else if (inv.rgb)
		ft_putendl_fd("\n\ninvalid rgb color\n\n", 1);
	else if (inv.empty)
		ft_putendl_fd("\n\nemptyfile\n\n", 1);
	free_all(val);
	exit(0);
}

int	check_configs(t_sval *val)
{
	if (check_values(val->cvalues))
		return (1);
	else if (check_invalid(val->cvalues.inv))
		exit_cub_settings(val, val->cvalues.inv);
	return (0);
}
