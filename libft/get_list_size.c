/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:34:55 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/14 16:34:58 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
