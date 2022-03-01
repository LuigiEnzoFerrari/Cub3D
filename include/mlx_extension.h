/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_extension.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:33:23 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/28 22:49:54 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_EXTENSION_H
# define MLX_EXTENSION_H

# include <stdint.h>
# include <stddef.h>

# include "mlx.h"

typedef struct mlx_rect
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_xrect;

typedef struct mlx_circle
{
	int	x;
	int	y;
	int	r;
}	t_xcircle;

typedef struct mlx_point
{
	int	x;
	int	y;
}	t_xpoint;

typedef struct mlx_fpoint
{
	double	x;
	double	y;
}	t_xfpoint;

typedef struct mlx_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_xline;

typedef struct mlx_color
{
	uint8_t	t;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_xcolor;

typedef struct mlx_renderer
{
	void	*img;
	char	*addr;
	int		bpp;
	int		s_line;
	int		endian;
	int		color;
}	t_xrenderer;

typedef struct mlx_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		s_line;
	int		endian;
	int		color;
}	t_ximg;

typedef struct s_bresenham_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bline;

void		mlx_put_pixel(t_xrenderer *renderer, int x, int y);
void		mlx_draw_line(t_xrenderer *renderer, t_xline line);
void		mlx_draw_fill_rect(t_xrenderer *renderer, t_xrect rect);
void		mlx_draw_circle(t_xrenderer *renderer, t_xcircle circle);
void		mlx_set_render_color(t_xrenderer *renderer, int color);
void		mlx_render_present(void *mlx, void *win, void *img);

t_xline		mlx_get_line(int x0, int y0, int x1, int y1);
t_xrect		mlx_get_rect(int x, int y, int w, int h);
t_xcircle	mlx_get_circle(int x, int y, int r);
t_xrenderer	mlx_create_renderer(void *mlx, int size_x, int size_y);

int			mlx_get_hex_trgb(uint8_t t, uint8_t r, uint8_t g, uint8_t b);

#endif
