#ifndef MLX_EXTENSION_H
# define MLX_EXTENSION_H

# include <stdint.h>
# include <stddef.h>

#include "mlx.h"

typedef struct mlx_Rect
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_xRect;

typedef struct mlx_Circle
{
	int	x;
	int y;
	int	r;
}	t_xCircle;

typedef struct mlx_Point
{
	int	x;
	int	y;
}	t_xPoint;

typedef struct mlx_Line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_xLine;

typedef struct mlx_Color
{
	uint8_t	t;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_xColor;

typedef struct mlx_Renderer
{
	void	*img;
	char	*addr;
	int		bpp;
	int		s_line;
	int		endian;
	int		color;
}	t_xRenderer;

typedef struct s_Bresenham_line
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;
}	t_BLine;

void	mlx_put_pixel(t_xRenderer *renderer, int x, int y);
void	mlx_draw_line(t_xRenderer *renderer, t_xLine line);
void	mlx_draw_fill_rect(t_xRenderer *renderer, t_xRect);
void	mlx_draw_circle(t_xRenderer *renderer, t_xCircle circle);
void	mlx_set_render_color(t_xRenderer *renderer, int color);
void	mlx_render_present(void *mlx, void *win, void *img);


t_xLine	mlx_get_line(int x0, int y0, int x1, int y1);
t_xRect	mlx_get_rect(int x, int y, int w, int h);
t_xCircle	mlx_get_circle(int x, int y, int r);
t_xRenderer	mlx_create_renderer(void *mlx, int size_x, int size_y);

int		mlx_get_hex_trgb(uint8_t t, uint8_t r, uint8_t g, uint8_t b);


#endif
