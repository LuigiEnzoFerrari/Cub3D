/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:28:16 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 22:28:17 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING2D_H
# define STRING2D_H
# include "libft.h"

size_t	ft_arrayslen(char **array);
size_t	ft_arraysmaxlen(char **array);
size_t	ft_arraylen(char **array);
char	**ft_arraydup(char **array);
void	ft_arrayfree(char **array);

#endif
