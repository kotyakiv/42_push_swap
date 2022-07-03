/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:22:40 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 15:42:24 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Count differnce in the list. If the number is bigger than other value add 1,
 * otherwise minus 1
**/

static int	count_dif_in_pivot(t_list *actual, t_list **temp, int *dif, int lf)
{
	if (actual == *temp)
	{
		*temp = (*temp)->next;
		lf--;
	}
	if (lf == 0 || *temp == NULL)
		return (1);
	if (*((int *)actual->content) > *((int *)(*temp)->content))
		*dif += 1;
	if (*((int *)actual->content) < *((int *)(*temp)->content))
		*dif -= 1;
	return (0);
}

/**
 * Find pivots depends on their differnce:
 * a : in list a
 * b : in list b
 * c : small pivot in list a
 * d : big pivot in list a
**/

static int	find_pivot_elem(int dif, int size, char c)
{
	if (c == 'a' && (dif == 1 || dif == 0))
		return (1);
	if (c == 'b' && (dif == -1 || dif == 0))
		return (1);
	if (c == 'c' && (dif <= (int)(size * -0.31) && dif >= (int)(size * -0.34)))
		return (1);
	if (c == 'd' && (dif >= (int)(size * 0.31) && dif <= (int)(size * 0.34)))
		return (1);
	return (0);
}

/**
 * Find pivots in lists depended on our requests
**/

int	find_pivot(t_list *a, int size, char c)
{
	t_list	*temp;
	t_list	*actual;
	int		dif;
	int		elem;
	int		i;

	elem = 0;
	actual = a;
	while (elem < size && actual)
	{
		i = 1;
		dif = 0;
		temp = a;
		while (temp && i++ < size)
		{
			if (count_dif_in_pivot(actual, &temp, &dif, size - elem))
				return (elem);
			temp = temp->next;
		}
		if (find_pivot_elem(dif, size, c))
			return (elem);
		++elem;
		actual = actual->next;
	}
	return (0);
}
