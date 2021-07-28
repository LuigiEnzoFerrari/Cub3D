#include "cub.h"

void	foundtWallHoriz(t_vars vars, t_rays *rays, float rayAngle, t_casting *cast)
{
	t_xFPoint	intercept;
	t_xFPoint	step;
	t_xFPoint	toCheck;

	cast->hit = 0;
	intercept.y = floor(vars.player.y / vars.set.tile_size) * vars.set.tile_size;
	if (rays->down)
		intercept.y += vars.set.tile_size;
	intercept.x = vars.player.x + (intercept.y - vars.player.y) / tan(rayAngle);
	step.y = vars.set.tile_size;
	if (rays->up)
		step.y = -step.y;
	step.x = vars.set.tile_size / tan(rayAngle);
	if (rays->left && step.x > 0)
		step.x = -step.x;
	if (rays->right && step.x < 0)
		step.x = -step.x;

	while (intercept.x >= 0 && intercept.x <= WINDOW_WIDTH && intercept.y >= 0 && intercept.y <= WINDOW_HEIGHT)
	{
		toCheck.x = intercept.x;
		toCheck.y = intercept.y;
		if (rays->up)
			toCheck.y -= 1;
		if (hasWall(vars.set.map, toCheck.x, toCheck.y, vars.set))
		{
			cast->wallHit.x = intercept.x;
			cast->wallHit.y = intercept.y;
			cast->wallContent = vars.set.map[(int)floor(toCheck.y / vars.set.tile_size)][(int)floor(toCheck.x / vars.set.tile_size)];
			cast->hit = 1;
			break ;
		}
		else
		{
			intercept.x += step.x;
			intercept.y += step.y;
		}
	}
}
