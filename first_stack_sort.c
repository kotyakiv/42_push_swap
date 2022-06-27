/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:49:56 by ykot              #+#    #+#             */
/*   Updated: 2022/06/27 13:50:35 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	}
}

void	first_sort_to_stacks(t_list **a, t_list **b, t_list **stack)
{
	t_svar s;

	s.ps = *((int *)ft_lstelem(a, find_pivot(*a, ft_lstsize(*a), 'c'))->content);
	s.pb = *((int *)ft_lstelem(a, find_pivot(*a, ft_lstsize(*a), 'd'))->content);
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