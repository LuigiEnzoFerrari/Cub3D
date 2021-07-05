#include "cub.h"

void	bibalit(t_sval *val)
{

	free_all(val);
}

void	settings(t_sval *val)
{
	int fd;

	fd = open ("./srcs/sett.cub", O_RDONLY);
	init_val(val);
	while (true)
	{
		rm_whitelines(val, fd);
		save_configs(val);
		free(val->str);
		if (check_configs(val))
			break ;
	}
	free_all(val);
	ft_putendl_fd("\n\nallgood\n\n", 1);
	// free(val->str);
	// save_map(val, fd);
}
