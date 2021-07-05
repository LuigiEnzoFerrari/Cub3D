#include "cub.h"

int	validate_TEX(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}
