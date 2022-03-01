/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:33:17 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:41:54 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>

# include <stdbool.h>

# include "libft.h"
# include "libft2d.h"

# include "struct.h"
# include "cub_settings.h"

# include "mlx_extension.h"

# include "const.h"
# include <fcntl.h>
# include <float.h>
# include <math.h>

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define ITEM 0

typedef struct s_vars
{
	void		*window;
	void		*mlx;
	t_set		set;
	t_P1		player;
	t_rays		*rays;
	t_xrenderer	renderer;
	t_ximg		tex[4];
}	t_vars;

void	init_all(t_vars *vars, int argc, char **argv);
void	set_player(t_P1 *player, t_set set);
void	printall(t_sval *val);

void	map_basic_check(t_list **map, t_sval *val, int fd);
int		map_basic_line(char *str, t_cmap *cmap);
void	get_map(t_sval *val, int fd);

void	input(t_vars *vars);
void	update(t_vars *vars);
int		render(t_vars *vars);

int		key_pressed(int event, t_vars *vars);
int		key_released(int event, t_vars *vars);
int		key_exit(t_vars *vars);

void	rays_casting(t_vars *vars);
int		has_wall(t_set set, double x, double y);
void	player(t_vars *vars);
void	found_wall_horiz(t_vars vars, t_rays *rays, t_casting *cast);
void	found_wall_vert(t_vars vars, t_rays *rays, t_casting *cast);
void	minimum_distance(t_vars vars, t_rays *rays, t_casting *cast);

void	background(t_xrenderer *renderer, t_set set);
void	player_position(t_vars *vars);
void	rays(t_vars *vars);
void	map(t_vars *vars);
void	projection(t_vars *vars, t_rays *rays, t_P1 player, t_set set);

#endif
