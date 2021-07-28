#include "cub.h"

void	minimap(t_xRenderer *img, char **map, t_set set)
{
	int i;
	int j;
	int tileX;
	int tileY;
	int tileColor;

	i = 0;
	j = 0;
	while (i < set.map_size.y)
	{
		while (j < set.map_size.x)
		{
			tileX = j * set.tile_size;
			tileY = i * set.tile_size;
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
					set.tile_size * MINIMAP_SCALE,
					set.tile_size * MINIMAP_SCALE));
			j++;
		}
		j = 0;
		i++;
	}
}
