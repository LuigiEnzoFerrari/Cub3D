/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:26:51 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 22:26:52 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string2d.h"

void	ft_arrayfree(char **array)
{
	char	**ptr;

	ptr = array;
	while (*array)
	{
		free(*array);
		array++;
	}
	free(ptr);
}
