/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:50:53 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 15:52:19 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		is_ascending(t_list *list)
{
	while (list->node->next)
	{
		if (((t_value*)list->node->content)->rank >
					((t_value*)list->node->next->content)->rank)
		{
			list->node = list->head;
			return (0);
		}
		list->node = list->node->next;
	}
	list->node = list->head;
	return (1);
}

int		is_sorted(t_list *list)
{
	while (list->node)
	{
		if (((t_value*)list->node->content)->rank !=
									((t_value*)list->node->content)->place)
		{
			list->node = list->head;
			return (0);
		}
		list->node = list->node->next;
	}
	list->node = list->head;
	return (1);
}

int		get_max_rank(t_list *list)
{
	int	max;

	max = 0;
	while (list->node)
	{
		if (max < ((t_value*)list->node->content)->rank)
			max = ((t_value*)list->node->content)->rank;
		list->node = list->node->next;
	}
	list->node = list->head;
	return (max);
}

int		get_min_rank(t_list *list)
{
	int min;

	min = 0;
	if (list->node)
		min = ((t_value*)list->node->content)->rank;
	while (list->node)
	{
		if (min > ((t_value*)list->node->content)->rank)
			min = ((t_value*)list->node->content)->rank;
		list->node = list->node->next;
	}
	list->node = list->head;
	return (min);
}
