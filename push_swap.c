/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:27:21 by ykot              #+#    #+#             */
/*   Updated: 2022/05/26 21:15:29 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nfsort(t_list *a)
{
	int	temp;
	int modflag;

	modflag = 0;
	while (a)
	{
		temp = *((int *)a->content);
		a = a->next;
		if (a == NULL)
			break ;
		if (temp > *((int *)a->content))
		{
			if (modflag)
				return (0);
			else
				modflag = 1;
		}
	}
	return (1);
}

static void assign_mod(t_list *a, int *max, int *mod)
{
	*max = *((int *)a->content);
	*mod += 1;
}

int	find_pivot(t_list *a, int *max, int *min)
{
	int elem;
	int	max_mod;
	int min_mod;
	int size;
	int	i;
	
	size = ft_lstsize(a);
	*max = *((int *)a->content);
	*min = *((int *)a->content);
	i = 0;
	max_mod = 0;
	min_mod = 0;
	while (a)
	{
		if (*max < *((int *)a->content))
			assign_mod(a, max, &max_mod);
		if (*min > *((int *)a->content))
			assign_mod(a, min, &min_mod);
		if (max_mod == size / 2 || min_mod == size / 2)
			elem = i;
		a = a->next;
		i++;		
	}
	return (elem);
}

int main()
{
	
}