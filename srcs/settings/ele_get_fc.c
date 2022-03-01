/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_get_fc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:31:46 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:37:17 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_rgb(char *str)
{
	t_xcolor	rgb;
	char		*ptr;

	ptr = str;
	rgb.t = 0;
	str = ft_skipctype(str, ft_isdigit, 0);
	rgb.r = ft_atoi(str);
	str = ft_skipctype(str, ft_isdigit, 1);
	str = ft_skipctype(str, ft_isdigit, 0);
	rgb.g = ft_atoi(str);
	str = ft_skipctype(str, ft_isdigit, 1);
	str = ft_skipctype(str, ft_isdigit, 0);
	rgb.b = ft_atoi(str);
	free(ptr);
	return (mlx_get_hex_trgb(rgb.t, rgb.r, rgb.g, rgb.b));
}

static void	set_fc(char *str, bool *rgb, t_check *cvalues, int *trgb)
{
	if (*rgb == true)
	{
		cvalues->inv.dkey = true;
		free(str);
		return ;
	}
	*trgb = get_rgb(str);
	*rgb = true;
}

void	get_fc(t_sval *val)
{
	char	*str;

	str = val->str;
	str = get_values(val->str + 1);
	if (!validate_rgb(str))
	{
		val->cvalues.inv.rgb = true;
		free(str);
	}
	else if (*val->str == 'F')
		set_fc(str, &val->cvalues.floor, &val->cvalues, &val->set.floor);
	else if (*val->str == 'C')
		set_fc(str, &val->cvalues.color, &val->cvalues, &val->set.cell);
}
