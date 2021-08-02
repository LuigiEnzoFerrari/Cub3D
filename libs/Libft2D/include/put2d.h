/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:28:13 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 22:28:14 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT2D_H
# define PUT2D_H
# include "libft.h"

void	ft_putarray_fd(char **array, int fd);
void	ft_putarray(char **array);
void	ft_putarraydelim_fd(char **array, int c, int fd);
void	ft_putarraydelim(char **array, int c);

#endif
