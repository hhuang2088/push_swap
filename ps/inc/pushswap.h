/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:41:52 by hehuang           #+#    #+#             */
/*   Updated: 2017/12/13 16:11:25 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSHSWAP_H
# define PUSHSWAP_H
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <wchar.h>
# include <inttypes.h>
# include "../../libft/libft.h"
# include "../../ft_printf/inc/ft_printf.h"
# include "../../ps_stack/inc/ps_stack.h"

typedef struct		s_part
{
	int				a;
	int				b;
	int				current;
	int				lower_a;
	int				upper_a;
	int				lower_b;
	int				upper_b;
	int				p_switch;
	int				lista_size;
	int				listb_size;
	int				expected_size;
	int				rotate_a;
	int				rotate_b;
}					t_part;

typedef struct		s_set
{
	t_list	*list_a;
	t_list	*list_b;
}					t_set;

typedef struct		s_value
{
	int				rank;
	int				place;
	int				previous;
}					t_value;

void				free_list(t_list *list);
void				free_set(t_set *set);
int					input_check(char *input);
int					is_sorted(t_list *list);
int					is_ascending(t_list *list);
t_set				*process_argv(int ac, char **av);
int					is_solved(t_set *set);
t_set				*copy_set(t_set *set);
int					solve_with_explicit_instructions(t_set *set);
void				refresh_position(t_list *list);
t_value				*value_new(int rank, int place);
int					get_rank_and_place_difference(t_node *node);
int					compare_two_nodes(t_node *node1, t_node *node2);
int					valid_midpoint(t_set *set);
int					get_max_rank(t_list *list);
int					get_min_rank(t_list *list);
int					is_smallest_value(t_node *node);
int					find_valid_position(t_value *value, t_list *list);
int					get_number_of_rotations_to_solve(t_list *list_a);
int					fits_in_partition(int current, int lower, int upper);
void				update_part(t_part *part, int initial_size, int partitions);
t_part				*get_part(int partition, int initial_size);
int					populate_listb(t_set *set, int partitions, int test);
int					fill_partition_a_and_b(t_set *set, t_part *part, int test);
int					repopulate_lista(t_set *copy, int test);
int					apply_optimal_rotation(t_set *set, t_part *part, int test);
int					swap_and_sort(t_set *set, t_part *part, int test);
int					optimized_sb(t_set	*set, int moves, int test);
int					apply_rotation(t_list *list, int rotate, int list_a,
																	int test);
int					simulate_steps_1(t_set *set, int sb, int steps, int moves);
void				apply_last_ra(t_set *set, t_part *part, int test);

#endif
