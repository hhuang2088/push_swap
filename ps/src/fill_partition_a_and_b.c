/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_partition_a_and_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:07:59 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 16:09:12 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	push_value_into_list_b(t_set *set, t_part *part, int test)
{
	int steps;

	steps = 0;
	lst_push(set->list_b, set->list_a);
	if (!test)
		ft_printf("pb\n");
	++steps;
	--part->lista_size;
	++part->listb_size;
	if (part->listb_size > 1)
	{
		steps += swap_and_sort(set, part, test);
		if (part->p_switch == 1 && part->listb_size > 1)
			part->rotate_b += 1;
	}
	return (steps);
}

static int	push_into_right_partition_helper(t_set *set, t_part *part, int test)
{
	int steps;

	steps = 0;
	if (part->listb_size > 1)
	{
		++part->rotate_b;
		while (part->rotate_b > 0)
		{
			lst_rotate(set->list_b);
			if (!test)
				ft_printf("rb\n");
			++steps;
			--part->rotate_b;
		}
	}
	part->p_switch = 0;
	return (steps);
}

static int	push_into_right_partition(t_set *set, t_part *part, int test)
{
	int steps;

	steps = 0;
	if (fits_in_partition(part->current, part->lower_a, part->upper_a) &&
			part->p_switch == 0)
	{
		if (part->listb_size > 1)
		{
			lst_reverse_rotate(set->list_b);
			if (!test)
				ft_printf("rrb\n");
			++steps;
		}
		part->p_switch = 1;
	}
	else if (fits_in_partition(part->current, part->lower_b, part->upper_b) &&
			part->p_switch == 1)
	{
		steps += push_into_right_partition_helper(set, part, test);
	}
	steps += push_value_into_list_b(set, part, test);
	return (steps);
}

int			fill_partition_a_and_b(t_set *set, t_part *part, int test)
{
	int steps;

	steps = 0;
	while (part->listb_size < part->expected_size && part->lista_size > 3)
	{
		part->current = ((t_value*)set->list_a->node->content)->rank;
		if (fits_in_partition(part->current, part->lower_a, part->upper_b))
			steps += push_into_right_partition(set, part, test);
		else
			steps += apply_optimal_rotation(set, part, test);
	}
	--part->a;
	++part->b;
	return (steps);
}
