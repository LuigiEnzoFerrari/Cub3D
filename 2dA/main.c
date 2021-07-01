#include "get_next_line.h"
#include "../Libft2D/libft2d.h"

void	lst_map(t_list **lst)
{
	t_list	*ptr;
	char	*line;
	int r, fd;

	r = 66;
	fd = open("map.cub", O_RDWR);
	while (r > 0)
	{
		r = get_next_line(fd, &line);
		ptr = ft_lstnew(line);
		ft_lstadd_back(lst, ptr);
	}
}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		ft_putendl_fd(lst->content, 1);
		lst = lst->next;
	}
}

char	**get_map(t_list *lst)
{
	size_t	len;
	char	**str;
	char	**ptr;

	len = ft_lstsize(lst);
	str = malloc(sizeof(char *) * (len + 1));
	ptr = str;
	while (lst)
	{
		*str = ft_strdup(lst->content);
		str++;
		lst = lst->next;
	}
	*str = NULL;
	return (ptr);
}

void	print_array(char **str)
{
	while (*str)
	{
		ft_putendl_fd(*str, 1);
		str++;
	}
}

void	free_all(char **str)
{
	char **ptr;

	ptr = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(ptr);
}

int		main(void)
{
	t_list	*lst;
	char	**str;
	lst = NULL;
	lst_map(&lst);
	// print_lst(lst);
	str = get_map(lst);
	ft_lstclear(&lst, free);
	print_array(str);
	free_all(str);
	return (0);
}
