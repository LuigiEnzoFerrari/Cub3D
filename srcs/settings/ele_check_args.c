/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_check_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:55:24 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 21:55:34 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	file_error(uint8_t n)
{
	if (n == 1)
		ft_putendl_fd("Invalid number of arguments", 0);
	else if (n == 2)
		ft_putendl_fd("Missing something", 0);
	else if (n == 3)
		ft_putendl_fd("Invalid file extension", 0);
	else if (n == 5)
		ft_putendl_fd("File .cub not found:", 0);
	exit(0);
}
