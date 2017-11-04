#include "checker.h"

int		is_sorted(t_list	*list)
{
	while (list->node->next)
	{
		if (*((int*)list->node->content) > *((int*)list->node->next->content))
		{
			list->node = list->head;
			return (0);
		}
		list->node = list->node->next;
	}
	list->node = list->head;
	return (1);
}

void 	print_lists(t_list *list_a, t_list *list_b, int space_seperation)
{
	char		*val_a;
	char		*space;
	char		*val_b;
	int			len_val_a;

	while (list_a->node || list_b->node)
	{
		if (list_a->node)
			val_a = ft_itoa((*(int*)list_a->node->content));
		else
			val_a = ft_strdup(" ");
		len_val_a = ft_strlen(val_a);
		space = create_space(space_seperation - len_val_a + 1);
		if (list_b->node)
			val_b = ft_itoa((*(int*)list_b->node->content));
		else
			val_b = ft_strdup(" ");
		ft_printf("%s%s %s\n", val_a, space, val_b);
		free(val_a);
		free(val_b);
		free(space);
		if (list_a->node)
			list_a->node = list_a->node->next;
		if (list_b->node)
			list_b->node = list_b->node->next;
	}
	space = create_space(space_seperation + 1);
	ft_printf("_%s_\n", space);
	ft_printf("a%sb\n", space);
	free(space);
	list_a->node = list_a->head;
	list_b->node = list_b->head;
}

void	handle_reverse_rotate(t_list *list, char *command)
{
	if (list->node->content && list->node->next)
		 lst_reverse_rotate(list);
	ft_printf(command);
}

int		get_space_seperation(t_list *list)
{
	char	*num_string;
	int		most_digits;
	int		digits;

	most_digits = 1;
	while (list->node)
	{
		num_string = ft_itoa(*(int*)list->node->content);
		digits = ft_strlen(num_string);
		if (most_digits < digits)
			most_digits = digits;
		free(num_string);
		list->node = list->node->next;
	}
	list->node = list->head;
	return (most_digits);
}

char	*create_space(int space_seperation)
{
	char	*space;
	int		i;

	i = 0;
	if (space_seperation > 0)
	{
		space = ft_strnew(space_seperation + 1);
		while (i < space_seperation)
		{
			space[i] = ' ';
			++i;
		}
	}
	else
		space = ft_strdup(" ");
	return (space);
}

static void 		node_free(t_node *node)
{
	if (node->next)
		node_free(node->next);
	free(node->content);
	free(node);
}

void 						list_free(t_list *list)
{
	if (list->head)
		node_free(list->head);
	free(list);
}

int							input_check(char *input)
{
	int		i;

	i = 0;
	if (input[i] == '-')
		++i;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (0);
		++i;
	}
	return (1);
}
