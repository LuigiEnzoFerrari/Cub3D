#include "cub.h"

static char	**cpy_map(t_list *lst)
{
	size_t	len;
	char	**str;
	char	**ptr;

	len = ft_lstsize(lst);
	str = malloc(sizeof(char *) * (len + 1));
	ptr = str;
	while (lst)
	{
		*str++ = ft_strdup(lst->content);
		lst = lst->next;
	}
	*str = NULL;
	return (ptr);
}

static void	get_map(t_list **map, t_sval *val, int fd)
{
	ssize_t	r;
	t_list	*ptr;

	r = 1;
	*map = ft_lstnew(ft_strdup(val->str));
	free(val->str);
	ptr = *map;
	while (r > 0)
	{
		r = get_next_line(fd, &val->str);
		ptr = ft_lstnew(val->str);
		ft_lstadd_back(&(*map), ptr);
	}
}

void	save_map(t_sval *val, int fd)
{
	t_list	*map;

	get_map(&map, val, fd);
	val->map = cpy_map(map);
	ft_lstclear(&map, free);
	ft_putarraydelim_fd(val->map, '\n', 1);
	ft_arrayfree(val->map);
}
