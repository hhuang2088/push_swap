/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:25:13 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 13:25:15 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

int				get_list_size(t_list *list)
{
	int		count;

	count = 0;
	while (list && list->node)
	{
		++count;
		list->node = list->node->next;
	}
	list->node = list->head;
	return (count);
}
