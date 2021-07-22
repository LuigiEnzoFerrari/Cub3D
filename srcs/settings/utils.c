#include "cub.h"

int	istexture(char *str)
{
	if ((*str == 'S' && *(str + 1) != 'O')
		|| (*str == 'N' && *(str + 1) == 'O')
		|| (*str == 'E' && *(str + 1) == 'A')
		|| (*str == 'S' && *(str + 1) == 'O')
		|| (*str == 'W' && *(str + 1) == 'E'))
		return (1);
	return (0);
}

char	*get_values(char *str)
{
	char	*ptr;

	str = ft_skipctype(str, ft_isspace, 1);
	ptr = ft_strdup(str);
	return (ptr);
}

void	free_all(t_sval *val)
{
	if (val->cvalues.south)
		free(val->set.tex.south);
	if (val->cvalues.north)
		free(val->set.tex.north);
	if (val->cvalues.east)
		free(val->set.tex.east);
	if (val->cvalues.west)
		free(val->set.tex.west);
	if (val->cvalues.sprit)
		free(val->set.tex.sprit);
}
