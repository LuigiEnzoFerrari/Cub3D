/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:33:14 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 22:39:59 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SETTINGS_H
# define CUB_SETTINGS_H

# include "struct.h"

typedef struct s_invalid_map
{
	bool	player;
	bool	dplayer;
	bool	x_split;
	bool	y_split;
}	t_cmap;

typedef struct s_invalid
{
	bool	ch;
	bool	rgb;
	bool	tex;
	bool	res;
	bool	map;
	bool	empty;
	bool	dkey;
}	t_inv;

typedef struct s_check
{
	bool	south;
	bool	north;
	bool	east;
	bool	west;
	bool	sprit;
	bool	floor;
	bool	color;
	bool	resol;
	t_inv	inv;
}	t_check;

typedef struct s_vRGB
{
	size_t	comma;
	size_t	digit;
	bool	charac;
}	t_vRGB;

typedef struct s_set_values
{
	char	*str;
	int		fd;
	t_check	cvalues;
	t_cmap	cmap;
	t_set	set;
}	t_sval;

t_set	settings(int argc, char **argv);
void	file_error(uint8_t n);

void	clr_whitespaces(t_sval *val, int fd);
void	clr_whitelines(t_sval *val, int fd);
void	save_configs(t_sval *val);
int		isvalid(int c);
void	init_val(t_sval *val);

int		validate_RGB(char *str);
int		validate_RES(char *str);
int		validate_TEX(char *str);

void	print_lst(t_list *lst);
int		check_configs(t_sval *val, int fd);
void	exit_cub_settings(t_sval *val, t_inv inv, int fd);
void	exit_elements(t_sval *val, int fd);
void	free_textures(t_sval *val);

void	get_TEX(t_sval *val);
void	get_R(t_sval *val);
void	get_FC(t_sval *val);
char	*get_values(char *str);
int		istexture(char *str);

void	map_clear_spaces(t_sval *val);
size_t	size_map(char **map);
size_t	len_map(char *map_line);
int		n_whitecolumn(char **str);
void	check_map(t_sval *val, int fd);
int		iswhite(char **str, int i);
void	replace_map(char *map, char *ptr, size_t x);
int		hasWhiteColomns(char **str);
int		map_line(char *map_line);
int		map_column(char **map);

#endif
