/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:32:50 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 18:44:08 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	printall(t_sval *val)
{
	if (val->cvalues.south)
		ft_putendl_fd(val->set.tex.south, 1);
	else
		ft_putendl_fd("ko_south", 1);
	if (val->cvalues.north)
		ft_putendl_fd(val->set.tex.north, 1);
	else
		ft_putendl_fd("ko_north", 1);
	if (val->cvalues.east)
		ft_putendl_fd(val->set.tex.east, 1);
	else
		ft_putendl_fd("ko_east", 1);
	if (val->cvalues.west)
		ft_putendl_fd(val->set.tex.west, 1);
	else
		ft_putendl_fd("ko_west", 1);
	fprintf(stdout, "color :%#X:\n", val->set.floor);
	fprintf(stdout, "color :%#X:\n", val->set.cell);
	ft_putnbr(val->set.resolution.w);
	ft_putchar('\n');
	ft_putnbr(val->set.resolution.h);
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
