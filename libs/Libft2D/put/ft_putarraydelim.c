/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarraydelim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:27:19 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 22:27:20 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put2d.h"

void	ft_putarraydelim(char **array, int c)
{
	while (*array)
	{
		ft_putstr(*array++);
		ft_putchar(c);
	}
}
