#include "cub.h"

void	file_error(uint8_t n)
{
	if (n == 1 << 1)
		ft_putendl_fd("Invalid number of arguments", 0);
	else if (n == 1 << 2)
		ft_putendl_fd("Missing something", 0);
	else if (n == 1 << 3)
		ft_putendl_fd("Invalid file extension", 0);
	else if(n == 1 << 4)
		ft_putendl_fd("Invalid file extension", 0);
	else if (n == 1 << 5)
		ft_putendl_fd("Second argument invalid", 0);
	else if (n == 1 << 6)
		ft_putendl_fd("File .cub not found:", 0);
	exit(0);
}