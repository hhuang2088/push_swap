/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:04:54 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 16:05:38 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		update_part(t_part *part, int initial_size, int partitions)
{
	if (part->a > 0)
		part->upper_a = (part->a * initial_size) / partitions;
	else
		part->upper_a = 0;
	part->lower_b = ((part->b - 1) * initial_size) / partitions;
	if (part->a - 1 > 0)
		part->lower_a = (((part->a - 1) * initial_size) / partitions);
	else
		part->lower_a = 0;
	if (part->b == partitions)
		part->upper_b = initial_size;
	else
		part->upper_b = (part->b * initial_size) / partitions;
	part->expected_size = part->upper_b - part->lower_a;
	if (part->expected_size > initial_size)
		part->expected_size = initial_size - 3;
}

t_part		*get_part(int partition, int initial_size)
{
	t_part *ret;

	if ((ret = malloc(sizeof(t_part))))
	{
		ret->a = partition / 2;
		ret->b = ret->a + 1;
		ret->p_switch = 0;
		ret->lista_size = initial_size;
		ret->listb_size = 0;
		ret->rotate_b = 0;
		ret->rotate_a = 0;
		return (ret);
	}
	return (NULL);
}
