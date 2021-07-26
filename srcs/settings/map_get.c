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

static void	check_befor_map(t_sval *val, int fd)
{
	char	*str;

	clr_whitelines(val, fd);
	str = ft_skipctype(val->str, ft_isspace, 1);
	if (*str == '1')
		return ;
	ft_putendl_fd("Invalid key found", 1);
	exit_elements(val, fd);
}

static void	check_chr_get_map(t_list **map, t_sval *val, int fd)
{
	ssize_t	r;
	t_list	*ptr;

	*map = ft_lstnew(val->str);
	map_basic_check(map, val, fd);
	r = 1;
	ptr = *map;
	while (r > 0)
	{
		r = get_next_line(fd, &val->str);
		if (*val->str == '\0')
			break ;
		map_basic_check(map, val, fd);
		ptr = ft_lstnew(val->str);
		ft_lstadd_back(&(*map), ptr);
	}
	if (*val->str == '\0')
		free(val->str);
}

static void	check_after_map(t_sval *val, int fd, t_list **map)
{
	t_cmap temp;

	temp.player = false;
	clr_whitelines(val, fd);
	if (*val->str == '\0')
	{
		free(val->str);
		return ;
	}
	else if (map_basic_line(val->str, &temp))
		ft_putendl_fd("Double map or splited map", 0);
	else
		ft_putendl_fd("Invalid key in the end of the file", 0);
	ft_lstclear(map, free);
	exit_elements(val, fd);
}

void	get_map(t_sval *val, int fd)
{
	t_list	*map;

	check_befor_map(val, fd);
	check_chr_get_map(&map, val, fd);
	check_after_map(val, fd, &map);
	val->set.map = cpy_map(map);
	ft_lstclear(&map, free);
}
