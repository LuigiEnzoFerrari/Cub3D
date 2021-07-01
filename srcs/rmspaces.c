#include "cube.h"

static int	white_line(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (!(*str));
}

static char	*rm_whitespace(char *str)
{
	size_t	len;
	char	*ptr;

	ptr = str;
	while (ft_isspace(*ptr))
		ptr++;
	len = ft_strlen(str);
	while (ft_isspace(str[len]))
		len--;
	ptr = ft_strndup(ptr, len);
	free(str);
	str = ptr;
	return (str);
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
	val->str = rm_whitespace(val->str);
}
