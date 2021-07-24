#ifndef STRUCT_H
# define STRUCT_H

# include <stdint.h>
# include <stddef.h>
# include "mlx_extension.h"

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

void	init_RES(t_RES *res);
void	init_TEX(t_TEX *tex);
void	init_RGBA(t_xColor *rgba);

#endif
