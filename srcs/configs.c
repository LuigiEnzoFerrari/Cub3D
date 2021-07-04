#include "cube.h"

t_RGBA	get_rgb(char *str)
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

t_RES	get_res(char *str)
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
		printf("ojaijoj\n");
		return ;
	}
	val->resolution = get_res(str);
}

static void	get_FC(t_sval *val)
{
	char	*str;

	str = val->str;
	str = get_values(val->str + 1);
	if (!validate_RGB(str))
	{
		printf(":-:\n:-:\n:-:totalmenteinvalido\n:-:\n:-:\n:-:");
		free(str);
		return ;
	}
	if (*val->str == 'F')
		val->folor = get_rgb(str);
	else if (*val->str == 'C')
		val->color = get_rgb(str);
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
		printf("pera\n");
	}
	if (*str == 'S' && *(str + 1) != 'O')
		val->tex.sprit = ptr;
	else if (*str == 'N' && *(str + 1) == 'O')
		val->tex.north = ptr;
	else if (*str == 'E' && *(str + 1) == 'A')
		val->tex.east = ptr;
	else if (*str == 'S' && *(str + 1) == 'O')
		val->tex.south = ptr;
	else if (*str == 'W' && *(str + 1) == 'E')
		val->tex.west = ptr;
	
}

static void	save_values(t_sval *val)
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
	// else
		// do someshit;
}

void	save_configs(t_sval *val)
{
	// if (isvalid(*val->str))
	save_values(val);
}