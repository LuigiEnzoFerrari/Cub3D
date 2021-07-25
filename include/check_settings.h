#ifndef CHECK_SETTINGS_H
# define CHECK_SETTINGS_H

# include "struct.h"
# include "check_map.h"

typedef	struct s_invalid
{
	bool	ch;
	bool	rgb;
	bool	tex;
	bool	res;
	bool	map;
	bool	empty;
	bool	dkey;
}	t_inv;

typedef struct s_check
{
	bool	south;
	bool	north;
	bool	east;
	bool	west;
	bool	sprit;
	bool	floor;
	bool	color;
	bool	resol;
	t_inv	inv;
}	t_check;

typedef	struct s_vRGB
{
	size_t	comma;
	size_t	digit;
	bool	charac;
}	t_vRGB;

typedef struct s_set_values
{
	char	*str;
	int		fd;
	t_check	cvalues;
	t_cmap	cmap;
	t_set	set;
}	t_sval;

int		validate_RGB(char *str);
int		validate_RES(char *str);
int		validate_TEX(char *str);

#endif
