/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_sb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:06:51 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 15:49:27 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		simulate_steps_3(t_set *copy1, int ret, int moves)
{
	int		rotate1;
	int		rotate2;
	t_set	*copy2;
	int		ret_non_sb;

	copy2 = copy_set(copy1);
	rotate1 = find_valid_position(copy1->list_b->node->content, copy1->list_a);
	rotate2 = find_valid_position(copy2->list_b->node->content, copy2->list_a);
	ret_non_sb = ret;
	ret += apply_rotation(copy1->list_a, rotate1, 1, 1);
	ret_non_sb += apply_rotation(copy2->list_a, rotate2, 1, 1);
	lst_push(copy1->list_a, copy1->list_b);
	lst_push(copy2->list_a, copy2->list_b);
	ret = moves > 1 ?
		simulate_steps_1(copy1, 1, ++ret, moves - 1) : ++ret;
	ret_non_sb = moves > 1 ?
		simulate_steps_1(copy2, 0, ++ret_non_sb, moves - 1) : ++ret_non_sb;
	free_set(copy1);
	free_set(copy2);
	if (ret < ret_non_sb)
		return (ret);
	return (ret_non_sb);
}

static int		simulate_steps_2(t_set *copy1, int steps, int moves)
{
	int rotate1;
	int ret;

	ret = steps;
	rotate1 = find_valid_position(copy1->list_b->node->content, copy1->list_a);
	ret += apply_rotation(copy1->list_a, rotate1, 1, 1);
	lst_push(copy1->list_a, copy1->list_b);
	++ret;
	if (!copy1->list_b->node)
	{
		free_set(copy1);
		return (ret);
	}
	return (simulate_steps_3(copy1, ret, moves));
}

int				simulate_steps_1(t_set *set, int sb, int steps, int moves)
{
	t_set *copy1;

	copy1 = NULL;
	if (moves <= 0 || !set->list_b->node)
		return (steps + sb);
	copy1 = copy_set(set);
	if (sb)
	{
		lst_swap(copy1->list_b);
		++steps;
	}
	return (simulate_steps_2(copy1, steps, moves));
}

int				optimized_sb(t_set *set, int moves, int test)
{
	int		steps_pb;
	int		steps_non_pb;
	t_set	*copy1;
	t_set	*copy2;

	copy1 = copy_set(set);
	copy2 = copy_set(set);
	steps_non_pb = simulate_steps_1(copy1, 0, 0, moves);
	steps_pb = simulate_steps_1(copy2, 1, 0, moves);
	free_set(copy1);
	free_set(copy2);
	if (steps_pb < steps_non_pb)
	{
		lst_swap(set->list_b);
		if (!test)
			ft_printf("sb\n");
		return (1);
	}
	return (0);
}
