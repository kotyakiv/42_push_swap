/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:58:26 by ykot              #+#    #+#             */
/*   Updated: 2022/06/26 21:24:15 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void passed_two_elem(t_list **a, t_list **b)
{
	if ( *(int *)(*a)->content >  *(int *)(*a)->next->content)
	{
		if (ft_lstsize(*b) > 1 && *(int *)(*b)->content < *(int *)(*b)->next->content)
			print_and_do_command("ss", a, b);
		else
			print_and_do_command("sa", a, b);
	}
}

static void	left_passed_two_elem(t_list **a, t_list **b, t_list **stack)
{
	print_and_do_command("pa", a, b);
	print_and_do_command("pa", a, b);
	passed_two_elem(a, b);
	ft_lstdelelem(stack, 0, del);
}

static int	passed_left_elem(t_list **a, t_list **b, t_qvar *q, t_list **stack, int *modflag)
{
	if (q->passed == 2)
		passed_two_elem(a, b);
	q->left = *(int *)(*stack)->content - q->passed;
	if (q->left == 2)
	{
		left_passed_two_elem(a, b, stack);
		return (1);
	}
	if (q->left > 2)
	{
		q->iterptr = &q->left;
		ft_lstdelelem(stack, 0, del);
		ft_lstadd(stack, ft_lstnew(q->iterptr, sizeof(int)));
	}
	if (q->passed > 2)
	{
		*modflag = 1;
		q->iterptr = &q->passed;
		ft_lstadd(stack, ft_lstnew(q->iterptr, sizeof(int)));
		return (1);
	}
	return (0);
}

static void	sort_b_stack_more_two(t_list **a, t_list **b, t_qvar *q)
{
	if (*((int *)(q->t_l)->content) > q->num)
	{
		print_and_do_command("pa", a, b);
		q->iter--;
	}
	else
	{
		print_and_do_command("rb", a, b);
		++q->i;
	}
	q->t_l = q->t_l->next;
}

void quick_sort_b(t_list **a, t_list **b, t_list **stack, int *modflag)
{
	t_qvar q;

	if (*stack != NULL && *(int *)(*stack)->content == 2)
		left_passed_two_elem(a, b, stack);
	while (*stack != NULL && *(int *)(*stack)->content > 2)
	{
		init_qvar(&q);
		q.num = *((int *)ft_lstelem(b, find_pivot(*b, *(int *)(*stack)->content, 'b'))->content);
		q.t_l = *b;
		q.iter = *(int *)(*stack)->content / 2;
		q.passed = q.iter;
		while (q.i < *(int *)(*stack)->content && q.iter)
			sort_b_stack_more_two(a, b, &q);
		while (ft_lstsize(*stack) > 1 && q.i--)
			print_and_do_command("rrb", a, b);
		if (passed_left_elem(a, b, &q, stack, modflag))
			break ;
	}
}