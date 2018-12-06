/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:02:25 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 16:04:31 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_set(t_set *set)
{
	if (set->list_a)
		list_free(set->list_a);
	if (set->list_b)
		list_free(set->list_b);
	free(set);
}

void	print_list(t_list *list)
{
	while (list->node)
	{
		ft_printf("rank: %d place: %d previous: %d\n",
		((t_value*)list->node->content)->rank,
		((t_value*)list->node->content)->place,
		((t_value*)list->node->content)->previous);
		list->node = list->node->next;
	}
	list->node = list->head;
}

void	apply_last_ra(t_set *set, t_part *part, int test)
{
	if (fits_in_partition(((t_value*)set->list_a->node->next->content)->rank,
												part->lower_b, part->upper_b)
												&& part->p_switch == 1
												&& part->listb_size > 1)
	{
		lst_rotate(set->list_a);
		lst_rotate(set->list_b);
		if (!test)
			ft_printf("rr\n");
		part->p_switch = 0;
	}
	else
	{
		lst_rotate(set->list_a);
		if (!test)
			ft_printf("ra\n");
	}
}
