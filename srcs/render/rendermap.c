#include "cub.h"

void	renderMap(t_data *img, char **map)
{
	int i;
	int j;
	int tileX;
	int tileY;
	int tileColor;

	i = 0;
	j = 0;
	while (i < MAP_ROWS)
	{
		while (j < MAP_COLS)
		{
			tileX = j * TILE_SIZE;
			tileY = i * TILE_SIZE;
			if (map[i][j] != '0')
				tileColor = 255;
			else
				tileColor = 0;
			mlx_draw_fill_rect(img,
			mlx_get_rect(tileX * MINIMAP_SCALE, 
					tileY * MINIMAP_SCALE,
					TILE_SIZE * MINIMAP_SCALE,
					TILE_SIZE * MINIMAP_SCALE),
			mlx_trgb_to_hex(0, tileColor, tileColor, tileColor));
			j++;
		}
		j = 0;
		i++;
	}
}