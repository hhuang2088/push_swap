/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:23:30 by hehuang           #+#    #+#             */
/*   Updated: 2018/09/05 16:54:28 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int			execute_input_command_helper(t_list *list_a, t_list *list_b,
						char *command)
{
	if (ft_strcmp("ra", command) == 0)
		return (execute_command(lst_rotate, list_a, "ra "));
	else if (ft_strcmp("rb", command) == 0)
		return (execute_command(lst_rotate, list_b, "rb "));
	else if (ft_strcmp("rr", command) == 0)
		return (execute_double_command(lst_rotate, list_a, list_b, "rr "));
	else if (ft_strcmp("rra", command) == 0)
		return (execute_command(lst_reverse_rotate, list_a, "rra "));
	else if (ft_strcmp("rrb", command) == 0)
		return (execute_command(lst_reverse_rotate, list_b, "rrb "));
	else if (ft_strcmp("rrr", command) == 0)
	{
		return (execute_double_command(lst_reverse_rotate,
					list_a, list_b, "rrr "));
	}
	ft_printf("Error\n");
	return (0);
}

static int			execute_input_command(t_list *list_a, t_list *list_b,
																char *command)
{
	if (ft_strcmp("sa", command) == 0)
		return (execute_command(lst_swap, list_a, "sa "));
	else if (ft_strcmp("sb", command) == 0)
		return (execute_command(lst_swap, list_b, "sb "));
	else if (ft_strcmp("ss", command) == 0)
		return (execute_double_command(lst_swap, list_a, list_b, "ss "));
	else if (ft_strcmp("pa", command) == 0)
		return (execute_push(list_a, list_b, "pa "));
	else if (ft_strcmp("pb", command) == 0)
		return (execute_push(list_b, list_a, "pb "));
	return (execute_input_command_helper(list_a, list_b, command));
}

static int			process_commands_helper(t_list *list_a, t_list *list_b,
															char **line_split,
																	int steps)
{
	int j;
	int	command_ret;

	j = 0;
	while (line_split[j])
	{
		command_ret = execute_input_command(list_a, list_b, line_split[j]);
		if (command_ret)
			steps += command_ret;
		else
		{
			free(line_split[j]);
			free(line_split);
			exit(0);
		}
		++j;
	}
	return (steps);
}

void				process_commands(t_list *list_a, t_list *list_b,
														int space_seperation)
{
	char			*line;
	char			**line_split;
	int				steps;

	steps = 0;
	while (get_next_line(0, &line))
	{
		line_split = ft_strsplit(line, ' ');
		if (!space_check(line_split, line) || !command_check(line_split))
		{
			fail_input_check(list_a, list_b);
			exit(0);
		}
		ft_printf("Exec ");
		steps = process_commands_helper(list_a, list_b, line_split, steps);
		ft_printf("Steps taken %d", steps);
		ft_printf(":\n");
		free(line_split);
		free(line);
		if (checker(list_a, list_b, space_seperation, steps))
			return ;
	}
}
