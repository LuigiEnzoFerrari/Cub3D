#ifndef CUB_ERROR_H
# define CUB_ERROR_H

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


#endif
