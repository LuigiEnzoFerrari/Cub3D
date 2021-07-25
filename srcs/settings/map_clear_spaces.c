#include "cub.h"

char	**clr_first_colomns(char **array)
{
	size_t	len;
	size_t	i;
	char	**ptr;

	i = n_whitecolumn(array);
	len = ft_arraylen(array);
	ptr = malloc(sizeof(char *) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = NULL;
	while (len--)
		ptr[len] = ft_strdup(&array[len][i]);
	ft_arrayfree(array);
	return (ptr);
}
char	**clr_last_columns(char **array)
{
	size_t	len;
	size_t	i;
	char	**ptr;

	i = size_map(array);
	len = ft_arraylen(array);
	ptr = malloc(sizeof(char *) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = NULL;
	while (len--)
		ptr[len] = ft_strndup(array[len], i);
	ft_arrayfree(array);
	return (ptr);
}

void	map_clear_spaces(t_sval *val)
{
	val->set.map = clr_first_colomns(val->set.map);
	val->set.map = clr_last_columns(val->set.map);
	
	ft_putnbr(size_map(val->set.map));
	ft_putchar('\n');
}
