/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:00:55 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 12:56:50 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** 
 * Check if both lists sorted and if true, rotate them and push everything to
 * the list a
**/

int	check_both_stacks_sort(t_list **a, t_list **b, t_list **stack)
{
	if ((sorted_a(*a) || full_sorted_a(*a)) && \
		(sorted_b(*b) || full_sorted_b(*b)))
	{
		if (sorted_a(*a))
			final_list_sort_a(a, b, stack);
		if (sorted_b(*b))
			final_list_sort_b(a, b, stack);
		while (*b != NULL)
			print_and_do_command("pa", a, b, stack);
		return (1);
	}
	return (0);
}

/**
 * If one or both lists contain three or less elements, sorts them
**/

static int	sort_stack_less_four(t_list **a, t_list **b, t_list **stack)
{
	int	modflag;

	modflag = 0;
	if (ft_lstsize(*a) < 4 && !full_sorted_a(*a))
	{
		sort_three_a(a, b, stack);
		modflag = 1;
	}
	if (*b != NULL && ft_lstsize(*b) < 4 && !full_sorted_b(*b))
	{
		sort_three_b(a, b, stack);
		modflag = 1;
	}
	return (modflag);
}

/** 
 * Initializing satck and modflag.
 * If size is bigger than 20, first sort elements in three group with 
 * the same range values.
**/

static void	init_prev_sort(t_list **a, t_list **b, t_list **stack, int *modflag)
{
	*modflag = 0;
	*stack = NULL;
	if (ft_lstsize(*a) > 20)
		first_sort_to_stacks(a, b, stack);
	if (*b == NULL && full_sorted_a(*a))
	{
		ft_lstdel(stack, del);
		return ;
	}
	first_quick_sort_a(a, b, stack);
}

/**
 * Sort lists with more than 3 elements, using implemented quicksort algorithm.
 * In the list 'stack' numbers on how many elements is needed to be sorted.
 * modflag is used to know if there were changes in stack.
**/

static void	algo_bigger_three(t_list **a, t_list **b)
{
	t_list	*stack;
	int		modflag;

	init_prev_sort(a, b, &stack, &modflag);
	while (TRUE)
	{
		if (*b == NULL && full_sorted_a(*a))
		{
			ft_lstdel(&stack, del);
			return ;
		}
		if (check_both_stacks_sort(a, b, &stack))
			continue ;
		if (sort_stack_less_four(a, b, &stack))
			continue ;
		quick_sort_b(a, b, &stack, &modflag);
		if (modflag && full_sorted_a(*a))
		{
			ft_lstdelelem(&stack, 0, del);
			modflag = 0;
			continue ;
		}
		quick_sort_a(a, b, &stack, &modflag);
	}
}

/**
 * Main algorithm sorts the list if there is three or less elements
 * and sort them, or call another function
**/

void	algorithm(t_list **a, t_list **b)
{
	if (full_sorted_a(*a))
		return ;
	if (sorted_a(*a))
	{
		final_list_sort_a(a, b, NULL);
		return ;
	}
	if (ft_lstsize(*a) <= 3)
	{
		sort_three_a(a, b, NULL);
		return ;
	}
	algo_bigger_three(a, b);
}
