/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:42:09 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 15:42:39 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_and_do_command( char *str, t_list **a, t_list **b, t_list **stack)
{
	dispatcher(str, a, b, stack);
	ft_putendl(str);
}

/**
 * Sorting passed two elements without adding to stack
**/

void	passed_two_elem(t_list **a, t_list **b, t_list **stack)
{
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
	{
		if (ft_lstsize(*b) > 1 && \
			*(int *)(*b)->content < *(int *)(*b)->next->content)
			print_and_do_command("ss", a, b, stack);
		else
			print_and_do_command("sa", a, b, stack);
	}
}
