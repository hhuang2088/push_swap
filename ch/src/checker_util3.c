/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:02:24 by hehuang           #+#    #+#             */
/*   Updated: 2018/03/22 16:02:30 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			space_check(char **line_split, char *line)
{
	int		i;
	int		j;
	int		spaces;

	i = 0;
	j = 0;
	spaces = 0;
	while (line_split[i])
		++i;
	while (line[j])
	{
		if (line[j] == ' ')
			++spaces;
		++j;
	}
	if (spaces != i - 1)
		return (0);
	return (1);
}

t_list		*fail_input_check(t_list *list_a, t_list *list_b)
{
	if (list_a)
		list_free(list_a);
	if (list_b)
		list_free(list_b);
	ft_printf("Error\n");
	return (NULL);
}
