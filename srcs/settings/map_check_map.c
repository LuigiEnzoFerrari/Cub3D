#include "cub.h"

static int	map_lines(char **map)
{
	while (*map)
	{
		if (!map_line(*map))
			return (0);
		map++;
	}
	return (1);
}

static int	map_colomns(char **map)
{
	if (hasWhiteColomns(map))
		return (0);
	return (1);
}

void	check_map(t_sval *val, int fd)
{
	if (!map_lines(val->set.map))
	{
		val->str = NULL;
		ft_putendl_fd("Must be close by walls", 0);
		exit_elements(val, fd);
	}
	if (!map_colomns(val->set.map))
	{
		val->str = NULL;
		ft_putendl_fd("Splited Map", 0);
		exit_elements(val, fd);
	}
	fd = 0;
}
