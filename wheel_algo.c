/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:26:30 by ykot              #+#    #+#             */
/*   Updated: 2022/06/27 17:04:12 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_all_elem_b(t_list **a, t_list **b)
{
	int size_a;

	size_a = ft_lstsize(*a);
	while (size_a-- <= 3)
	{
		print_and_do_command("pb", a, b);
	}
	sort_three_a(a, b);
}

static int position(int num, int a, int b)
{
	if (num < a && num < b)
		return (1);
	if (num > a && num > b)
		return (2);
	return (0);
}

static int scroll_up(t_list **a, t_list **b, int num)
{
	int i;
	int top;
	int bottom;
	int result_up;
	int result_down;

	i = 0;
	top = *((int *)(*a)->content);
	bottom = *((int *)(ft_lstelem(a, ft_lstsize(*a) - 1))->content);
	while (position(num, top, bottom))
	{
		top = *((int *)(*a)->content);
		bottom = *((int *)(ft_lstelem(a, ft_lstsize(*a) - 1))->content);
		dispatcher("ra", a, b);
		i++;
		result_up = i;
	}
	while (i--)
		dispatcher("rra", a, b);
	top = *((int *)(*a)->content);
	bottom = *((int *)(ft_lstelem(a, ft_lstsize(*a) - 1))->content);
	while (position(num, top, bottom))
	{
		top = *((int *)(*a)->content);
		bottom = *((int *)(ft_lstelem(a, ft_lstsize(*a) - 1))->content);
		dispatcher("rra", a, b);
		i++;
		result_down = i;
	}
	while (i--)
		dispatcher("ra", a, b);

	return (result_up - result_down);
}

static int push_a_scroll_a(t_list **a, t_list **b)
{
	int num;
	int top;
	int bottom;
	int pos;

	num = *((int *)(*b)->content);
	top = *((int *)(*a)->content);
	bottom = *((int *)(ft_lstelem(a, ft_lstsize(*a) - 1))->content);
	pos = position(num, top, bottom);
	if (pos == 1 || pos == 2)
		return (pos);
	if (scroll_up(a, b, num) >= 0)
		while (!position(num, top, bottom))
		{
			print_and_do_command("ra", a, b);
			top = *((int *)(*a)->content);
			bottom = *((int *)(ft_lstelem(a, ft_lstsize(*a) - 1))->content);
		}
	else
		while (!position(num, top, bottom))
		{
			print_and_do_command("rra", a, b);
			top = *((int *)(*a)->content);
			bottom = *((int *)(ft_lstelem(a, ft_lstsize(*a) - 1))->content);
		}
	pos = position(num, top, bottom);
	return (pos);
}
/*
static int push_a_scroll_b(t_list **a, t_list **b)
{

}
*/
void	wheel_algo(t_list **a, t_list **b)
{
	int pos;
	
	push_all_elem_b(a, b);
	while (ft_lstsize(*b) > 3)
	{
		pos = push_a_scroll_a(a, b);
		if (pos == 1)
			print_and_do_command("pa", a, b);
		if (pos == 2)
		{
			print_and_do_command("pa", a, b);
			print_and_do_command("ra", a, b);
		}
	}
	sort_three_b(a, b);	
}
