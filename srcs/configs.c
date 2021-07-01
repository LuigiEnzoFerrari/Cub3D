#include "cube.h"

t_RGBA	get_rgb(char *str)
{
	t_RGBA	rgb;
	char	*fire;

	fire = str;
	while (!ft_isdigit(*str))
		str++;
	rgb.r = ft_atoi(str);
	str += ft_nbrlen(rgb.r);
	while (!ft_isdigit(*str))
		str++;
	rgb.g = ft_atoi(str);
	str += ft_nbrlen(rgb.r);
	while (!ft_isdigit(*str))
		str++;
	rgb.b = ft_atoi(str);
	free(fire);
	return (rgb);
}

t_RES	get_res(char *str)
{
	char	*fire;
	t_RES	res;

	fire = str;
	while (!ft_isdigit(*str))
		str++;
	res.w = ft_atoi(str);
	str += ft_nbrlen(res.w);
	while (!ft_isdigit(*str))
		str++;
	res.h = ft_atoi(str);
	str += ft_nbrlen(res.h);
	free(fire);
	return (res);
}

static char	*get_values(char *str)
{
	char	*ptr;

	while (ft_isspace(*str))
		str++;
	ptr = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	strcpy(ptr, str);
	return (ptr);
}

static void	get_RFC(t_sval *val)
{
	char	*str;

	str = val->str;
	str = get_values(val->str + 1);
	if (*val->str == 'F')
		val->folor = get_rgb(str);
	else if (*val->str == 'C')
		val->color = get_rgb(str);
	else if (*val->str == 'R')
		val->resolution = get_res(str);
}

static void	save_values(t_sval *val)
{
	char	*str;

	str = val->str;
	if (*str == 'S' && *(str + 1) != 'O')
		val->tex.sprit = get_values(str + 1);
	else if (*str == 'N' && *(str + 1) == 'O')
		val->tex.north = get_values(str + 2);
	else if (*str == 'E' && *(str + 1) == 'A')
		val->tex.east = get_values(str + 2);
	else if (*str == 'S' && *(str + 1) == 'O')
		val->tex.south = get_values(str + 2);
	else if (*str == 'W' && *(str + 1) == 'E')
		val->tex.west = get_values(str + 2);
	else if (*str == 'F' || *str == 'C')
		get_RFC(val);
	else if (*str == 'R')
		get_RFC(val);
	// else
		// do someshit;
}

void	save_configs(t_sval *val)
{
	// if (isvalid(*val->str))
		save_values(val);
}