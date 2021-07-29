# include "cub.h"
# include <stdio.h>

int	isWall(int c)
{
	return (c == '1' || c == ' ');
}

int	hasWall(char **map, double x, double y)
{
	uint32_t	indexGridX;
	uint32_t	indexGridY;

	indexGridX = floor(x / TILE_SIZE);
	indexGridY = floor(y / TILE_SIZE);
	return (isWall(map[indexGridY][indexGridX]));
}
