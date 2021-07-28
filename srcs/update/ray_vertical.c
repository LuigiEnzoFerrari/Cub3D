#include "cub.h"

void	foundWallVert(t_vars vars, t_rays *rays, float rayAngle, t_casting *cast)
{
	t_xFPoint	intercept;
	t_xFPoint	step;

	cast->hit = 0;
	intercept.x = floor(vars.player.x / vars.set.tile_size) * vars.set.tile_size;
	if (rays->right)
		intercept.x +=vars.set.tile_size;
	intercept.y = vars.player.y + (intercept.x - vars.player.x) * tan(rayAngle);
	step.x = vars.set.tile_size;
	if (rays->left)
		step.x = -step.x;
	step.y = vars.set.tile_size * tan(rayAngle);
	if (rays->up && step.y > 0)
		step.y = -step.y;
	if (rays->down  && step.y < 0)
		step.y = -step.y;
	while (intercept.x >= 0 && intercept.x <= WINDOW_WIDTH && intercept.y >= 0 && intercept.y <= WINDOW_HEIGHT)
	{
		float xToCheck = intercept.x + (rays->left ? -1 : 0);
		float yToCheck = intercept.y;

		if (hasWall(vars.set.map, xToCheck, yToCheck, vars.set))
		{
			cast->wallHit.x = intercept.x;
			cast->wallHit.y = intercept.y;
			cast->wallContent = vars.set.map[(int)floor(yToCheck / vars.set.tile_size)][(int)floor(xToCheck / vars.set.tile_size)];
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
