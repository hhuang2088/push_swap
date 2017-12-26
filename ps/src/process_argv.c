/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:00:26 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 16:02:07 by hehuang          ###   ########.fr       */
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

static int		error_handle(t_set *ret)
{
	free_set(ret);
	ft_printf("Error\n");
	return (0);
}

static int		process_input(t_set *ret, int ac, char **av, int i)
{
	t_value		*value;
	int				rank;

	if (input_check(av[i]))
	{
		rank = normalize_input(ac, i, av);
		if (rank == -1)
			return (error_handle(ret));
		value = value_new(normalize_input(ac, i, av), i - 1);
		if (!(ret->list_a->node->next = ft_nodenew(value, sizeof(value))))
			return (error_handle(ret));
		ret->list_a->node = ret->list_a->node->next;
	}
	else
		return (error_handle(ret));
	free(value);
	return (1);
}

t_set			*process_argv(int ac, char **av)
{
	int		i;
	t_set	*ret;
	t_value *value;

	i = 1;
	ret = (t_set*)malloc(sizeof(t_set));
	ret->list_b = ft_lstnew(NULL, 0);
	if (ac < 2 && av)
	{
		ft_printf("No Input Number\n");
		return (NULL);
	}
	value = value_new(normalize_input(ac, i++, av), 0);
	ret->list_a = ft_lstnew(value, sizeof(value));
	free(value);
	while (i < ac)
	{
		if (!process_input(ret, ac, av, i++))
			return (NULL);
	}
	ret->list_a->node = ret->list_a->head;
	return (ret);
}
