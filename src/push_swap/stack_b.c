/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:21:06 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 15:43:32 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** 
 * Function checks is our list is completely sorted from the smallest
 * to the biggest value
**/

int	full_sorted_b(t_list *b)
{
	int	temp;

	while (b)
	{
		temp = *((int *)b->content);
		b = b->next;
		if (b == NULL)
			break ;
		if (temp < *((int *)b->content))
			return (0);
	}
	return (1);
}

/** 
 * Function checks is our list is sorted, but doesn't begin from the smallest 
 * value
**/

int	sorted_b(t_list *b)
{
	int		num;
	int		modflag;
	t_list	*temp;

	modflag = 0;
	temp = b;
	while (b)
	{
		num = *((int *)temp->content);
		temp = temp->next;
		if (temp == NULL)
			break ;
		if (!temp->next && *((int *)temp->content) < *((int *)b->content))
			return (0);
		if (num < *((int *)temp->content))
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

void	sort_three_b(t_list **a, t_list **b, t_list **stack)
{
	if (full_sorted_b(*b))
		return ;
	if (!sorted_b(*b))
		print_and_do_command("sb", a, b, stack);
	final_list_sort_b(a, b, stack);
}

/** 
 * Check if the fastest way to completely sort the list is to use command rb
**/

static int	fastest_way_to_sort_rb(t_list *b)
{
	int	num;
	int	elem;
	int	size;

	size = ft_lstsize(b);
	elem = 0;
	while (b)
	{
		num = *((int *)b->content);
		b = b->next;
		if (b == NULL)
			break ;
		if (num < *((int *)b->content))
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

void	final_list_sort_b(t_list **a, t_list **b, t_list **stack)
{
	if (full_sorted_b(*b))
		return ;
	if (fastest_way_to_sort_rb(*b))
		while (!full_sorted_b(*b))
			print_and_do_command("rb", a, b, stack);
	else
		while (!full_sorted_b(*b))
			print_and_do_command("rrb", a, b, stack);
}
