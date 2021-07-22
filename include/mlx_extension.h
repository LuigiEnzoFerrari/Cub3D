#ifndef MLX_EXTENSION_H
# define MLX_EXTENSION_H

# include <stdint.h>
# include <stddef.h>

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
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_xColor;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		s_line;
	int		endian;
	int		color;
}	t_data;

typedef struct s_Bresenham_line
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;
}	t_BLine;

void	mlx_put_pixel(t_data *img, int x, int y, int color);
void	mlx_draw_line(t_data *img, t_xLine line, int color);
void	mlx_draw_fill_rect(t_data *img, t_xRect, int color);
void	mlx_draw_circle(t_data *img, t_xCircle circle, int color);

t_xLine	mlx_get_line(int x0, int y0, int x1, int y1);
t_xRect	mlx_get_rect(int x, int y, int w, int h);
t_xCircle	mlx_get_circle(int x, int y, int r);
int		mlx_trgb_to_hex(uint8_t t, uint8_t r, uint8_t g, uint8_t b);

#endif
