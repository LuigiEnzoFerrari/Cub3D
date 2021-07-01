#ifndef CUBE_H
# define CUBE_H

# include <stdbool.h>
# include "libft.h"
# include "struct.h"
# include "get_next_line.h"
# include "libft2d.h"

void	init_all(void);
void	settings(t_sval *val);
void	rm_whitelines(t_sval *val, int fd);
void	save_configs(t_sval *val);
int		isvalid(int c);
void	save_map(t_sval *val, int fd);
// static char	**cpy_map(t_list *lst);


#endif
