/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:00:55 by ykot              #+#    #+#             */
/*   Updated: 2022/06/27 17:09:25 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	check_full_sort(t_list **a, t_list **b)
{
	if (*b == NULL && sorted_a(*a))
	{
		final_list_sort_a(a, b);
		return (1);
	}
	return (0);
}
*/
static int	check_both_stacks_sort(t_list **a, t_list **b)
{
	if ((sorted_a(*a) || full_sorted_a(*a)) && (sorted_b(*b) || full_sorted_b(*b)))
	{
		if (sorted_a(*a))
			final_list_sort_a(a, b);
		if (sorted_b(*b))	
			final_list_sort_b(a, b);
		while (*b != NULL)
			print_and_do_command("pa", a, b);
		return (1);
	}
	return (0);
}

static int	sort_stack_less_four(t_list **a, t_list **b)
{
	int modflag;

	modflag = 0;
	if (ft_lstsize(*a) < 4 && !full_sorted_a(*a))
	{
		sort_three_a(a, b);
		modflag = 1;
	}
	if (*b != NULL && ft_lstsize(*b) < 4 && !full_sorted_b(*b))
	{
		sort_three_b(a, b);
		modflag = 1;
	}
	return (modflag);
}

static void algo_bigger_three(t_list **a, t_list **b)
{
	t_list	*stack;
	//int modflag;
	//int c;
	
	//modflag = 0;
	//c = 0;
	stack = NULL;
	if (*b == NULL && full_sorted_a(*a))
	{
		ft_lstdel(&stack, del);
		return ;
	}
	if (ft_lstsize(*a) > 6)
		first_sort_to_stacks(a, b, &stack);
	check_both_stacks_sort(a, b);
	sort_stack_less_four(a, b);
	check_both_stacks_sort(a, b);
	if (*b == NULL && full_sorted_a(*a))
	{
		ft_lstdel(&stack, del);
		return ;
	}
	wheel_algo(a, b);
	/*while (TRUE)
	{
		if (*b == NULL && full_sorted_a(*a))
		{
			ft_lstdel(&stack, del);
			return ;
		}
		if (check_both_stacks_sort(a, b))
			continue ;
		if (sort_stack_less_four(a, b))
			continue ;
		if (c != 0)
			quick_sort_b(a, b, &stack, &modflag);
		if (modflag && full_sorted_a(*a) && c == 1)
		{
			ft_lstdelelem(&stack, 0, del);
			modflag = 0;
			continue ;
		}
		quick_sort_a(a, b, &stack, &modflag, &c);
	}*/
}

void	algorithm(t_list **a, t_list **b)
{
	if (full_sorted_a(*a))
			return ;
	if (sorted_a(*a))
	{
		final_list_sort_a(a, b);
		return ;
	}
	if (ft_lstsize(*a) <= 3)
	{
		sort_three_a(a, b);
		return ;
	}
	algo_bigger_three(a, b);
}
