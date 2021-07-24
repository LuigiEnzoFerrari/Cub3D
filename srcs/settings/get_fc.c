#include "cub.h"

static t_xColor	get_RGB(char *str)
{
	t_xColor	rgb;
	char		*ptr;

	ptr = str;
	str = ft_skipctype(str, ft_isdigit, 0);
	rgb.r = ft_atoi(str);
	str = ft_skipctype(str, ft_isdigit, 1);
	str = ft_skipctype(str, ft_isdigit, 0);
	rgb.g = ft_atoi(str);
	str = ft_skipctype(str, ft_isdigit, 1);
	str = ft_skipctype(str, ft_isdigit, 0);
	rgb.b = ft_atoi(str);
	free(ptr);
	return (rgb);
}

static void	set_FC(char *str, bool *rgb, t_xColor *rgba, t_check *cvalues)
{
	if (*rgb == true)
	{
		cvalues->inv.dkey = true;
		free(str);
		return ;
	}
	*rgba = get_RGB(str);
	*rgb = true;
}

void	get_FC(t_sval *val)
{
	char	*str;

	str = val->str;
	str = get_values(val->str + 1);
	if (!validate_RGB(str))
	{
		val->cvalues.inv.rgb = true;
		free(str);
	}
	else if (*val->str == 'F')
		set_FC(str, &val->cvalues.floor, &val->set.floor, &val->cvalues);
	else if (*val->str == 'C')
		set_FC(str, &val->cvalues.color, &val->set.cell, &val->cvalues);
}
