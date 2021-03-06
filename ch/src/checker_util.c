/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:22:50 by hehuang           #+#    #+#             */
/*   Updated: 2018/12/07 00:30:27 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_sorted(t_list *list)
{
	if (list->node)
	{
		while (list->node->next)
		{
			if (*((int*)list->node->content) > *((int*)list->node->next->content))
			{
				list->node = list->head;
				return (0);
			}
			list->node = list->node->next;
		}
	}
	list->node = list->head;
	return (1);
}

int		get_space_seperation(t_list *list)
{
	char	*num_string;
	int		most_digits;
	int		digits;

	most_digits = 1;
	while (list->node)
	{
		if (!(num_string = ft_itoa(*(int*)list->node->content)))
			return (-1);
		digits = ft_strlen(num_string);
		if (most_digits < digits)
			most_digits = digits;
		free(num_string);
		list->node = list->node->next;
	}
	list->node = list->head;
	return (most_digits);
}

char	*create_space(int space_seperation)
{
	char	*space;
	int		i;

	i = 0;
	if (space_seperation > 0)
	{
		space = ft_strnew(space_seperation + 1);
		while (i < space_seperation)
		{
			space[i] = ' ';
			++i;
		}
	}
	else
		space = ft_strdup(" ");
	return (space);
}

int		input_check(char *input)
{
	int		i;

	i = 0;
	if (input[i] == '-')
		++i;
	else
	{
		if (ft_strlen(input) > 10)
			return (0);
	}
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (0);
		++i;
	}
	if (!is_int_input(input))
		return (0);
	return (1);
}
