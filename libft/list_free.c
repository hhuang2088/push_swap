/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:35:11 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/14 17:12:40 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	node_free(t_node *node)
{
	if (node->next)
		node_free(node->next);
	free(node->content);
	free(node);
}

void	list_free(t_list *list)
{
	if (list->head)
		node_free(list->head);
	free(list);
}
