/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayslen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:26:59 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 22:27:00 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string2d.h"

size_t	ft_arrayslen(char **array)
{
	size_t	len;

	len = 0;
	while (*array)
	{
		len += ft_strlen(*array);
		array++;
	}
	return (len);
}
