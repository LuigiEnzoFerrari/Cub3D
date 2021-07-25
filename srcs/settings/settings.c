#include "cub.h"

static void	set_map(t_sval *val, int fd)
{
	get_check_map(val, fd);
	map_clear_spaces(val);
	// check_map(val, fd);
}

static void	set_elements(t_sval *val, int fd)
{
	while (true + true)
	{
		clr_whitespaces(val, fd);
		save_configs(val);
		free(val->str);
		if (check_configs(val, fd))
			break ;
	}
}

t_set	settings(void)
{
	int		fd;
	t_sval	val;

	fd = open("./srcs/sett.cub", O_RDONLY);
	init_val(&val);
	set_elements(&val, fd);
	set_map(&val, fd);
	printall(&val);
	ft_putarraydelim_fd(val.set.map, '\n', 1);
	free_all(&val);
	ft_arrayfree(val.set.map);
	close(fd);
	return (val.set);
}
