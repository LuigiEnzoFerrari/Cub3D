#include "cub.h"

static void	set_map(t_sval *val, int fd)
{
	t_list	*map;

	check_befor_map(val, fd);
	check_chr_get_map(&map, val, fd);
	check_after_map(val, fd, &map);
	val->set.map = cpy_map(map);
	ft_lstclear(&map, free);
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
	int	fd;
	t_sval val;

	fd = open("./srcs/sett.cub", O_RDONLY);
	init_val(&val);
	set_elements(&val, fd);
	set_map(&val, fd);
	printall(&val);
	ft_putarraydelim_fd(val.set.map, '\n', 1);
	// free_all(&val);
	// ft_arrayfree(val.set.map);
	close(fd);
	return (val.set);
}
