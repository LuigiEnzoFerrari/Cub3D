# include "cub.h"
# include <stdio.h>

int	isWall(int c)
{
	return (c == '1' || c == ' ');
}

int	hasWall(t_set set, double x, double y)
{
	uint32_t	gX;
	uint32_t	gY;

	if (x < 0 || x > set.map_size.x * TILE_SIZE
		|| y < 0 || y > set.map_size.y * TILE_SIZE)
		return (1);
	gX = floor(x / TILE_SIZE);
	gY = floor(y / TILE_SIZE);
	return (isWall(set.map[gY][gX]));
}
