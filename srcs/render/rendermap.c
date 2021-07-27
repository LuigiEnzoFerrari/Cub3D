#include "cub.h"

void	renderMap(t_xRenderer *img, char **map)
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
			if (map[i][j] == '0')
				tileColor = 0;
			else if (map[i][j] == 'W')
				tileColor = 0x00adf16a;
			else
				tileColor = 0x00ffffff;
			mlx_set_render_color(img, tileColor);
			mlx_draw_fill_rect(img,
			mlx_get_rect(tileX * MINIMAP_SCALE, 
					tileY * MINIMAP_SCALE,
					TILE_SIZE * MINIMAP_SCALE,
					TILE_SIZE * MINIMAP_SCALE));
			j++;
		}
		j = 0;
		i++;
	}
}