/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_optimal_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:06:04 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 16:07:01 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	undo_rotation(t_list *list, int rotate)
{
	if (rotate < 0)
	{
		while (rotate < 0)
		{
			lst_rotate(list);
			++rotate;
		}
	}
	else
	{
		while (rotate > 0)
		{
			lst_reverse_rotate(list);
			--rotate;
		}
	}
}

static int	find_rotate(t_list *copy, int lower_a, int upper_b)
{
	int			current;
	int			rotation;

	rotation = 0;
	current = ((t_value*)copy->node->content)->rank;
	while (!fits_in_partition(current, lower_a, upper_b))
	{
		lst_rotate(copy);
		current = ((t_value*)copy->node->content)->rank;
		++rotation;
	}
	undo_rotation(copy, rotation);
	return (rotation);
}

static int	apply_double_rotation(t_set *set, int rotation, int test)
{
	int steps;

	steps = 0;
	apply_rotation(set->list_a, rotation, 1, 1);
	steps += apply_rotation(set->list_b, rotation, 0, 1);
	if (!test)
	{
		while (rotation > 0)
		{
			ft_printf("rr\n");
			--rotation;
		}
	}
	return (steps);
}

int			apply_optimal_rotation(t_set *set, t_part *part, int test)
{
	int steps;
	int double_rotations;

	steps = 0;
	part->rotate_a = find_rotate(set->list_a, part->lower_a, part->upper_b);
	if (part->rotate_b && part->rotate_a > 0)
	{
		if (part->rotate_b < part->rotate_a)
			double_rotations = part->rotate_b;
		else
			double_rotations = part->rotate_a;
		steps += apply_double_rotation(set, double_rotations, test);
		part->rotate_a -= double_rotations;
		part->rotate_b -= double_rotations;
	}
	if (part->rotate_a > 0)
	{
		steps += apply_rotation(set->list_a, part->rotate_a - 1, 1, test);
		apply_last_ra(set, part, test);
		++steps;
	}
	return (steps);
}
