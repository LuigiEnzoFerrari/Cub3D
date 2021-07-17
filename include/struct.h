#ifndef STRUCT_H
# define STRUCT_H

# include <stdint.h>
# include <stddef.h>

typedef struct s_Resolution // to points later
{
	int	w;
	int	h;
}	t_RES;

typedef struct s_RGBA
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_RGBA;

typedef struct s_TEX
{
	char	*south;
	char	*north;
	char	*west;
	char	*east;
	char	*sprit;
}	t_TEX;

void	init_RES(t_RES *res);
void	init_TEX(t_TEX *tex);
void	init_RGBA(t_RGBA *rgba);

#endif
