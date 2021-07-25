#include "cub.h"

char	**cpy_map(t_list *lst)
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

void	check_chr_get_map(t_list **map, t_sval *val, int fd)
{
	ssize_t	r;
	t_list	*ptr;

	*map = ft_lstnew(val->str);
	check_line(map, val, fd);
	r = 1;
	ptr = *map;
	while (r > 0)
	{
		r = get_next_line(fd, &val->str);
		if (*val->str == '\0')
			break ;
		check_line(map, val, fd);
		ptr = ft_lstnew(val->str);
		ft_lstadd_back(&(*map), ptr);
	}
	if (*val->str == '\0')
		free(val->str);
}
