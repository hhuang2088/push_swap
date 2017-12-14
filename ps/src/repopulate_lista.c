/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repopulate_lista.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:59:08 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 16:00:07 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	optimized_pa(t_set *copy, int test)
{
	int rotate;
	int steps;

	steps = 1;
	if (copy->list_b->node->next)
		steps += optimized_sb(copy, 2, test);
	rotate = find_valid_position(copy->list_b->node->content, copy->list_a);
	steps += apply_rotation(copy->list_a, rotate, 1, test);
	lst_push(copy->list_a, copy->list_b);
	if (!test)
		ft_printf("pa\n");
	return (steps);
}

int			repopulate_lista(t_set *copy, int test)
{
	int	steps;
	int	size_b;
	int	rotate;

	steps = 0;
	size_b = get_list_size(copy->list_b);
	while (!is_solved(copy))
	{
		if (copy->list_b->node)
		{
			steps += optimized_pa(copy, test);
			--size_b;
		}
		else
		{
			rotate = get_number_of_rotations_to_solve(copy->list_a);
			steps += apply_rotation(copy->list_a, rotate, 1, test);
		}
		refresh_position(copy->list_a);
	}
	return (steps);
}
