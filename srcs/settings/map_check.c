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

static int	good_line(char *str, t_cmap *cmap)
{
	while (*str == ' ')
		str++;
	if (*str != '1')
		return (0);
	while (*str)
	{
		if (!valid_map(*str))
			return (0);
		if (isplayer(*str))
		{
			if (cmap->player == true)
			{
				cmap->dplayer = true;
				return (0);
			}
			cmap->player = true;
		}
		str++;
	}
	return (1);
}

void	check_line(t_list **map, t_sval *val, int fd)
{
	char	*str;

	str = val->str;
	if (good_line(str, &val->cmap))
		return ;
	if (val->cmap.dplayer == true)
		ft_putendl_fd("Multiple Players", 0);
	else
		ft_putendl_fd("Shit Map", 0);
	ft_lstclear(map, free);
	exit_elements(val, fd);
}

void	check_after_map(t_sval *val, int fd, t_list **map)
{
	t_cmap temp;

	temp.player = false;
	clr_whitelines(val, fd);
	if (*val->str == '\0')
	{
		free(val->str);
		return ;
	}
	else if (good_line(val->str, &temp))
		ft_putendl_fd("Double map or splited map\n", 0);
	else
		ft_putendl_fd("Invalid key in the end of the file\n", 0);
	ft_lstclear(map, free);
	exit_elements(val, fd);
}

void	check_befor_map(t_sval *val, int fd)
{
	char	*str;

	clr_whitelines(val, fd);
	str = ft_skipctype(val->str, ft_isspace, 1);
	if (*str == '1')
		return ;
	ft_putendl_fd("Invalid key found", 1);
	exit_elements(val, fd);
}
