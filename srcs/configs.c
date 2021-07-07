#include "cub.h"

void	save_configs(t_sval *val)
{
	char	*str;

	str = val->str;
	if (istexture(str))
		get_TEX(val);
	else if (*str == 'F' || *str == 'C')
		get_FC(val);
	else if (*str == 'R')
		get_R(val);
	else if (*str == '1')
		val->cvalues.inv.map = true;
	else if (*str == '\0')
		val->cvalues.inv.empty = true;
	else
		val->cvalues.inv.ch = true;
}
