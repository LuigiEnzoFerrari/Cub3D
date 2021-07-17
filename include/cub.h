#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <stdbool.h>
# include "libft.h"
# include "libft2d.h"
# include "struct.h"
# include "validate.h"
# include "cub_error.h"
# include "mlx_extension.h"
# include <fcntl.h>

typedef struct s_set_values
{
	char	*str;
	char	**map;
	int		fd;
	t_TEX	tex;
	t_RGBA	cell;
	t_RGBA	floor;
	t_RES	resolution;
	t_check	cvalues;
}	t_sval;

typedef struct s_vars
{
	void	*window;
	void	*mlx;
	t_data	img;
}	t_vars;

void	init_all(void);
void	settings(t_sval *val);
void	clr_whitespaces(t_sval *val, int fd);
void	clr_whitelines(t_sval *val, int fd);
void	save_configs(t_sval *val);
int		isvalid(int c);

void	init_val(t_sval *val);

void	free_all(t_sval *val);
void	printall(t_sval *val);
void	print_lst(t_list *lst);

int		check_configs(t_sval *val, int fd);
void	exit_cub_settings(t_sval *val, t_inv inv, int fd);
void	get_TEX(t_sval *val);
void	get_R(t_sval *val);
void	get_FC(t_sval *val);
char	*get_values(char *str);

void	get_map(t_list **map, t_sval *val, int fd);
char	**cpy_map(t_list *lst);

void	check_line(t_list **map, t_sval *val, int fd);
void	check_inv_end(t_sval *val, int fd, t_list **map);
void	check_inv_ch(t_sval *val, int fd);
int		istexture(char *str);


#endif
