#ifndef CUB_H
# define CUB_H

# include <mlx.h>

# include <stdbool.h>

# include "libft.h"
# include "libft2d.h"

# include "struct.h"
# include "cub_settings.h"

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

void	init_all(t_vars *vars);
void	printall(t_sval *val);

void	map_basic_check(t_list **map, t_sval *val, int fd);
int		map_basic_line(char *str, t_cmap *cmap);
void	get_map(t_sval *val, int fd);

void	renderMap(t_xRenderer *img, char **map);
void	input(t_vars *vars);
void	update(t_vars *vars);
void	render(t_vars *vars);

void	rayCasting(t_P1 player, char **map, float rayAngle, int stripId, t_rays *rays);
int		hasWall(char **map, float x, float y);
void	movePlayer(t_vars *vars);



#endif
