/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:22:28 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 14:03:41 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		checker_helper(t_list *list_a, t_list *list_b, int steps)
{
	ft_printf("ok\n");
	ft_printf("-----------------------------------------------------------\n");
	list_a->node = list_a->head;
	list_b->node = list_b->head;
	list_free(list_a);
	list_free(list_b);
	ft_printf("Completed in %d steps!!!\n", steps);
	return (1);
}

int				checker(t_list *list_a, t_list *list_b, int space_seperation,
																	int steps)
{
	print_lists(list_a, list_b, space_seperation);
	if (list_b->node)
	{
		ft_printf("ko\n");
		ft_printf("------------------------------------------------------\n");
		return (0);
	}
	while (list_a->node->next)
	{
		if ((*(int*)(list_a->node->content)) >
				(*(int*)list_a->node->next->content))
		{
			list_a->node = list_a->head;
			list_b->node = list_b->head;
			ft_printf("ko\n");
			ft_printf("---------------------------------------------------\n");
			return (0);
		}
		list_a->node = list_a->node->next;
	}
	return (checker_helper(list_a, list_b, steps));
}
