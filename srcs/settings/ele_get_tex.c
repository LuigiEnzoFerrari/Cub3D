/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_get_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:31:59 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:33:27 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_tex(char **tex, char **ptr, bool *v_tex, t_inv *cvalues)
{
	if (*v_tex == false)
		*v_tex = true;
	else
	{
		cvalues->dkey = true;
		free(*ptr);
		return ;
	}
	*tex = *ptr;
}

void	get_tex(t_sval *val)
{
	char	*str;
	char	*ptr;

	str = val->str;
	ptr = get_values(str + 2);
	if (!validate_tex(ptr))
	{
		val->cvalues.inv.tex = true;
		free(ptr);
	}
	else if (*str == 'N' && *(str + 1) == 'O')
		set_tex(&val->set.tex.north, &ptr,
			&val->cvalues.north, &val->cvalues.inv);
	else if (*str == 'E' && *(str + 1) == 'A')
		set_tex(&val->set.tex.east, &ptr,
			&val->cvalues.east, &val->cvalues.inv);
	else if (*str == 'S' && *(str + 1) == 'O')
		set_tex(&val->set.tex.south, &ptr,
			&val->cvalues.south, &val->cvalues.inv);
	else if (*str == 'W' && *(str + 1) == 'E')
		set_tex(&val->set.tex.west, &ptr,
			&val->cvalues.west, &val->cvalues.inv);
}
