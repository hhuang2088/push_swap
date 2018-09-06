/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:23:15 by hehuang           #+#    #+#             */
/*   Updated: 2018/03/22 15:58:45 by hehuang          ###   ########.fr       */
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

static t_list		*fill_lista(int ac, char **av)
{
	int			current;
	int			i;
	t_list		*list_a;

	i = 1;
	if (!duplicate_check(ac, av) || !(input_check(av[i])))
		return (fail_input_check(NULL, NULL));
	current = ft_atoi(av[i++]);
	if (!(list_a = ft_lstnew(&current, sizeof(int))))
		return (fail_input_check(NULL, NULL));
	while (i < ac)
	{
		if (input_check(av[i]))
		{
			current = ft_atoi(av[i++]);
			if (current > INT_MAX)
				return (fail_input_check(list_a, NULL));
			if (!(list_a->node->next = ft_nodenew(&current, sizeof(int))))
				return (fail_input_check(list_a, NULL));
			list_a->node = list_a->node->next;
		}
		else
			return (fail_input_check(list_a, NULL));
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
	if (space_seperation < 0)
	{
		fail_input_check(list_a, list_b);
		return (0);
	}
	print_lists(list_a, list_b, space_seperation);
	if (is_sorted(list_a))
		ft_printf("ok\n");
	process_commands(list_a, list_b, space_seperation);
	return (0);
}
