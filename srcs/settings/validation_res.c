#include "cub.h"

static int	n_numbers_res(char *str)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			str = ft_skipctype(str, ft_isdigit, 1);
			n++;
			continue ;
		}
		str++;
	}
	return (n);
}

static int	v_character_res(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

int	validate_RES(char *str)
{
	if (n_numbers_res(str) != 2 || !v_character_res(str))
		return (0);
	return (1);
}
