/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:49:56 by ykot              #+#    #+#             */
/*   Updated: 2022/06/30 15:57:50 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checking if there are still any elements to push
**/

static int	left_elem_to_push(t_list *a, int big_pivot)
{
	while (a)
	{
		if (*(int *)a->content < big_pivot)
			return (0);
		a = a->next;
	}
	return (1);
}

/**
 * Push elements that less than biggest pivot to stack b and if some elements 
 * less than small pivot rotate them to the bottom of stack b
**/

static void	sort_to_stacks_loop(t_svar *s, t_list **a, t_list **b)
{
	while (s->size--)
	{
		s->num = *(int *)s->t_l->content;
		if (s->num < s->pb)
		{
			print_and_do_command("pb", a, b);
			s->i++;
			if (s->num < s->ps)
			{
				s->j++;
				if (ft_lstsize(*b) > 1)
				{
					print_and_do_command("rb", a, b);
					s->t_l = *a;
					continue ;
				}
			}
		}
		else
			print_and_do_command("ra", a, b);
		s->t_l = s->t_l->next;
		if (left_elem_to_push(*a, s->pb))
			return ;
	}
}

/**
 * Find to pivots (usually 33% and 66% of a stack size) and sort them to 
 * three differnets group. One in stack a and two to stack b
**/

void	first_sort_to_stacks(t_list **a, t_list **b, t_list **stack)
{
	t_svar	s;
	int		pivot;

	pivot = find_pivot(*a, ft_lstsize(*a), 'c');
	s.ps = *((int *)ft_lstelem(a, pivot)->content);
	pivot = find_pivot(*a, ft_lstsize(*a), 'd');
	s.pb = *((int *)ft_lstelem(a, pivot)->content);
	s.i = 0;
	s.j = 0;
	s.size = ft_lstsize(*a);
	s.t_l = *a;
	sort_to_stacks_loop(&s, a, b);
	s.ptr = &s.j;
	ft_lstadd(stack, ft_lstnew(s.ptr, sizeof(int)));
	s.ptr = &s.i;
	s.i -= s.j;
	ft_lstadd(stack, ft_lstnew(s.ptr, sizeof(int)));
}
