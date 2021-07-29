# include "cub.h"
# include <stdio.h>

int	hasWall(char **map, double x, double y)
{
	int	indexGridX;
	int	indexGridY;

	indexGridX = floor(x / TILE_SIZE);
	indexGridY = floor(y / TILE_SIZE);
	return (map[indexGridY][indexGridX] != '0');
}
