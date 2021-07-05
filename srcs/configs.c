#include "cub.h"

t_RGBA	get_RGB(char *str)
{
	t_RGBA	rgb;
	char	*ptr;

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

t_RES	get_RES(char *str)
{
	char	*ptr;
	t_RES	res;

	ptr = str;
	str = ft_skipctype(str, ft_isdigit, 0);
	res.w = ft_atoi(str);
	str = ft_skipctype(str, ft_isdigit, 1);
	str = ft_skipctype(str, ft_isdigit, 0);
	res.h = ft_atoi(str);
	str = ft_skipctype(str, ft_isdigit, 1);
	free(ptr);
	return (res);
}

static void	set_tex(char **tex, char **ptr, bool *v_tex, t_inv *cvalues)
{
	if (!*v_tex)
		*v_tex = true;
	else
	{
		cvalues->dkey = true;
		free(*ptr);
		return ;
	}
	*tex = *ptr;
}

static char	*get_values(char *str)
{
	char	*ptr;

	str = ft_skipctype(str, ft_isspace, 1);
	ptr = ft_strdup(str);
	return (ptr);
}

static void	get_R(t_sval *val)
{
	char	*str;

	str = val->str;
	str = get_values(val->str + 1);
	if (!validate_RES(str))
	{
		free(str);
		val->cvalues.inv.res = true;
		return ;
	}
	val->resolution = get_RES(str);
	val->cvalues.resol = true;
}

static void	get_FC(t_sval *val)
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
	{
		val->floor = get_RGB(str);
		val->cvalues.floor = true;
	}
	else if (*val->str == 'C')
	{
		val->color = get_RGB(str);
		val->cvalues.color = true;
	}
}

static void	get_TEX(t_sval *val)
{
	char	*str;
	char	*ptr;

	str = val->str;
	if ((*str == 'S' && *(str + 1) != 'O'))
		ptr = get_values(str + 1);
	else
		ptr = get_values(str + 2);
	if (!validate_TEX(ptr))
	{
		val->cvalues.inv.tex = true;
		free(ptr);
	}
	else if (*str == 'S' && *(str + 1) != 'O')
		set_tex(&val->tex.sprit, &ptr, &val->cvalues.sprit, &val->cvalues.inv);
	else if (*str == 'N' && *(str + 1) == 'O')
		set_tex(&val->tex.north, &ptr, &val->cvalues.north, &val->cvalues.inv);
	else if (*str == 'E' && *(str + 1) == 'A')
		set_tex(&val->tex.east, &ptr, &val->cvalues.east, &val->cvalues.inv);
	else if (*str == 'S' && *(str + 1) == 'O')
		set_tex(&val->tex.south, &ptr, &val->cvalues.south, &val->cvalues.inv);
	else if (*str == 'W' && *(str + 1) == 'E')
		set_tex(&val->tex.west, &ptr, &val->cvalues.west, &val->cvalues.inv);
}

void	save_configs(t_sval *val)
{
	char	*str;

	str = val->str;

	if ((*str == 'S' && *(str + 1) != 'O')
		|| (*str == 'N' && *(str + 1) == 'O')
		|| (*str == 'E' && *(str + 1) == 'A')
		|| (*str == 'S' && *(str + 1) == 'O')
		|| (*str == 'W' && *(str + 1) == 'E'))
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
