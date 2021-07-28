#include "cub.h"

static float	distPoints(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	minimumDistance(t_vars vars, t_rays *rays, float rayAngle, t_casting *cast)
{
	t_xFPoint	dist;

	dist.x = FLT_MAX;
	if (cast[0].hit)
		dist.x = distPoints(vars.player.x, vars.player.y, cast[0].wallHit.x, cast[0].wallHit.y);
	dist.y = FLT_MAX;
	if (cast[1].hit)
		dist.y = distPoints(vars.player.x, vars.player.y, cast[1].wallHit.x, cast[1].wallHit.y);
	if (dist.y < dist.x)
	{
		rays->distance = dist.y;
		rays->wallHitX = cast[1].wallHit.x;
		rays->wallHitY = cast[1].wallHit.y;
		rays->wallHitContent = cast[1].wallContent;
		rays->wasHisVerical = 1;
	}
	else
	{
		rays->distance = dist.x;
		rays->wallHitX = cast[0].wallHit.x;
		rays->wallHitY = cast[0].wallHit.y;
		rays->wallHitContent = cast[0].wallContent;
		rays->wasHisVerical = 0;
	}
	rays->rayAngle = rayAngle;
}