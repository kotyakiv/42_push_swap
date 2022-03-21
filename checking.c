/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:05:33 by ykot              #+#    #+#             */
/*   Updated: 2022/03/21 16:38:28 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	sorted(t_list *a)
{
	int	temp;

	while (a)
	{
		temp = *((int *)a->content);
		a = a->next;
		if (a == NULL)
			break ;
		if (temp > *((int *)a->content))
			return (1);
	}
	return (0);
}

void	print_result(t_list *a, t_list *b)
{
	if (sorted(a) || b != NULL)
		ft_putendl("KO");
	else
		ft_putendl("OK");
}

void	print_list(t_list *a)
{
	size_t	i;
	
	i = ft_lstsize(a);
	while (i--)
	{
		ft_printf("%d\n", *((int *)a->content));
		a = a->next;
	}
	ft_printf("end\n");
}