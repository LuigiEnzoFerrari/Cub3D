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
# include <float.h>

#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

#define PI 3.14159265358979323846
#define TWO_PI (2 * PI)
#define TILE_SIZE 64
#define MAP_COLS 20
#define MAP_ROWS 13
#define WINDOW_WIDTH (MAP_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_ROWS * TILE_SIZE)
#define FOV_ANGLE (60 * PI /180)

#define MINIMAP_SCALE 0.3
#define NUM_RAY WINDOW_WIDTH

typedef struct s_setting
{
	char	**map;
	t_TEX	tex;
	t_RGBA	cell;
	t_RGBA	floor;
	t_RES	resolution;
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

typedef struct s_vars
{
	void	*window;
	void	*mlx;
	t_set	set;
	t_xRenderer	renderer;
	t_P1	player;
}	t_vars;

typedef struct s_ray
{
	float	rayAngle;
	float	wallHitX;
	float	wallHitY;
	float	distance;
	int		wasHisVerical;
	int		isRayFacingUp;
	int		isRayFacingDown;
	int		isRayFacingLeft;
	int		isRayFacingRight;
	int		wallHitContent;
}	t_ray[NUM_RAY];

void	init_all(t_vars *vars);
t_set	settings(void);
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

#endif
