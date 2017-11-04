#include "checker.h"

void 	lst_swap(t_list *list)
{
	void			*tmp;

	tmp = NULL;
	if (list->node && list->node->next)
	{
		tmp = list->node->content;
		list->node->content = list->node->next->content;
		list->node->next->content = tmp;
		list->head = list->node;
	}
}

void		lst_push(t_list *dst_list, t_list *src_list)
{
	t_node	*top;

	top = NULL;
	if (src_list->node)
	{
		top = src_list->node;
		src_list->node = src_list->node->next;
		src_list->head = src_list->node;
		if (dst_list->node)
			top->next = dst_list->node;
		else
			top->next = NULL;
		dst_list->node = top;
		dst_list->head = dst_list->node;
	}
}

void		lst_rotate(t_list *list)
{
	t_node	*new_tail;

	if (list)
	{
		new_tail = list->head;
		if (list->node->next)
		{
			list->head = list->node->next;
			while (list->node->next)
				list->node = list->node->next;
			list->node->next = new_tail;
			list->node = list->node->next;
			list->node->next = NULL;
			list->node = list->head;
		}
	}
}

void 		lst_reverse_rotate(t_list *list)
{
	if (list)
	{
		if (list->node->next)
		{
			while(list->node->next->next)
				list->node = list->node->next;
			list->node->next->next = list->head;
			list->head = list->node->next;
			list->node->next = NULL;
			list->node = list->head;
		}
	}
}
