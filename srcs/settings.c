#include "cube.h"

int		white_line(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (!(*str));
}

void	rm_whitelines(t_sval *val, int fd)
{
	ssize_t	r;

	r = get_next_line(fd, &val->str);
	while (white_line(val->str) && r > 0)
	{
		free(val->str);
		r = get_next_line(fd, &val->str);
	}
}

int		check_lines(t_sval *val)
{
	if (!val->str || !*val->str)
		return (1);
	else if (*val->str == '1')
	{
		ft_putstr_fd("olamundocruel", 1);
		return (0);
	}
	return (0);
}

void	rm_whitespace(t_sval *val)
{
	char	*str;

	str = val->str;
	while (ft_isspace(*str))
		str++;
	str = ft_strdup(str);
	free(val->str);
	val->str = str;
	return ;
}

int	isvalid(int c)
{
	if (c == 'S'
		|| c == 'N' || c == 'E' || c == 'R'
		|| c == 'W' || c == 'F' || c == 'C')
		return (1);
	return (0);
}

char	*get_values(char *str)
{
	char	*ptr;

	while (ft_isspace(*str))
		str++;
	ptr = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	strcpy(ptr, str);
	return (ptr);
}

char	*get_rgb(char *str, t_RGBA *rgb)
{
	char	*fire;

	str = get_values(str + 1);
	fire = str;
	while (!ft_isdigit(*str))
		str++;
	rgb->r = ft_atoi(str);
	str += ft_nbrlen(rgb->r);
	while (!ft_isdigit(*str))
		str++;
	rgb->g = ft_atoi(str);
	str += ft_nbrlen(rgb->r);
	while (!ft_isdigit(*str))
		str++;
	rgb->b = ft_atoi(str);
	free(fire);
	return (str);
}

void	get_res(char *str, t_RES *resolution)
{
	char	*fire;

	str = get_values(str + 1);
	fire = str;
	while (!ft_isdigit(*str))
		str++;
	resolution->w = ft_atoi(str);
	str += ft_nbrlen(resolution->w);
	while (!ft_isdigit(*str))
		str++;
	resolution->h = ft_atoi(str);
	str += ft_nbrlen(resolution->h);
	free(fire);
}

void	save_values(t_sval *val)
{
	char	*str;

	str = val->str;
	if (*str == 'S' && *(str + 1) != 'O')
		val->sprit = get_values(str + 1);
	else if (*str == 'N' && *(str + 1) == 'O')
		val->north = get_values(str + 2);
	else if (*str == 'E' && *(str + 1) == 'A')
		val->east = get_values(str + 2);
	else if (*str == 'S' && *(str + 1) == 'O')
		val->south = get_values(str + 2);
	else if (*str == 'W' && *(str + 1) == 'E')
		val->west = get_values(str + 2);
	else if (*str == 'F')
		get_rgb(str, &val->folor);
	else if (*str == 'C')
		get_rgb(str, &val->color);
	else if (*str == 'R')
		get_res(str, &val->resolution);
}

void	save_configs(t_sval *val)
{
	if (isvalid(*val->str))
		save_values(val);
}

void	printall(t_sval *val)
{
	ft_putendl_fd(val->south, 1);
	ft_putendl_fd(val->north, 1);
	ft_putendl_fd(val->east, 1);
	ft_putendl_fd(val->west, 1);
	ft_putendl_fd(val->sprit, 1);
	ft_putnbr(val->folor.r);
	ft_putchar('\n');
	ft_putnbr(val->folor.g);
	ft_putchar('\n');
	ft_putnbr(val->folor.b);
	ft_putchar('\n');
	ft_putnbr(val->resolution.w);
	ft_putchar('\n');
	ft_putnbr(val->resolution.h);
	ft_putchar('\n');
	free(val->south);
	free(val->north);
	free(val->east);
	free(val->west);
	free(val->sprit);
}

void	settings(t_sval *val)
{
	int fd;

	fd = open ("./srcs/sett.cub", O_RDONLY);
	while (true)
	{
		rm_whitelines(val, fd);
		rm_whitespace(val);
		save_configs(val);
		if (check_lines(val))
		{
			free(val->str);
			break ;
		}
		free(val->str);
	}
	printall(val);
}
