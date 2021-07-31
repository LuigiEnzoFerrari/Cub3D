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

# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct s_vars
{
	void	*window;
	void	*mlx;
	t_set	set;
	t_P1	player;
	t_rays	*rays;
	t_xRenderer	renderer;
	t_ximg	tex;
}	t_vars;

void	init_all(t_vars *vars, int argc, char **argv);
void	set_player(t_P1 *player, t_set set);
void	printall(t_sval *val);

void	map_basic_check(t_list **map, t_sval *val, int fd);
int		map_basic_line(char *str, t_cmap *cmap);
void	get_map(t_sval *val, int fd);

void	input(t_vars *vars);
void	update(t_vars *vars);
void	render(t_vars *vars);

void	raysCasting(t_vars *vars);
int		hasWall(char **map, double x, double y);
void	player(t_vars *vars);

void	foundWallHoriz(t_vars vars, t_rays *rays, t_casting *cast);
void	foundWallVert(t_vars vars, t_rays *rays, t_casting *cast);
void	minimumDistance(t_vars vars, t_rays *rays, t_casting *cast);

void	background(t_xRenderer *renderer, t_set set);
void	playerPosition(t_vars *vars);
void	rays(t_vars *vars);
void	minimap(t_xRenderer *img, char **map, t_set set);
void	projection(t_vars *vars, t_rays *rays, t_P1 player, t_set set);


#endif
