#include "cub.h"

static size_t	len_map(char *map_line)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*map_line)
	{
		if (*map_line == '1')
			len = i;
		i++;
		map_line++;
	}
	return (len + 1);
}

size_t	size_map(char **map)
{
	size_t	len;
	size_t	maxlen;

	len = 0;
	while (*map)
	{
		maxlen = len_map(*map);
		if (maxlen > len)
			len = maxlen;
		map++;
	}
	return (len);
}

static int	iswhite(char **str, int i)
{
	while (*str)
	{
		if (*(*str + i) != ' ')
			return (0);
		str++;
	}
	return (1);
}

int	n_whitecolumn(char **str)
{
	size_t	i;

	i = 0;
	while (iswhite(str, i))
		i++;
	return (i);
}
