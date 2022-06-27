/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:55 by ykot              #+#    #+#             */
/*   Updated: 2022/06/26 20:35:52 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_qvar(t_qvar *q)
{
	q->t_l = NULL;
	q->iter = 0;
	q->num = 0;
	q->iterptr = NULL;
	q->i = 0;
	q->left = 0;
	q->passed = 0;
}

static int	passed_left_elem(t_list **a, t_list **b, int passed, t_list **stack)
{
	int	*iterptr;
	int left;
	
	left = *(int *)(*stack)->content - passed;
	ft_lstdelelem(stack, 0, del);
	if (left == 2)
		passed_two_elem(a, b);
	if (passed == 1)
	{
		print_and_do_command("pa", a, b);
		return (1);
	}
	if (passed >= 2)
	{
		iterptr = &passed;
		ft_lstadd(stack, ft_lstnew(iterptr, sizeof(int)));
	}
	if (left >= 3)
	{
		iterptr = &left;
		ft_lstadd(stack, ft_lstnew(iterptr, sizeof(int)));
	}
	return (0);
}

static void	sort_a_more_three_elem(t_list **a, t_list **b, t_list **stack, t_qvar *q)
{
	q->num = *((int *)ft_lstelem(a, find_pivot(*a, ft_lstsize(*a), 'a'))->content);
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

static void	sort_a_stack_more_two(t_list **a, t_list **b, t_list **stack, t_qvar *q)
{
	q->i = 0;
	q->num = *((int *)ft_lstelem(a, find_pivot(*a, *(int *)(*stack)->content, 'a'))->content);
	q->t_l = *a;
	q->iter = *(int *)(*stack)->content / 2;
	q->passed = q->iter;
	while (q->t_l && q->iter)
	{
		if (*((int *)q->t_l->content) < q->num)
		{
			print_and_do_command("pb", a, b);
			q->iter--;
		}
		else
		{
			print_and_do_command("ra", a, b);
			++q->i;
		}
		q->t_l = q->t_l->next;
	}
}

void	quick_sort_a(t_list **a, t_list **b, t_list **stack, int *modflag, int *c)
{
	t_qvar q;
	
	if (full_sorted_a(*a) && *c == 1)
		return ;
	init_qvar(&q);
	if (*c == 0)
	{
		while (ft_lstsize(*a) > 3)
			sort_a_more_three_elem(a, b, stack, &q);
		*c = 1;
	}
	else
	{
		while (*stack != NULL && *(int *)(*stack)->content > 2)
		{
			*modflag = 0;
			sort_a_stack_more_two(a, b, stack, &q);
			while (ft_lstsize(*stack) > 1 && q.i--)
				print_and_do_command("rra", a, b);
			if (passed_left_elem(a, b, q.passed, stack))
				break ;
		}
	}
}