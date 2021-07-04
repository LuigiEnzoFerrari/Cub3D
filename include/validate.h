#ifndef VALIDATE_H
# define VALIDATE_H

typedef	struct s_vRGB
{
	int8_t	comma;
	int8_t	digit;
	bool	charac;
}	t_vRGB;

int		validate_RGB(char *str);

int		validate_RES(char *str);

int		validate_TEX(char *str);

#endif