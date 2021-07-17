#ifndef MLX_EXTENSION_H
#define MLX_EXTENSION_H

# include <stdint.h>
# include <stddef.h>

typedef struct mlx_Rect
{
	int	x;
	int	y;
	int	w;
	int	h;
}	mlx_Rect;

typedef struct mlx_Point
{
	int	x;
	int	y;
}	mlx_Point;

typedef struct mlx_Color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	mlx_Color;

#endif
