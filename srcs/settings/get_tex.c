#include "cub.h"

static void	set_tex(char **tex, char **ptr, bool *v_tex, t_inv *cvalues)
{
	if (*v_tex == false)
		*v_tex = true;
	else
	{
		cvalues->dkey = true;
		free(*ptr);
		return ;
	}
	*tex = *ptr;
}

void	get_TEX(t_sval *val)
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