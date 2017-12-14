#ifndef PS_STACK_H
# define PS_STACK_H
# include "../../libft/libft.h"
# include <stdlib.h>


int			get_list_size(t_list *list);
t_list		*copy_list(t_list *src_list);
void 		lst_swap(t_list *list);
void		lst_push(t_list *dst_list, t_list *src_list);
void		lst_rotate(t_list *list);
void 		lst_reverse_rotate(t_list *list);
void 		free_list(t_list *list);

#endif
