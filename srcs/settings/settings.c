/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:32:46 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 12:41:13 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_map(t_sval *val, int fd)
{
	get_map(val, fd);
	map_clear_spaces(val);
	check_map(val, fd);
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
	// free_textures(&val);
	// ft_arrayfree(val.set.map);
	close(fd);
	return (val.set);
}
