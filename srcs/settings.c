#include "cub.h"

static void	set_map(t_sval *val, int fd)
{
	t_list	*map;

	check_inv_ch(val, fd);
	get_map(&map, val, fd);
	check_inv_end(val, fd, &map);
	val->map = cpy_map(map);
	ft_lstclear(&map, free);
}

static void	set_elements(t_sval *val, int fd)
{
	while (true)
	{
		clr_whitespaces(val, fd);
		save_configs(val);
		free(val->str);
		if (check_configs(val, fd))
			break ;
	}
}

void	settings(t_sval *val)
{
	int	fd;

	fd = open("./srcs/sett.cub", O_RDONLY);
	init_val(val);
	set_elements(val, fd);
	set_map(val, fd);
	printall(val);
	free_all(val);
	ft_putarraydelim_fd(val->map, '\n', 1);
	ft_arrayfree(val->map);
	close(fd);
}
