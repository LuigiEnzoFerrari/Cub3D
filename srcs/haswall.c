# include "cub.h"
# include <stdio.h>

int	hasWall(char **map, float x, float y, t_set set)
{
	uint32_t indexGridX;
	uint32_t indexGridY;

	indexGridX = floor(x / set.tile_size);
	indexGridY = floor(y / set.tile_size);
	if (x < 0 || x > set.resolution.w || y < 0 || y > set.resolution.h)
		return (1);
	return map[indexGridY][indexGridX] != '0';
}
