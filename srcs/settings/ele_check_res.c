/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_check_res.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:31:21 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:35:12 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	n_numbers_res(char *str)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			str = ft_skipctype(str, ft_isdigit, 1);
			n++;
			continue ;
		}
		str++;
	}
	return (n);
}

static int	v_character_res(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

int	validate_res(char *str)
{
	if (n_numbers_res(str) != 2 || !v_character_res(str))
		return (0);
	return (1);
}
