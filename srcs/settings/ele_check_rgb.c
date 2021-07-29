/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_check_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:31:25 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 10:31:26 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	isordered(char *str)
{
	if (!ft_isdigit(*str) && !ft_isspace(*str))
		return (0);
	str = ft_skipctype(str, ft_isdigit, 1);
	str = ft_skipctype(str, ft_isspace, 1);
	if (*str++ != ',')
		return (0);
	if (!ft_isdigit(*str) && !ft_isspace(*str))
		return (0);
	str = ft_skipctype(str, ft_isspace, 1);
	if (!ft_isdigit(*str))
		return (0);
	str = ft_skipctype(str, ft_isdigit, 1);
	str = ft_skipctype(str, ft_isspace, 1);
	if (*str++ != ',')
		return (0);
	if (!ft_isdigit(*str) && !ft_isspace(*str))
		return (0);
	str = ft_skipctype(str, ft_isspace, 1);
	if (!ft_isdigit(*str))
		return (0);
	return (1);
}

static size_t	n_numbers(char *str)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			while (ft_isdigit(*str))
				str++;
			n++;
			continue ;
		}
		str++;
	}
	return (n);
}

static size_t	n_commas(char *str)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		if (*str == ',')
		{
			n++;
			str++;
			continue ;
		}
		str++;
	}
	return (n);
}

static bool	v_character(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str) && *str != ',')
			return (true);
		str++;
	}
	return (false);
}

int	validate_RGB(char *str)
{
	t_vRGB	rgb;

	rgb.charac = false;
	rgb.comma = 0;
	rgb.digit = 0;
	rgb.charac = v_character(str);
	rgb.digit = n_numbers(str);
	rgb.comma = n_commas(str);
	if (rgb.charac || rgb.digit != 3 || rgb.comma != 2)
		return (0);
	if (!isordered(str))
		return (0);
	return (1);
}
