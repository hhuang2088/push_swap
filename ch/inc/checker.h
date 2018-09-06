/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:23:43 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 14:37:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <wchar.h>
# include <limits.h>
# include <inttypes.h>
# include "../../libft/libft.h"
# include "../../ft_printf/inc/ft_printf.h"
# include "../../ps_stack/inc/ps_stack.h"

int		checker(t_list *list_a, t_list *list_b, int space_seperation,
																int steps);
int		is_sorted(t_list *list);
void	print_lists(t_list *head_a, t_list *head_b, int space_seperation);
int		execute_command(void (*f)(t_list*), t_list *list, char *command);
int		execute_double_command(void (*f)(t_list*), t_list *list1,
												t_list *list2, char *command);
int		execute_push(t_list *list1, t_list *list2, char *command);
int		get_space_seperation(t_list *list);
char	*create_space(int space_seperation);
int		input_check(char *input);
void	process_commands(t_list *list_a, t_list *list_b, int space_seperation);
int		command_check(char **line_split);
int		is_int_input(char *input);
int		space_check(char **line_split, char *line);
t_list	*fail_input_check(t_list *list_a, t_list *list_b);

#endif
