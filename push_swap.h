#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

int		read_arg(t_list **a, const char *argv);
int		sorted(t_list *a);
void	del(void *content, size_t size);
void	ft_swap(t_list **a);
void	ft_push(t_list **a, t_list **b);
void	ft_rotate(t_list **a);
void	ft_revrotate(t_list **a);
void	dispatcher(const char *str, t_list **a, t_list **b);
void	print_result(t_list *a, t_list *b);
void	print_list(t_list *a);
void	free_lists(t_list **a, t_list **b);
void	print_stack(t_list *a, t_list *b);
int		is_nfsort(t_list *a);
int		find_pivot(t_list *a);
int		find_min(t_list *a);
int		find_max(t_list *a);
void	sort_isnfullsort_list(t_list **a);

#endif