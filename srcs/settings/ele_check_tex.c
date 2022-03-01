/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_check_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:31:29 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:33:27 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	validate_tex(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}
