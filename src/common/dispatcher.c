/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:52:05 by ykot              #+#    #+#             */
/*   Updated: 2022/06/30 18:16:19 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

static int	ss(t_list **a, t_list **b)
{
	if (ft_swap(a))
		return (1);
	if (ft_swap(b))
		return (1);
	return (0);
}

static int	rr(t_list **a, t_list **b)
{
	if (ft_rotate(a))
		return (1);
	if (ft_rotate(b))
		return (1);
	return (0);
}

static int	rrr(t_list **a, t_list **b)
{
	if (ft_revrotate(a))
		return (1);
	if (ft_revrotate(b))
		return (1);
	return (0);
}

/** 
 * A simple disatcher is used for more convinient navigation
**/

static int	sub_dispatcher(const char *str, t_list **a, t_list **b)
{
	if (!strcmp(str, "sa"))
		return (ft_swap(a));
	if (!strcmp(str, "sb"))
		return (ft_swap(b));
	if (!strcmp(str, "ss"))
		return (ss(a, b));
	if (!strcmp(str, "pa"))
		return (ft_push(a, b));
	if (!strcmp(str, "pb"))
		return (ft_push(b, a));
	if (!strcmp(str, "ra"))
		return (ft_rotate(a));
	if (!strcmp(str, "rb"))
		return (ft_rotate(b));
	if (!strcmp(str, "rr"))
		return (rr(a, b));
	if (!strcmp(str, "rra"))
		return (ft_revrotate(a));
	if (!strcmp(str, "rrb"))
		return (ft_revrotate(b));
	if (!strcmp(str, "rrr"))
		return (rrr(a, b));
	return (1);
}

void dispatcher(const char *str, t_list **a, t_list **b)
{
	if (sub_dispatcher(str, a, b))
	{
		error_mes(a, b);
		exit(0);
	}
}