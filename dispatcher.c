/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:52:05 by ykot              #+#    #+#             */
/*   Updated: 2022/03/21 20:45:32 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
}

static void	rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
}

static void	rrr(t_list **a, t_list **b)
{
	ft_revrotate(a);
	ft_revrotate(b);
}


void	dispatcher(const char *str, t_list **a, t_list **b)
{ 
	if (!strcmp(str, "sa"))
		ft_swap(a);
	if (!strcmp(str, "sb"))
		ft_swap(b);
	if (!strcmp(str, "ss"))
		ss(a, b);
	if (!strcmp(str, "pa"))
		ft_push(a, b);
	if (!strcmp(str, "pb"))
		ft_push(b, a);
	if (!strcmp(str, "ra"))
		ft_rotate(a);
	if (!strcmp(str, "rb"))
		ft_rotate(b);
	if (!strcmp(str, "rr"))
		rr(a, b);
	if (!strcmp(str, "rra"))
		ft_revrotate(a);
	if (!strcmp(str, "rrb"))
		ft_revrotate(b);
	if (!strcmp(str, "rrr"))
		rrr(a, b);
}