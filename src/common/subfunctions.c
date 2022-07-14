/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:19:44 by ykot              #+#    #+#             */
/*   Updated: 2022/07/05 12:16:58 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	free_lists(t_list **a, t_list **b, t_list **stack)
{
	ft_lstdel(a, del);
	ft_lstdel(b, del);
	ft_lstdel(stack, del);
}

/** 
 * The function is used only to save space and use less lines in other functions
**/

void	error_mes(t_list **a, t_list **b, t_list **stack)
{
	ft_putendl_fd("Error", 2);
	free_lists(a, b, stack);
	exit(1);
}

/** 
 * Function checks is our list is completely sorted from the smallest
 * to the biggest value
**/

int	full_sorted_a(t_list *a)
{
	int	temp;

	while (a)
	{
		temp = *((int *)a->content);
		a = a->next;
		if (a == NULL)
			break ;
		if (temp > *((int *)a->content))
			return (0);
	}
	return (1);
}
