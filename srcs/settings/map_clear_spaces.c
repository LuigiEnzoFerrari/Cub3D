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

char	**make_square(size_t x, size_t y)
{
	char	**ptr;
	size_t	i;

	i = 0;
	ptr = malloc(sizeof(char *) * (y + 1));
	ptr[y] = NULL;
	while (i < y)
	{
		ptr[i] = malloc(sizeof(char) * (x + 1));
		ptr[i][x] = '\0';
		i++;
	}
	return (ptr);
}

void	transferer_map(char **map, char **ptr, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while (i < y)
	{
		replace_map(map[i], ptr[i], x);
		i++;
	}
}

char	**clr_last_columns(char **map)
{
	char	**ptr;
	size_t	x;
	size_t	y;

	x = size_map(map);
	y = ft_arraylen(map);
	ptr = make_square(x, y);
	transferer_map(map, ptr, x, y);
	ft_arrayfree(map);
	return (ptr);
}

void	map_clear_spaces(t_sval *val)
{
	val->set.map = clr_first_colomns(val->set.map);
	val->set.map = clr_last_columns(val->set.map);
}
