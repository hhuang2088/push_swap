/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:22:59 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 14:23:19 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		execute_push(t_list *list1, t_list *list2, char *command)
{
	lst_push(list1, list2);
	ft_printf(command);
	return (1);
}

int		execute_double_command(void (*f)(t_list*), t_list *list1,
												t_list *list2, char *command)
{
	if (list1->head)
		f(list1);
	if (list2->head)
		f(list2);
	ft_printf(command);
	return (1);
}

int		execute_command(void (*f)(t_list*), t_list *list, char *command)
{
	if (list->head)
		f(list);
	ft_printf(command);
	return (1);
}
