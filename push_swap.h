#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct		s_qvar
{
	t_list *t_l;
	int	iter;
	int num;
	int *iterptr;
	int i;
	int left;
	int passed;
}					t_qvar;

typedef struct		s_svar
{
	int ps;
	int pb;
	int i;
	int j;
	int size;
	int *ptr;
	int num;
	t_list *t_l;
}					t_svar;

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
int		find_pivot(t_list *a, int size, char c);
void	final_list_sort_a(t_list **a, t_list **b);
void	final_list_sort_b(t_list **a, t_list **b);
void	sort_three_a(t_list **a, t_list **b);
void	sort_three_b(t_list **a, t_list **b);
int		sorted_b(t_list *b);
int		sorted_a(t_list *a);
int		full_sorted_b(t_list *b);
int		full_sorted_a(t_list *a);

void print_stack_s(t_list *a, t_list *b, t_list *c);
void quick_sort_b(t_list **a, t_list **b, t_list **stack, int *modflag);
void quick_sort_a(t_list **a, t_list **b, t_list **stack, int *modflag, int *c);
void passed_two_elem(t_list **a, t_list **b);
void init_qvar(t_qvar *q);
void	first_sort_to_stacks(t_list **a, t_list **b, t_list **stack);
void	algorithm(t_list **a, t_list **b);
void	wheel_algo(t_list **a, t_list **b);

#endif
