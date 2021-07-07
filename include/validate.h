#ifndef VALIDATE_H
# define VALIDATE_H

#include <stddef.h>

typedef	struct s_vRGB
{
	size_t	comma;
	size_t	digit;
	bool	charac;
}	t_vRGB;

int		validate_RGB(char *str);
int		validate_RES(char *str);
int		validate_TEX(char *str);

#endif