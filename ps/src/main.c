/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:57:44 by hehuang           #+#    #+#             */
/*   Updated: 2018/12/05 15:40:28 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		free_linesplit(char **line_split)
{
	int	i;

	i = 0;
	while (line_split[i])
		free(line_split[i++]);
	free(line_split);
	return (0);
}

int		main(int ac, char **av)
{
	t_set		*set;
	int			steps;
	int			new_ac;
	char		**new_av;

	new_ac = get_new_ac(ac, av);
	if (!(new_av = ch_get_input_tokens(ac, av, new_ac)))
		return (0);
	if (!((set = process_argv(new_ac, new_av))))
	{
		free_linesplit(new_av);
		return (0);
	}
	if (is_solved(set))
	{
		free_set(set);
		free_linesplit(new_av);
		return (0);
	}
	steps = solve_with_explicit_instructions(set);
	ft_printf("%d\n", steps);
	free_set(set);
	free_linesplit(new_av);
	return (0);
}
