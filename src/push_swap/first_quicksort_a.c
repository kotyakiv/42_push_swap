/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_quicksort_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:59:28 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 17:37:09 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorta_mr_three(t_list **a, t_list **b, t_list **stack, t_qvar *q)
{
	int		pivot;
	t_list	*temp;

	pivot = find_pivot(*a, ft_lstsize(*a), 'a');
	q->num = *((int *)ft_lstelem(a, pivot)->content);
	q->tl = *a;
	q->iter = ft_lstsize(*a) / 2;
	q->iterptr = &q->iter;
	temp = ft_lstnew(q->iterptr, sizeof(int));
	if (!temp)
		error_mes(a, b, stack);
	ft_lstadd(&(*stack), temp);
	while (q->tl && q->iter)
	{
		if (*((int *)q->tl->content) < q->num)
		{
			print_and_do_command("pb", a, b, stack);
			q->iter--;
		}
		else
			print_and_do_command("ra", a, b, stack);
		q->tl = q->tl->next;
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
