#include "cub.h"

void	printall(t_sval *val)
{
	if (val->cvalues.south)
		ft_putendl_fd(val->tex.south, 1);
	else
		ft_putendl_fd("ko_south", 1);
	if (val->cvalues.north)
		ft_putendl_fd(val->tex.north, 1);
	else
		ft_putendl_fd("ko_north", 1);
	if (val->cvalues.east)
		ft_putendl_fd(val->tex.east, 1);
	else
		ft_putendl_fd("ko_east", 1);
	if (val->cvalues.west)
		ft_putendl_fd(val->tex.west, 1);
	else
		ft_putendl_fd("ko_west", 1);
	if (val->cvalues.sprit)
		ft_putendl_fd(val->tex.sprit, 1);
	else
		ft_putendl_fd("ok_sprite", 1);

	fprintf(stdout, "floor :%d: :%d: :%d:\n", val->floor.r, val->floor.g, val->floor.b);
	fprintf(stdout, "color :%d: :%d: :%d:\n", val->cell.r, val->cell.g, val->cell.b);
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
