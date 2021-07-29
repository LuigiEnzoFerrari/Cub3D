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
	t_xPoint	map_size;
}	t_set;

typedef struct s_player
{
	double	x;
	double	y;
	int		r;
	int		tD;
	double	wDFB;
	double	wDLR;
	double	fov;
	double	rAngle;
	double	wS;
	double	tS;
}	t_P1;

typedef struct s_ray
{
	double	angle;
	double	wallHitX;
	double	wallHitY;
	double	distance;
	bool	isVert;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	int		wallHitContent;
}	t_rays;

typedef struct s_rayCasting
{
	bool		hit;
	t_xFPoint	wallHit;
	int			wallContent;
}	t_casting;

typedef struct s_intercept
{
	t_xFPoint	intercept;
	t_xFPoint	step;
}	t_inter;

typedef struct s_prjection
{
	double	perDistance;
	double	projDistance;
	double	projHeight;

	int		stripHeight;
	int		topPixel;
	int		bottomPixel;
}	t_proj;


#endif
