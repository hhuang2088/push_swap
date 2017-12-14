/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:52:59 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 15:54:59 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		basic_solver(t_set *copy, int test)
{
	int steps;
	int max;

	max = get_max_rank(copy->list_a);
	steps = 0;
	while (!is_ascending(copy->list_a))
	{
		if (((t_value*)copy->list_a->node->content)->rank >
					((t_value*)copy->list_a->node->next->content)->rank &&
						((t_value*)copy->list_a->node->content)->rank != max)
		{
			lst_swap(copy->list_a);
			if (!test)
				ft_printf("sa\n");
		}
		else
		{
			lst_rotate(copy->list_a);
			if (!test)
				ft_printf("ra\n");
		}
		++steps;
	}
	refresh_position(copy->list_a);
	return (steps);
}

static int		pivot_sort(t_set *set, int partitions, int test)
{
	int steps;

	steps = 0;
	steps = populate_listb(set, partitions, test);
	steps += basic_solver(set, test);
	steps += repopulate_lista(set, test);
	return (steps);
}

int				find_best_partition(t_set *set, int list_size)
{
	int		steps;
	int		least_steps;
	int		best_partition;
	int		trial;
	t_set	*copy;

	trial = 1;
	best_partition = 1;
	least_steps = list_size * list_size * list_size;
	steps = least_steps + 1;
	while (trial < list_size / 5)
	{
		copy = copy_set(set);
		steps = pivot_sort(copy, trial, 1);
		free_set(copy);
		if (least_steps > steps)
		{
			best_partition = trial;
			least_steps = steps;
		}
		++trial;
	}
	return (best_partition);
}

int				solve_with_explicit_instructions(t_set *set)
{
	int	best_partition;
	int	least_steps;
	int	list_size;

	set->list_a->node = set->list_a->head;
	list_size = get_list_size(set->list_a);
	least_steps = list_size * list_size * list_size;
	best_partition = 1;
	if (list_size > 3)
	{
		best_partition = find_best_partition(set, list_size);
		least_steps = pivot_sort(set, best_partition, 0);
	}
	else
		least_steps = basic_solver(set, 0);
	if (is_solved(set))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_printf("best partition: %d\n", best_partition);
	return (least_steps);
}
