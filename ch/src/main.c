/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:23:15 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 13:53:33 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int			duplicate_check(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 2;
		while (j < ac)
		{
			if (!ft_strcmp(av[i], av[j]) && (i != j))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

static t_list		*fail_input_check(t_list *list_a)
{
	if (list_a)
		list_free(list_a);
	ft_printf("Error\n");
	return (NULL);
}

static t_list		*fill_lista(int ac, char **av)
{
	int			current;
	int			i;
	t_list	*list_a;

	i = 1;
	if (!duplicate_check(ac, av))
		return (fail_input_check(NULL));
	if (input_check(av[i]))
		current = ft_atoi(av[i++]);
	else
		return (fail_input_check(NULL));
	list_a = ft_lstnew(&current, sizeof(int));
	while (i < ac)
	{
		if (input_check(av[i]))
		{
			current = ft_atoi(av[i++]);
			if (current > INT_MAX)
			 	return (fail_input_check(list_a));
			if (!(list_a->node->next = ft_nodenew(&current, sizeof(int))))
				return (fail_input_check(list_a));
			list_a->node = list_a->node->next;
		}
		else
			return (fail_input_check(list_a));
	}
	return (list_a);
}

int					main(int ac, char **av)
{
	int		space_seperation;
	t_list	*list_a;
	t_list	*list_b;

	if (ac < 2 && av)
		return (0);
	list_b = ft_lstnew(NULL, 0);
	if ((!(list_a = fill_lista(ac, av))))
		return (0);
	list_a->node = list_a->head;
	space_seperation = get_space_seperation(list_a);
	print_lists(list_a, list_b, space_seperation);
	process_commands(list_a, list_b, space_seperation);
	return (0);
}
