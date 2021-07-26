#include "cub.h"

static int	isplayer(int c)
{
	if (c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		return (1);
	return (0);
}

static int	valid_map(int c)
{
	if (c == '1' || c == '0' || c == '2'
		|| c == ' ' || isplayer(c))
		return (1);
	return (0);
}

static int map_basic_player(char c, t_cmap *cmap)
{
		if (isplayer(c))
		{
			if (cmap->player == true)
			{
				cmap->dplayer = true;
				return (0);
			}
			cmap->player = true;
		}
	return (1);
}

int	map_basic_line(char *str, t_cmap *cmap)
{
	char	*ptr;

	while (*str == ' ')
		str++;
	if (*str != '1')
		return (0);
	while (*str)
	{
		if (!valid_map(*str))
			return (0);
		if (!map_basic_player(*str, cmap))
			return (0);
		// if (isplayer(*str))
		// {
		// 	if (cmap->player == true)
		// 	{
		// 		cmap->dplayer = true;
		// 		return (0);
		// 	}
		// 	cmap->player = true;
		// }
		if (*str == '1')
			ptr = str;
		str++;
	}
	while (*ptr)
	{
		if (*ptr != '1' && *ptr != ' ')
			return (0);
		ptr++;
	}
	return (1);
}

void	map_basic_check(t_list **map, t_sval *val, int fd)
{
	char	*str;

	str = val->str;
	if (map_basic_line(str, &val->cmap))
		return ;
	if (val->cmap.dplayer == true)
		ft_putendl_fd("Multiple Players\n", 0);
	else
		ft_putendl_fd("Invalid map\n", 0);
	ft_lstclear(map, free);
	exit_elements(val, fd);
}
