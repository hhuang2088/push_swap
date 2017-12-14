/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_listb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:02:13 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 15:03:10 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		populate_listb(t_set *set, int partitions, int test)
{
	t_part	*part;
	int		steps;
	int		initial_size;

	steps = 0;
	initial_size = get_list_size(set->list_a);
	part = get_part(partitions, initial_size);
	update_part(part, initial_size, partitions);
	while ((part->a - 1 >= 0 || part->b <= partitions) && part->lista_size > 3)
	{
		steps += fill_partition_a_and_b(set, part, test);
		update_part(part, initial_size, partitions);
	}
	free(part);
	return (steps);
}
