#include "cub.h"

static int	isjogador(int c)
{
	return (c == 'W' || c == 'S' || c == 'N' || c == 'E');
}

static void	playerPostion(double *x, double *y, char **map)
{
	int	a;
	int	b;

	a = 0;
	while (*(map + a))
	{
		b = 0;
		while (*(*(map + a) + b))
		{
			if (isjogador(*(*(map + a) + b)))
			{
				*y = a;
				*x = b;
				break ;
			}
			b++;
		}
		a++;
	}
}

void	set_player(t_P1 *player, char **map)
{
	playerPostion(&player->x, &player->y, map);
	ft_putarraydelim_fd(map, '\n', 1);
	printf("a::%.2lf b::%.2lf\n ", player->x, player->y);
	player->x = player->x * TILE_SIZE + (TILE_SIZE >> 1);
	player->y = player->y * TILE_SIZE + (TILE_SIZE >> 1);
	player->r = 20;
	player->wDFB = 0;
	player->tD = 0;
	player->tS = 5 * (PI / 180);
	player->wS = 8;
	player->rAngle = PI / 2;
	player->fov = PI / 3;
}
