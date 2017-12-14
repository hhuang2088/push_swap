/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:55:18 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 15:57:21 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_value_location(t_list *list, int place)
{
	int	rotations;

	rotations = 0;
	while (((t_value*)list->node->content)->place != place)
	{
		list->node = list->node->next;
		++rotations;
	}
	list->node = list->head;
	return (rotations);
}

int	find_insertion_point(t_value *value, t_list *list)
{
	t_value	*current;
	int		min;
	int		place;

	min = 2147483647;
	place = -1;
	while (list->node)
	{
		current = (t_value*)list->node->content;
		if (value->rank < current->rank && min > current->rank)
		{
			min = current->rank;
			place = current->place;
		}
		list->node = list->node->next;
	}
	list->node = list->head;
	return (find_value_location(list, place));
}

int	find_valid_position(t_value *value, t_list *list)
{
	int	rotations;
	int	reverse;
	int	size;
	int	max;

	size = get_list_size(list);
	rotations = 0;
	max = get_max_rank(list);
	if (value->rank > max)
		rotations = find_value_location(list, 0);
	else
		rotations = find_insertion_point(value, list);
	reverse = size - rotations;
	list->node = list->head;
	if (reverse < rotations)
		return (-reverse);
	return (rotations);
}

int	get_number_of_rotations_to_solve(t_list *list)
{
	int	size;
	int	rotation;
	int	reverse;

	size = get_list_size(list);
	rotation = find_value_location(list, 0);
	reverse = size - rotation;
	if (reverse < rotation)
		return (-reverse);
	return (rotation);
}
