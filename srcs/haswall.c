# include "cub.h"
# include <stdio.h>

int	isWall(int c)
{
	return (c == '1' || c == ' ');
}

int	hasWall(char **map, double x, double y)
{
	uint32_t	gX;
	uint32_t	gY;

	// if (x < 0 || x > n_columns * TILE_SIZE || y < 0 || y > n_rows * TILE_SIZE)
	// 	return (1);
	gX = floor(x / TILE_SIZE);
	gY = floor(y / TILE_SIZE);
	return (isWall(map[gY][gX]));
}
