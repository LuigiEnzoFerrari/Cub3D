#include "cub.h"

size_t	len_map(char *map_line)
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

void	replace_map(char *map, char *ptr, size_t x)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = len_map(map);
	while (i < len)
	{
		ptr[i]	= map[i];
		i++;
	}
	while (i < x)
	{
		ptr[i] = ' ';
		i++;
	}
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

int	iswhite(char **str, int i)
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
