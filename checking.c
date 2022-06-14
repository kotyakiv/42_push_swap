/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:05:33 by ykot              #+#    #+#             */
/*   Updated: 2022/06/14 16:38:52 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sorted(t_list *a)
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

int	rev_sorted(t_list *a)
{
	int	temp;

	while (a)
	{
		temp = *((int *)a->content);
		a = a->next;
		if (a == NULL)
			break ;
		if (temp < *((int *)a->content))
			return (0);
	}
	return (1);
}


int	is_nfsort(t_list *a)
{
	int	num;
	int modflag;
	t_list	*temp;
	
	modflag = 0;
	temp = a;
	while (a)
	{
		num = *((int *)temp->content);
		temp = temp->next;
		if (temp == NULL)
			break ;
		if (temp->next == NULL &&  *((int *)temp->content) > *((int *)a->content))
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
