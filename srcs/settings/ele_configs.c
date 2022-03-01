/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_configs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:54:25 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 13:38:26 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	save_configs(t_sval *val)
{
	char	*str;

	str = val->str;
	if (istexture(str))
		get_tex(val);
	else if (*str == 'F' || *str == 'C')
		get_fc(val);
	else if (*str == 'R')
		get_r(val);
	else if (*str == '1')
		val->cvalues.inv.map = true;
	else if (*str == '\0')
		val->cvalues.inv.empty = true;
	else
		val->cvalues.inv.ch = true;
}
