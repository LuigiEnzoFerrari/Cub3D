/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:32:46 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/31 00:39:18 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

static void	set_args(int argc, char **argv, int *fd)
{
	if (argc < 2 || argc > 3)
		file_error(1 << 1);
	else if (!argv[1])
		file_error(1 << 2);
	if (!ft_strrchr(argv[1], '.'))
		file_error(1 << 3);
	else if(ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 4))
		file_error(1 << 4);
	else if (argc == 3 && ft_memcmp(argv[2], "--save", 6))
		file_error(1 << 5);
	*fd = open(argv[1], O_RDONLY);
	if (*fd <= 0)
		file_error(1 << 6);
}

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

t_set	settings(int argc, char **argv)
{
	int		fd;
	t_sval	val;

	set_args(argc, argv, &fd);
	init_val(&val);
	set_elements(&val, fd);
	set_map(&val, fd);
	printall(&val);
	close(fd);
	return (val.set);
}
