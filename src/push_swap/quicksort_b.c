/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:58:26 by ykot              #+#    #+#             */
/*   Updated: 2022/07/04 11:59:04 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * If there left two elements after pushing, push and sort them same as in
 * passed_two_elem function.
**/

static void	left_passed_two_elem(t_list **a, t_list **b, t_list **stack)
{
	print_and_do_command("pa", a, b, stack);
	print_and_do_command("pa", a, b, stack);
	passed_two_elem(a, b, stack);
	ft_lstdelelem(stack, 0, del);
}

static void	add_elem_stack(t_list **a, t_list **b, t_qvar *q, t_list **stack)
{
	t_list	*temp;

	temp = ft_lstnew(q->iterptr, sizeof(int));
	if (!temp)
		error_mes(a, b, stack);
	ft_lstadd(stack, temp);
}

/**
 * Checking how many elements were passed and left. Depends on that decide 
 * what to do:
 * 2 passed		- sort them
 * 2 left		- pass and sort them
 * >2 passed	- add number to stack and finish with all operations
 * none of above- continue sorting
**/

static int	passed_left_elem(t_list **a, t_list **b, t_qvar *q, t_list **stack)
{
	if (q->passed == 2)
		passed_two_elem(a, b, stack);
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
		add_elem_stack(a, b, q, stack);
	}
	if (q->passed > 2)
	{
		q->modflag = 1;
		q->iterptr = &q->passed;
		add_elem_stack(a, b, q, stack);
		return (1);
	}
	return (0);
}

/**
 * Elements that bigger than pivot pushed to stack a and smaller
 * to the bottom of stack b
**/

static void	sort_b_stack_more_two(t_list **a, t_list **b, t_qvar *q, \
			t_list **stack)
{
	if (*((int *)(q->tl)->content) > q->num)
	{
		print_and_do_command("pa", a, b, stack);
		q->iter--;
	}
	else
	{
		print_and_do_command("rb", a, b, stack);
		++q->i;
	}
	q->tl = q->tl->next;
}

/**
 * Sort elemnts using quicksort algorithm
**/

void	quick_sort_b(t_list **a, t_list **b, t_list **stack, int *modflag)
{
	t_qvar	q;
	int		pivot;

	if (*stack != NULL && *(int *)(*stack)->content == 2)
		left_passed_two_elem(a, b, stack);
	while (*stack != NULL && *(int *)(*stack)->content > 2)
	{
		ft_bzero(&q, sizeof(q));
		pivot = find_pivot(*b, *(int *)(*stack)->content, 'b');
		q.num = *((int *)ft_lstelem(b, pivot)->content);
		q.tl = *b;
		q.iter = *(int *)(*stack)->content / 2;
		q.passed = q.iter;
		q.modflag = *modflag;
		while (q.i < *(int *)(*stack)->content && q.iter)
			sort_b_stack_more_two(a, b, &q, stack);
		while (ft_lstsize(*stack) > 1 && q.i--)
			print_and_do_command("rrb", a, b, stack);
		if (passed_left_elem(a, b, &q, stack))
		{
			*modflag = q.modflag;
			break ;
		}
	}
}
