/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:00:26 by hehuang           #+#    #+#             */
/*   Updated: 2018/09/05 16:55:52 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		normalize_input(int ac, int i, char **av)
{
	int		j;
	int		rank;

	j = 1;
	rank = 0;
	while (j < ac)
	{
		if (ft_atoi(av[i]) == ft_atoi(av[j]) && i != j)
			return (-1);
		if (ft_atoi(av[i]) > ft_atoi(av[j]))
			++rank;
		++j;
	}
	return (rank);
}

int				input_check(char *input)
{
	int		i;

	i = 0;
	if (input[i] == '-')
		++i;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (0);
		++i;
	}
	return (1);
}

static t_set	*error_handle(t_set *ret, int no_input_number)
{
	free_set(ret);
	if (no_input_number)
		ft_printf("No Input Number\n");
	else
		ft_printf("Error\n");
	return (NULL);
}

static int		process_input(t_set *ret, int ac, char **av, int i)
{
	t_value		*value;
	int			rank;

	if (input_check(av[i]))
	{
		rank = normalize_input(ac, i, av);
		if (rank == -1)
			return (0);
		value = value_new(normalize_input(ac, i, av), i - 1);
		if (!(ret->list_a->node->next = ft_nodenew(value, sizeof(value))))
			return (0);
		ret->list_a->node = ret->list_a->node->next;
	}
	else
		return (0);
	free(value);
	return (1);
}

t_set			*process_argv(int ac, char **av)
{
	int		i;
	t_set	*ret;
	t_value *value;

	i = 1;
	if (!(ret = (t_set*)malloc(sizeof(t_set))))
		return (NULL);
	if (!(ret->list_b = ft_lstnew(NULL, 0)))
		return (error_handle(ret, 0));
	if (ac < 2 && av)
		return (error_handle(ret, 1));
	if (!(value = value_new(normalize_input(ac, i++, av), 0)))
		return (error_handle(ret, 0));
	if (!(ret->list_a = ft_lstnew(value, sizeof(value))))
		return (error_handle(ret, 0));
	free(value);
	while (i < ac)
	{
		if (!process_input(ret, ac, av, i++))
			return (error_handle(ret, 0));
	}
	ret->list_a->node = ret->list_a->head;
	return (ret);
}
