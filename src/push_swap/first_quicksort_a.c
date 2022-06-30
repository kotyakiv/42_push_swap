/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_quicksort_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:59:28 by ykot              #+#    #+#             */
/*   Updated: 2022/06/30 16:00:06 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorta_mr_three(t_list **a, t_list **b, t_list **stack, t_qvar *q)
{
	int	pivot;

	pivot = find_pivot(*a, ft_lstsize(*a), 'a');
	q->num = *((int *)ft_lstelem(a, pivot)->content);
	q->t_l = *a;
	q->iter = ft_lstsize(*a) / 2;
	q->iterptr = &q->iter;
	ft_lstadd(&(*stack), ft_lstnew(q->iterptr, sizeof(int)));
	while (q->t_l && q->iter)
	{
		if (*((int *)q->t_l->content) < q->num)
		{
			print_and_do_command("pb", a, b);
			q->iter--;
		}
		else
			print_and_do_command("ra", a, b);
		q->t_l = q->t_l->next;
	}
}

/**
 * Push all elements to stack b, except the biggest three, which
 * are going to be sorted by three_sort_a algo later 
**/

void	first_quick_sort_a(t_list **a, t_list **b, t_list **stack)
{
	t_qvar	q;

	if (full_sorted_a(*a))
		return ;
	init_qvar(&q);
	while (ft_lstsize(*a) > 3)
		sorta_mr_three(a, b, stack, &q);
}
