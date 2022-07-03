/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:19:44 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 12:39:23 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** 
 * Function checks is our list is sorted, but doesn't begin from the smallest 
 * value
**/

int	sorted_a(t_list *a)
{
	int		num;
	int		modflag;
	t_list	*temp;

	modflag = 0;
	temp = a;
	while (a)
	{
		num = *((int *)temp->content);
		temp = temp->next;
		if (temp == NULL)
			break ;
		if (!temp->next && *((int *)temp->content) > *((int *)a->content))
			return (0);
		if (num > *((int *)temp->content))
		{
			if (modflag)
				return (0);
			modflag = 1;
		}
	}
	return (1);
}

/** 
 * If the list consitis from three or less elements, the function sorts them
**/

void	sort_three_a(t_list **a, t_list **b, t_list **stack)
{
	if (full_sorted_a(*a))
		return ;
	if (!sorted_a(*a))
		print_and_do_command("sa", a, b, stack);
	final_list_sort_a(a, b, stack);
}

/** 
 * Check if the fastest way to completely sort the list is to use command ra
**/

static int	fastest_way_to_sort_ra(t_list *a)
{
	int	num;
	int	elem;
	int	size;

	size = ft_lstsize(a);
	elem = 0;
	while (a)
	{
		num = *((int *)a->content);
		a = a->next;
		if (a == NULL)
			break ;
		if (num > *((int *)a->content))
		{
			if (size / 2 > elem)
				return (1);
		}
		elem++;
	}
	return (0);
}

/** 
 * Rotate the sorted list until it fully sorted
**/

void	final_list_sort_a(t_list **a, t_list **b, t_list **stack)
{
	if (full_sorted_a(*a))
		return ;
	if (fastest_way_to_sort_ra(*a))
		while (!full_sorted_a(*a))
			print_and_do_command("ra", a, b, stack);
	else
		while (!full_sorted_a(*a))
			print_and_do_command("rra", a, b, stack);
}
