/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_listb_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:03:36 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 15:05:48 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	swap_and_sort_helper(t_set *set, int list_a, int test)
{
	if (list_a)
	{
		lst_swap(set->list_a);
		if (!test)
			ft_printf("ss\n");
	}
	else
	{
		if (!test)
			ft_printf("sb\n");
	}
	lst_swap(set->list_b);
	return (1);
}

int			swap_and_sort(t_set *set, t_part *part, int test)
{
	if (((t_value*)set->list_b->node->content)->rank <
		((t_value*)set->list_b->node->next->content)->rank)
	{
		if (fits_in_partition(
					((t_value*)set->list_a->node->next->content)->rank,
					part->lower_a, part->upper_b) &&
				!fits_in_partition(
					((t_value*)set->list_a->node->content)->rank,
					part->lower_a, part->upper_b))
			return (swap_and_sort_helper(set, 1, test));
		else
			return (swap_and_sort_helper(set, 0, test));
	}
	return (0);
}

int			fits_in_partition(int current, int lower, int upper)
{
	if (current >= lower && current < upper)
		return (1);
	return (0);
}
