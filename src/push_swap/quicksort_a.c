/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:55 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 17:37:50 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Initializing variablles for quick_sort algorithm
**/

void	init_qvar(t_qvar *q)
{
	q->tl = NULL;
	q->iter = 0;
	q->num = 0;
	q->iterptr = NULL;
	q->i = 0;
	q->left = 0;
	q->passed = 0;
	q->modflag = 0;
}

static void	add_elem_stack(t_list **a, t_list **b, int	*ptr, t_list **stack)
{
	t_list	*temp;

	temp = ft_lstnew(ptr, sizeof(int));
	if (!temp)
		error_mes(a, b, stack);
	ft_lstadd(stack, temp);
}

/**
 * Checking how many elements were passed and left. Depends on that decide 
 * what to do:
 * 1 passed		- push it back to stck a
 * 2 passed		- sort them
 * 2 left		- sort them
 * >2 left		- add number to stack
 * >1 passed	- add number to stack
 * none of above- continue sorting
**/

static int	passed_left_el(t_list **a, t_list **b, int passed, t_list **stack)
{
	int		*iterptr;
	int		left;

	left = *(int *)(*stack)->content - passed;
	ft_lstdelelem(stack, 0, del);
	if (left == 2)
		passed_two_elem(a, b, stack);
	if (passed == 1)
	{
		print_and_do_command("pa", a, b, stack);
		return (1);
	}
	if (passed >= 2)
	{
		iterptr = &passed;
		add_elem_stack(a, b, iterptr, stack);
	}
	if (left >= 3)
	{
		iterptr = &left;
		add_elem_stack(a, b, iterptr, stack);
	}
	return (0);
}

/**
 * If number in a stack bigger than two, sort them
**/

static void	sort_a_stack_more_two(t_list **a, t_list **b, \
	t_list **stack, t_qvar *q)
{
	int	num;

	num = *(int *)(*stack)->content;
	q->i = 0;
	q->num = *((int *)ft_lstelem(a, find_pivot(*a, num, 'a'))->content);
	q->tl = *a;
	q->iter = num / 2;
	q->passed = q->iter;
	while (q->tl && q->iter)
	{
		if (*((int *)q->tl->content) < q->num)
		{
			print_and_do_command("pb", a, b, stack);
			q->iter--;
		}
		else
		{
			print_and_do_command("ra", a, b, stack);
			++q->i;
		}
		q->tl = q->tl->next;
	}
}

/**
 * Sorting elements using quicksort algo
**/

void	quick_sort_a(t_list **a, t_list **b, t_list **stack, int *modflag)
{
	t_qvar	q;

	if (full_sorted_a(*a))
		return ;
	init_qvar(&q);
	while (*stack != NULL && *(int *)(*stack)->content > 2)
	{
		*modflag = 0;
		sort_a_stack_more_two(a, b, stack, &q);
		while (ft_lstsize(*stack) > 1 && q.i--)
			print_and_do_command("rra", a, b, stack);
		if (passed_left_el(a, b, q.passed, stack))
			break ;
	}
}
