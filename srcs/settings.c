#include "cube.h"

void	bibalit(t_inv *inv, t_sval *val)
{
	if (inv->ch)
		ft_putendl_fd("\n\ninvalid command line\n\n", 1);
	else if (inv->tex)
		ft_putendl_fd("\n\ninvalid texture\n\n", 1);
	else if (inv->res)
		ft_putendl_fd("\n\ninvalid resolution\n\n", 1);
	else if (inv->rgb)
		ft_putendl_fd("\n\ninvalid rgb color\n\n", 1);
	else if (inv->empty)
		ft_putendl_fd("\n\nemptyfile\n\n", 1);
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
