/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:58:18 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 15:00:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		refresh_position_helper(t_list *list, int min, int max, int i)
{
	while (list->node)
	{
		((t_value*)list->node->content)->place = i++;
		if (list->node->next)
			((t_value*)(list->node->next->content))->previous =
				((t_value*)list->node->content)->rank;
		list->node = list->node->next;
	}
	list->node = list->head;
	while (list->node)
	{
		if (((t_value*)list->node->content)->rank == min)
		{
			((t_value*)list->node->content)->previous = max;
			break ;
		}
		((t_value*)list->node->content)->place = i++;
		if (!list->node->next)
			((t_value*)list->head->content)->previous =
				((t_value*)list->node->content)->rank;
		list->node = list->node->next;
	}
	list->node = list->head;
}

void			refresh_position(t_list *list)
{
	int		i;
	int		max;
	int		min;

	i = 0;
	min = get_min_rank(list);
	max = get_max_rank(list);
	while (list->node)
	{
		if (((t_value*)list->node->content)->rank != min)
			list->node = list->node->next;
		else
			break ;
	}
	refresh_position_helper(list, min, max, i);
}

t_set			*copy_set(t_set *set)
{
	t_set		*copy;

	if (!(copy = (t_set*)malloc(sizeof(t_set))))
		return (NULL);
	if (!(copy->list_a = copy_list(set->list_a)))
		copy->list_a = NULL;
	if (!(copy->list_b = copy_list(set->list_b)))
		copy->list_b = NULL;
	return (copy);
}

int				is_solved(t_set *set)
{
	if (is_sorted(set->list_a) && !get_list_size(set->list_b) &&
	((t_value*)set->list_a->node->content)->rank == 0)
		return (1);
	return (0);
}
