/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:02:01 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 11:32:06 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	isjogador(int c)
{
	return (c == 'W' || c == 'S' || c == 'N' || c == 'E');
}

static int	find_postion(double *x, double *y, char **map, int (f)(int))
{
	int	a;
	int	b;

	a = 0;
	while (*(map + a))
	{
		b = 0;
		while (*(*(map + a) + b))
		{
			if (f(*(*(map + a) + b)))
			{
				*y = a;
				*x = b;
				return ((*(*(map + a) + b)));
			}
			b++;
		}
		a++;
	}
	return (0);
}

static double	set_player_rotation(char c)
{
	if (c == 'S')
		return (PI * 0.5);
	else if (c == 'N')
		return (PI * 1.5);
	else if (c == 'W')
		return (PI);
	return (0);
}

void	set_player(t_P1 *player, t_set set)
{
	char	rotation;

	rotation = find_postion(&player->x, &player->y, set.map, isjogador);
	player->x = player->x * TILE_SIZE + (TILE_SIZE >> 1);
	player->y = player->y * TILE_SIZE + (TILE_SIZE >> 1);
	player->r = 15;
	player->walk_direction_fb = 0;
	player->turn_direction = 0;
	player->turn_step = 5 * (PI / 180);
	player->walk_step = 8;
	player->rotation_angle = set_player_rotation(rotation);
	player->fov = PI / 3;
	player->dist = (set.resolution.w >> 1) / tan(player->fov / 2);
}
