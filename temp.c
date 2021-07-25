
#include "libft2d.h"


size_t	quer(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}


size_t	ft_maxlenmap(char **array)
{
	size_t	len;
	size_t	maxlen;

	len = 0;
	while (*array)
	{
		maxlen = quer(*array, ' ');
		if (maxlen > len)
			len = maxlen	;
		array++;
	}
	return (len);
}

char	**newArrayTwo(char **array, int i)
{
	size_t	len;
	char	**ptr;

	len = ft_arraylen(array);
	ptr = malloc(sizeof(char *) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = NULL;
	while (len--)
		ptr[len] = ft_strndup(array[len], i);
	return (ptr);
}



void	pushcolumn(char **str)
{
	while (*str)
	{
		(*str)++;
		str++;
	}
}


int	main(void)
{

	char	**map;
	char	**ptr;
	char	**fire;
	size_t	i;

	map = malloc(sizeof(char *) * 5);
	ptr = map;
	fire = map;

	*map++ = ft_strdup("      olameubem    ");
	*map++ = ft_strdup("      olameuq      ");
	*map++ = ft_strdup("      aolaflordo    ");
	*map++ = ft_strdup("      olavasosa    ");
	*map++ = NULL;

	i = n_whitecolumn(ptr);
	ptr = newArray(ptr);
	ft_putnbr(i);

	ft_putchar('\n');
	ft_putarraydelim_fd(ptr, '\n', 1);
	ft_putchar('\n');

	i = ft_maxlenmap(ptr);
	// ptr = newArrayTwo(ptr, i);
	ft_putnbr(i);

	// ft_putarraydelim_fd(ptr, '\n', 1);
	ft_putchar('\n');
	ft_arrayfree(fire);
	return (0);
}
