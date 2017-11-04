#include "checker.h"

int		main(int ac, char **av)
{
	int				i;
	int				j;
	int				current;
	char			*line;
	char			**line_split;
	int				space_seperation;
	t_list		*list_a;
	t_list		*list_b;

	i = 1;
	if (ac < 2 && av)
	{
		ft_printf("No Input Number\n");
		return (0);
	}
	current = ft_atoi(av[i++]);
	list_a = ft_lstnew(&current, sizeof(int));
	list_b = ft_lstnew(NULL, 0);
	while (i < ac)
	{
		if (input_check(av[i]))
		{
			current = ft_atoi(av[i++]);
			if (!(list_a->node->next = ft_nodenew(&current, sizeof(int))))
			{
				list_free(list_a);
				ft_printf("Error\n");
				return (0);
			}
			list_a->node = list_a->node->next;
		}
		else
		{
			list_free(list_a);
			ft_printf("Error\n");
			return (0);
		}
	}
	ft_printf("Init a and b:\n");
	list_a->node = list_a->head;
	space_seperation = get_space_seperation(list_a);
	print_lists(list_a, list_b, space_seperation);
	while (get_next_line(0, &line))
	{
		j = 0;
		line_split = ft_strsplit(line, ' ');
		ft_printf("Exec ");
		if (ft_strncmp(line, "exit", 4) == 0)
		{
			ft_printf("Exitting program\n");
			return(0);
		}
		while (line_split[j])
		{
			if (ft_strcmp("sa", line_split[j]) == 0)
			{
				lst_swap(list_a);
				ft_printf("sa ");
			}
			else if (ft_strcmp("sb", line_split[j]) == 0)
			{
				lst_swap(list_b);
				ft_printf("sb ");
			}
			else if (ft_strcmp("ss", line_split[j]) == 0)
			{
				lst_swap(list_a);
				lst_swap(list_b);
				ft_printf("ss ");
			}
			else if (ft_strcmp("pa", line_split[j]) == 0)
			{
				lst_push(list_a, list_b);
				ft_printf("pa ");
			}
			else if (ft_strcmp("pb", line_split[j]) == 0)
			{
				lst_push(list_b, list_a);
				ft_printf("pb ");
			}
			else if (ft_strcmp("ra", line_split[j]) == 0)
			{
				if (list_a->head)
					lst_rotate(list_a);
				ft_printf("ra ");
			}
			else if (ft_strcmp("rb", line_split[j]) == 0)
			{
				if (list_b->head)
					lst_rotate(list_b);
				ft_printf("rb ");
			}
			else if (ft_strcmp("rr", line_split[j]) == 0)
			{
				if (list_a->head)
					lst_rotate(list_a);
				if (list_b->head)
					lst_rotate(list_b);
				ft_printf("rr ");
			}
			else if (ft_strcmp("rra", line_split[j]) == 0)
				handle_reverse_rotate(list_a, "rra ");
			else if (ft_strcmp("rrb", line_split[j]) == 0)
				handle_reverse_rotate(list_b, "rrb ");
			else if (ft_strcmp("rrr", line_split[j]) == 0)
			{
				lst_reverse_rotate(list_a);
				lst_reverse_rotate(list_b);
				ft_printf("rrr ");
			}
			else
				ft_printf("\nUnknown Command: %s\n", line_split[j]);
			free(line_split[j]);
			++j;
		}
		ft_printf(":\n");
		free(line_split);
		if (checker(list_a, list_b, space_seperation))
		{
			list_free(list_a);
			list_free(list_b);
			return (0);
		}
	}
}
