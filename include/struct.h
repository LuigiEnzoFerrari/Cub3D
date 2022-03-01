/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:33:27 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:22:15 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdint.h>
# include <stddef.h>
# include "mlx_extension.h"
# include "const.h"
# include <stdint.h>

typedef struct s_resolution
{
	int	w;
	int	h;
}	t_res;

typedef struct s_tex
{
	char	*south;
	char	*north;
	char	*west;
	char	*east;
}	t_tex;

typedef struct s_setting
{
	char		**map;
	t_tex		tex;
	int			cell;
	int			floor;
	t_res		resolution;
	t_xpoint	map_size;
	uint32_t	*pixel;
}	t_set;

typedef struct s_player
{
	double	x;
	double	y;
	int		r;
	int		turn_direction;
	double	walk_direction_fb;
	double	walk_direction_lr;
	double	fov;
	double	rotation_angle;
	double	dist;
	double	walk_step;
	double	turn_step;
}	t_P1;

typedef struct s_ray
{
	double	angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	bool	is_vert;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	int		wall_hit_content;
}	t_rays;

typedef struct s_raycasting
{
	bool		hit;
	t_xfpoint	wall_hit;
	int			wall_content;
}	t_casting;

typedef struct s_intercept
{
	t_xfpoint	intercept;
	t_xfpoint	step;
}	t_inter;

typedef struct s_prjection
{
	double	per_distance;
	double	distance;
	double	height;

	int		strip_height;
	int		top_pixel;
	int		bottom_pixel;
}	t_proj;

#endif
