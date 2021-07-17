#include "cub.h"

static int	player_direction(int c)
{
	if (c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		return (1);
	return (0);
}

static int	valid_map(int c)
{
	if (c == '1' || c == '0' || c == '2'
		|| c == ' ' || player_direction(c))
		return (1);
	return (0);
}

static int	good_line(char *str)
{
	while (*str == ' ')
		str++;
	if (*str != '1')
		return (0);
	while (*str)
	{
		if (!valid_map(*str))
			return (0);
		str++;
	}
	return (1);
}

void	check_line(t_list **map, t_sval *val, int fd)
{
	char	*str;

	str = val->str;
	if (good_line(str))
		return ;
	ft_putendl_fd("Shit Map", 0);
	free_all(val);
	ft_lstclear(map, free);
	close(fd);
	exit(0);
}

void	check_inv_end(t_sval *val, int fd, t_list **map)
{
	clr_whitelines(val, fd);
	if (*val->str == '\0')
	{
		free(val->str);
		return ;
	}
	else if (good_line(val->str))
		ft_putendl_fd("double map or splited map\n", 0);
	else
		ft_putendl_fd("Shit in the end of the file", 0);
	ft_lstclear(map, free);
	free(val->str);
	free_all(val);
	close(fd);
	exit(0);
}

void	check_inv_ch(t_sval *val, int fd)
{
	char	*str;

	clr_whitelines(val, fd);
	str = ft_skipctype(val->str, ft_isspace, 1);
	if (*str == '1')
		return ;
	ft_putendl_fd("some shit is happening", 1);
	free(val->str);
	free_all(val);
	close(fd);
	exit(0);
}
