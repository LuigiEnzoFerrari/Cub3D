/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_clear_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:31:35 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/07/29 10:31:36 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	white_line(char *str)
{
	str = ft_skipctype(str, ft_isspace, 1);
	return (!(*str));
}

static char	*trim_spaces(char *str)
{
	size_t	len;
	char	*ptr;

	ptr = str;
	ptr = ft_skipctype(ptr, ft_isspace, 1);
	len = ft_strlen(ptr);
	while (ft_isspace(ptr[len - 1]))
		len--;
	ptr = ft_strndup(ptr, len);
	free(str);
	return (ptr);
}

void	clr_whitelines(t_sval *val, int fd)
{
	ssize_t	r;

	r = get_next_line(fd, &val->str);
	while (white_line(val->str) && r > 0)
	{
		free(val->str);
		r = get_next_line(fd, &val->str);
	}
}

void	clr_whitespaces(t_sval *val, int fd)
{
	clr_whitelines(val, fd);
	if (*val->str)
		val->str = trim_spaces(val->str);
}
