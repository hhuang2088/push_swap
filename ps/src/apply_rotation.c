/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:49:53 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 15:50:28 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	print_rotation(int rotate, int list_a, int test)
{
	if (rotate > 0 && list_a && !test)
		ft_printf("ra\n");
	else if (rotate < 0 && list_a && !test)
		ft_printf("rra\n");
	else if (rotate > 0 && !list_a && !test)
		ft_printf("rb\n");
	else if (rotate < 0 && !list_a && !test)
		ft_printf("rrb\n");
}

int			apply_rotation(t_list *list, int rotate, int list_a, int test)
{
	int steps;

	steps = 0;
	while (rotate != 0)
	{
		if (rotate > 0)
		{
			lst_rotate(list);
			print_rotation(rotate, list_a, test);
			--rotate;
		}
		else
		{
			lst_reverse_rotate(list);
			print_rotation(rotate, list_a, test);
			++rotate;
		}
		++steps;
	}
	return (steps);
}
