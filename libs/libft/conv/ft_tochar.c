/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tochar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:13:54 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/07 17:24:35 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tochar(long n)
{
	if (n < 0)
		n = -n;
	return ((n % 10) + '0');
}