#include "cub.h"

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
		|| inv.map || inv.empty
		|| inv.dkey)
		return (1);
	return (0);
}

int	check_configs(t_sval *val, int fd)
{
	if (check_values(val->cvalues))
		return (1);
	else if (check_invalid(val->cvalues.inv))
		exit_cub_settings(val, val->cvalues.inv, fd);
	return (0);
}
