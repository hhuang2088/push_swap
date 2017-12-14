/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:23:23 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 13:44:52 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		handle_vals(char *val_a, char *val_b, char *space)
{
	ft_printf("%s%s %s\n", val_a, space, val_b);
	free(val_a);
	free(val_b);
	free(space);
}

static void		print_lists_helper(t_list *list_a, t_list *list_b,
														int space_seperation)
{
	char	*val_a;
	char	*val_b;
	char	*space;
	int		len_val_a;

	while (list_a->node || list_b->node)
	{
		if (list_a->node)
			val_a = ft_itoa((*(int*)list_a->node->content));
		else
			val_a = ft_strdup(" ");
		len_val_a = ft_strlen(val_a);
		space = create_space(space_seperation - len_val_a + 1);
		if (list_b->node)
			val_b = ft_itoa((*(int*)list_b->node->content));
		else
			val_b = ft_strdup(" ");
		handle_vals(val_a, val_b, space);
		if (list_a->node)
			list_a->node = list_a->node->next;
		if (list_b->node)
			list_b->node = list_b->node->next;
	}
}

void			print_lists(t_list *list_a, t_list *list_b,
													int space_seperation)
{
	char	*space;

	print_lists_helper(list_a, list_b, space_seperation);
	space = create_space(space_seperation + 1);
	ft_printf("_%s_\n", space);
	ft_printf("a%sb\n", space);
	free(space);
	list_a->node = list_a->head;
	list_b->node = list_b->head;
}
