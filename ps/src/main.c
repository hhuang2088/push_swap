/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:57:44 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 15:58:41 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		main(int ac, char **av)
{
	t_set		*set;
	int			steps;

	if (!((set = process_argv(ac, av))))
		return (0);
	steps = solve_with_explicit_instructions(set);
	ft_printf("%d\n", steps);
	free_set(set);
	return (0);
}
