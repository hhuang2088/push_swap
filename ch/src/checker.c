#include "checker.h"

int	checker(t_list *list_a, t_list *list_b, int space_seperation)
{
	print_lists(list_a, list_b, space_seperation);
	if (list_b->node)
	{
		ft_printf("ko\n");
		ft_printf("--------------------------------------------------------------\n");
		return (0);
	}
	while (list_a->node->next)
	{
		if ((*(int*)(list_a->node->content)) > (*(int*)list_a->node->next->content))
		{
			list_a->node = list_a->head;
			list_b->node = list_b->head;
			ft_printf("ko\n");
			ft_printf("--------------------------------------------------------------\n");
			return (0);
		}
		list_a->node = list_a->node->next;
	}
	ft_printf("ok\n");
	ft_printf("--------------------------------------------------------------\n");
	list_a->node = list_a->head;
	list_b->node = list_b->head;
	return (1);
}
