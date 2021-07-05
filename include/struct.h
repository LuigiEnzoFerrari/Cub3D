#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_Resolution
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



#endif