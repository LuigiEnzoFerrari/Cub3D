/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_get_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:32:03 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 10:32:04 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*get_values(char *str)
{
	char	*ptr;

	str = ft_skipctype(str, ft_isspace, 1);
	ptr = ft_strdup(str);
	return (ptr);
}

int	istexture(char *str)
{
	if ((*str == 'S' && *(str + 1) != 'O')
		|| (*str == 'N' && *(str + 1) == 'O')
		|| (*str == 'E' && *(str + 1) == 'A')
		|| (*str == 'S' && *(str + 1) == 'O')
		|| (*str == 'W' && *(str + 1) == 'E'))
		return (1);
	return (0);
}
