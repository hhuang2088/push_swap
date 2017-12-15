/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:18:53 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/14 17:19:06 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*copy_list(t_list *src_list)
{
	t_list		*copy;

	if (!src_list->node)
	{
		copy = ft_lstnew(NULL, 0);
		return (copy);
	}
	copy = ft_lstnew(src_list->node->content, src_list->node->content_size);
	while (src_list->node->next)
	{
		copy->node->next = ft_nodenew(src_list->node->next->content,
				src_list->node->next->content_size);
		src_list->node = src_list->node->next;
		copy->node = copy->node->next;
	}
	src_list->node = src_list->head;
	copy->node = copy->head;
	return (copy);
}
