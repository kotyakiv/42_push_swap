#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	print_and_do_command(char *str, t_list **a, t_list **b);
int		read_arg(t_list **a, const char *argv);
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
int		find_pivot(t_list *a);
void	final_list_sort_a(t_list **a, t_list **b);
void	final_list_sort_b(t_list **a, t_list **b);
void	sort_three_a(t_list **a, t_list **b);
void	sort_three_b(t_list **a, t_list **b);
int		sorted_b(t_list *b);
int		sorted_a(t_list *a);
int		full_sorted_b(t_list *b);
int		full_sorted_a(t_list *a);

#endif
