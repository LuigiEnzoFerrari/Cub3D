#ifndef CUB_H
# define CUB_H

# include <mlx.h>

# include <stdbool.h>

# include "libft.h"
# include "libft2d.h"

# include "struct.h"
# include "check_settings.h"

# include "mlx_extension.h"

# include "const.h"
# include <fcntl.h>
# include <float.h>
# include <math.h>

typedef struct s_vars
{
	void	*window;
	void	*mlx;
	t_set	set;
	t_P1	player;
	t_rays	*rays;
	t_xRenderer	renderer;
}	t_vars;

t_set	settings(void);
void	init_all(t_vars *vars);
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
void	exit_elements(t_sval *val, int fd);

void	get_TEX(t_sval *val);
void	get_R(t_sval *val);
void	get_FC(t_sval *val);
char	*get_values(char *str);

void	map_basic_check(t_list **map, t_sval *val, int fd);
int		map_basic_line(char *str, t_cmap *cmap);
void	get_map(t_sval *val, int fd);

void	map_clear_spaces(t_sval *val);
size_t	size_map(char **map);
int		n_whitecolumn(char **str);
void	check_map(t_sval *val, int fd);
int		iswhite(char **str, int i);
size_t	len_map(char *map_line);
void	replace_map(char *map, char *ptr, size_t x);
int		hasWhiteColomns(char **str);
int		map_line(char *map_line);

int		istexture(char *str);

void	renderMap(t_xRenderer *img, char **map);
void	input(t_vars *vars);
void	update(t_vars *vars);
void	render(t_vars *vars);

void	rayCasting(t_P1 player, char **map, float rayAngle, int stripId, t_rays *rays);
int		hasWall(char **map, float x, float y);
void	movePlayer(t_vars *vars);

#endif
