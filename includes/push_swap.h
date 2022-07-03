/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:31:48 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 17:40:45 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_qvar
{
	t_list	*tl;
	int		iter;
	int		num;
	int		*iterptr;
	int		i;
	int		left;
	int		passed;
	int		modflag;
}				t_qvar;

typedef struct s_svar
{
	int		ps;
	int		pb;
	int		i;
	int		j;
	int		size;
	int		*ptr;
	int		num;
	t_list	*tl;
}				t_svar;

void	print_and_do_command(char *str, t_list **a, t_list **b, t_list **stack);
int		read_arg(t_list **a, const char *argv);
void	del(void *content, size_t size);
int		ft_swap(t_list **a);
int		ft_push(t_list **a, t_list **b);
int		ft_rotate(t_list **a);
int		ft_revrotate(t_list **a);
void	dispatcher(const char *str, t_list **a, t_list **b, t_list **stack);
void	free_lists(t_list **a, t_list **b, t_list **stack);
int		find_pivot(t_list *a, int size, char c);
void	final_list_sort_a(t_list **a, t_list **b, t_list **stack);
void	final_list_sort_b(t_list **a, t_list **b, t_list **stack);
void	sort_three_a(t_list **a, t_list **b, t_list **stack);
void	sort_three_b(t_list **a, t_list **b, t_list **stack);
int		sorted_b(t_list *b);
int		sorted_a(t_list *a);
int		full_sorted_b(t_list *b);
int		full_sorted_a(t_list *a);
void	quick_sort_b(t_list **a, t_list **b, t_list **stack, int *modflag);
void	quick_sort_a(t_list **a, t_list **b, t_list **stack, int *modflag);
void	passed_two_elem(t_list **a, t_list **b, t_list **stack);
void	init_qvar(t_qvar *q);
void	first_sort_to_stacks(t_list **a, t_list **b, t_list **stack);
void	algorithm(t_list **a, t_list **b);
int		check_both_stacks_sort(t_list **a, t_list **b, t_list **stack);
void	first_quick_sort_a(t_list **a, t_list **b, t_list **stack);
void	error_mes(t_list **a, t_list **b, t_list **stack);

#endif
