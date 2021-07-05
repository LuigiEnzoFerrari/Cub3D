#include "cub.h"

static int	white_line(char *str)
{
	str = ft_skipctype(str, ft_isspace, 1);
	return (!(*str));
}

static char	*rm_whitespace(char *str)
{
	size_t	len;
	char	*ptr;

	ptr = str;
	ptr = ft_skipctype(ptr, ft_isspace, 1);
	len = ft_strlen(ptr);
	while (ft_isspace(ptr[len - 1]))
		len--;
	ptr = ft_strndup(ptr, len);
	free(str);
	return (ptr);
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
	if (*val->str)
		val->str = rm_whitespace(val->str);
}
