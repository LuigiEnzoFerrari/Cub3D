#include "cub.h"

void	free_all(t_sval *val)
{
	if (val->cvalues.south)
		free(val->tex.south);
	if (val->cvalues.north)
		free(val->tex.north);
	if (val->cvalues.east)
		free(val->tex.east);
	if (val->cvalues.west)
		free(val->tex.west);
	if (val->cvalues.sprit)
		free(val->tex.sprit);
}

void	printall(t_sval *val)
{
	if (val->cvalues.south)
		ft_putendl_fd("ok_south", 1);
	else
		ft_putendl_fd("ko_south", 1);
	if (val->cvalues.north)
		ft_putendl_fd("ok_north", 1);
	else
		ft_putendl_fd("ko_north", 1);
	if (val->cvalues.east)
		ft_putendl_fd("ok_east", 1);
	else
		ft_putendl_fd("ko_east", 1);
	if (val->cvalues.west)
		ft_putendl_fd("ok_west", 1);
	else
		ft_putendl_fd("ko_west", 1);
	if (val->cvalues.sprit)
		ft_putendl_fd("ok_sprite", 1);
	else
		ft_putendl_fd("ok_sprite", 1);
	fprintf(stdout, "floor :%d: :%d: :%d:\n", val->floor.r, val->floor.g, val->floor.b);
	fprintf(stdout, "color :%d: :%d: :%d:\n", val->color.r, val->color.g, val->color.b);
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
