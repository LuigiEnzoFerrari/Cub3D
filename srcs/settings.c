#include "cube.h"

int		check_lines(t_sval *val)
{
	if (!val->str || !*val->str)
		return (1);
	else if (*val->str == '1')
		return (1);
	return (0);
}

int	isvalid(int c)
{
	if (c == 'S'
		|| c == 'N' || c == 'E' || c == 'R'
		|| c == 'W' || c == 'F' || c == 'C')
		return (1);
	return (0);
}

void	free_all(t_sval *val)
{
	free(val->tex.south);
	free(val->tex.north);
	free(val->tex.east);
	free(val->tex.west);
	free(val->tex.sprit);
}

void	printall(t_sval *val)
{
	// ft_putendl_fd(val->tex.south, 1);
	// ft_putendl_fd(val->tex.north, 1);
	// ft_putendl_fd(val->tex.east, 1);
	// ft_putendl_fd(val->tex.west, 1);
	// ft_putendl_fd(val->tex.sprit, 1);
	printf(":%s:\n", val->tex.south);
	printf(":%s:\n", val->tex.north);
	printf(":%s:\n", val->tex.east);
	printf(":%s:\n", val->tex.west);
	printf(":%s:\n", val->tex.sprit);
	fprintf(stdout, "%d: %d: %d:\n", val->folor.r, val->folor.g, val->folor.b);
	fprintf(stdout, "%d: %d: %d:\n", val->color.r, val->color.g, val->color.b);
	ft_putnbr(val->resolution.w);
	ft_putchar('\n');
	ft_putnbr(val->resolution.h);
	ft_putchar('\n');

}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		ft_putendl_fd(lst->content, 1);
		lst = lst->next;
	}
}

void	settings(t_sval *val)
{
	int fd;

	fd = open ("./srcs/sett.cub", O_RDONLY);
	while (true)
	{
		rm_whitelines(val, fd);
		save_configs(val);
		if (check_lines(val))
			break ;
		free(val->str);
	}
	printall(val);
	free_all(val);
	save_map(val, fd);
}
