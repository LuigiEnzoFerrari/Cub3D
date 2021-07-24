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
# include "const.h"
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>

typedef struct s_setting
{
	char		**map;
	t_TEX		tex;
	t_xColor	cell;
	t_xColor	floor;
	int			llec;
	int			roolf;
	t_RES		resolution;
}	t_set;

typedef struct s_set_values
{
	char	*str;
	int		fd;
	t_check	cvalues;
	t_set	set;
}	t_sval;

typedef struct s_player
{
	float	x;
	float	y;
	float	w;
	float	h;
	int		r;
	int		turnDirection;
	int		walkDirection;
	double	rotationAngle;
	float	walkSpeed;
	float	turnSpeed;
}	t_P1;

typedef struct s_ray
{
	float	rayAngle;
	float	wallHitX;
	float	wallHitY;
	float	distance;
	int		wasHisVerical;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	int		wallHitContent;
}	t_rays;

typedef struct s_vars
{
	void	*window;
	void	*mlx;
	t_set	set;
	t_xRenderer	renderer;
	t_P1	player;
	t_rays	rays[NUM_RAY];
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

void	renderMap(t_xRenderer *img, char **map);
void	input(t_vars *vars);
void	update(t_vars *vars);
void	render(t_vars *vars);

void	rayCasting(t_P1 player, char **map, float rayAngle, int stripId, t_rays *rays);
int		hasWall(char **map, float x, float y);
void	movePlayer(t_vars *vars);

#endif
