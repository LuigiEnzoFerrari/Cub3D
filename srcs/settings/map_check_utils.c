#include "cub.h"

int	map_line(char *map_line)
{
	while (*map_line == ' ')
		map_line++;
	while (*map_line)
	{
		if (map_line[1] == ' ')
		{
			if (*map_line++ != '1')
				return (0);
			while (*map_line == ' ')
				map_line++;
			if (*map_line == '\0')
				return (1);
			else if (*map_line != '1')
				return (0);
		}
		map_line++;
	}
	return (1);
}

int	hasWhiteColomns(char **str)
{
	size_t	i;

	i = 0;
	while (!iswhite(str, i))
	{
		if (*(*str + i) == '\0')
			return (0);
		i++;
	}
	return (1);
}