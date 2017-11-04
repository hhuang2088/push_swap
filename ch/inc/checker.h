#ifndef CHECKER_H
# define CHECKER_H
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <wchar.h>
# include <inttypes.h>
# include "../../libft/libft.h"
# include "../../ft_printf/inc/ft_printf.h"

int		checker(t_list *list_a, t_list *list_b, int space_seperation);
void 	lst_swap(t_list *head);
void	lst_push(t_list *head1, t_list *head2);
void	lst_rotate(t_list *list);
int		is_sorted(t_list *list);
void	lst_reverse_rotate(t_list *list);
void 	print_lists(t_list *head_a, t_list *head_b, int space_seperation);
void	handle_reverse_rotate(t_list *list, char *command);
int		get_space_seperation(t_list *list);
char	*create_space(int space_seperation);
void 	list_free(t_list *list);
int		input_check(char *input);

#endif
