#ifndef DEFINES_H
#define DEFINES_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "get_next_line.h"
# include <ctype.h>
# include <stdint.h>
# include <string.h>
# include <wchar.h>
# include <complex.h>
# include <stdbool.h>

typedef struct co
{
	char	*south;
	char	*north;
	char	*west;
	char	*east;
	char	*sprit;
	char	*resul;
	char	*color;
	char	*floor;
}	conf;

typedef	struct sets
{
	char	*str;
	int		fd;
	conf	config;
}	sets;

#endif