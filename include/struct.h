#ifndef STRUCT_H
# define STRUCT_H

# include <stdint.h>
# include <stddef.h>
# include "mlx_extension.h"
# include "const.h"

typedef struct s_Resolution // to points later
{
	int	w;
	int	h;
}	t_RES;

typedef struct s_TEX
{
	char	*south;
	char	*north;
	char	*west;
	char	*east;
	char	*sprit;
}	t_TEX;

typedef struct s_setting
{
	char		**map;
	t_TEX		tex;
	int			cell;
	int			floor;
	t_RES		resolution;
}	t_set;


typedef struct s_player
{
	float	x;
	float	y;
	float	w;
	float	h;
	int		r;
	int		turnDirection;
	int		walkDirection;
	double	fov;
	double	rotationAngle;
	float	walkSpeed;
	float	turnSpeed;
}	t_P1;

typedef struct s_ray
{
	float	rayAngle;
	float	wallHitX;
	float	wallHitY;
	float	distance;
	int		wasHisVerical;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	int		wallHitContent;
}	t_rays;

void	init_RES(t_RES *res);
void	init_TEX(t_TEX *tex);

#endif
