/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:35:16 by ykot              #+#    #+#             */
/*   Updated: 2022/06/30 16:22:32 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_list *a, t_list *b)
{
	int	i;
	int	j;

	i = 0;
	j = ft_bigger((long long)ft_lstsize(a), (long long)ft_lstsize(b));
	ft_printf("\t\t\tstack A\t\t\tstack B\n");
	while (i < j)
	{
		if (a)
		{
			ft_printf("%12d\t\t\t", *(int *)(a->content));
			a = a->next;
		}
		else
			ft_printf("%12c\t\t\t", ' ');
		if (b)
		{
			ft_printf("%12d", *(int *)(b->content));
			b = b->next;
		}
		else
			ft_printf("%12c\t\t\t", ' ');
		ft_putendl("");
		++i;
	}
}

void	print_result(t_list *a, t_list *b)
{
	if (full_sorted_a(a) && b == NULL)
		ft_putendl("OK");
	else
		ft_putendl("KO");
}
