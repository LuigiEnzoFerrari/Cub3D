/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_get_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:31:51 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 10:31:52 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_RES	get_RES(char *str)
{
	char	*ptr;
	t_RES	res;

	ptr = str;
	str = ft_skipctype(str, ft_isdigit, 0);
	res.w = ft_atoi(str);
	str = ft_skipctype(str, ft_isdigit, 1);
	str = ft_skipctype(str, ft_isdigit, 0);
	res.h = ft_atoi(str);
	str = ft_skipctype(str, ft_isdigit, 1);
	free(ptr);
	return (res);
}

void	get_R(t_sval *val)
{
	char	*str;

	str = val->str;
	str = get_values(val->str + 1);
	if (!validate_RES(str))
	{
		free(str);
		val->cvalues.inv.res = true;
	}
	else if (val->cvalues.resol)
	{
		val->cvalues.inv.dkey = true;
		free(str);
	}
	else
	{
		val->set.resolution = get_RES(str);
		val->cvalues.resol = true;
	}
}
