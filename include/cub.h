#ifndef CUB_H
# define CUB_H

# include <stdbool.h>
# include "libft.h"
# include "libft2d.h"
# include "struct.h"
# include "get_next_line.h"
# include "validate.h"
# include "cub_error.h"

typedef struct s_set_values
{
	char	*str;
	char 	**map;
	t_TEX	tex;
	t_RGBA	color;
	t_RGBA	floor;
	t_RES	resolution;
	t_check	cvalues;
}	t_sval;

void	init_all(void);
void	settings(t_sval *val);
void	rm_whitelines(t_sval *val, int fd);
void	save_configs(t_sval *val);
int		isvalid(int c);
void	save_map(t_sval *val, int fd);

void	init_val(t_sval *val);

// temp
void	free_all(t_sval *val);
void	printall(t_sval *val);
void	print_lst(t_list *lst);

int		check_configs(t_sval *val);
void	exit_cub_settings(t_sval *val, t_inv inv);

#endif
