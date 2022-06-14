#include "push_swap.h"

int	find_min(t_list *a)
{
	int	min;
	int	elem;
	int i;
	
	min = *((int *)a->content);
	elem = 0;
	i = 0;
	while (a)
	{
		if (min > *((int *)a->content))
		{
			min = *((int *)a->content);
			elem = i;
		}
		a = a->next;
		++i;
	}
	return (elem);
}

int	find_max(t_list *a)
{
	int	max;
	int	elem;
	int i;
	
	max = *((int *)a->content);
	elem = 0;
	i = 0;
	while (a)
	{
		if (max < *((int *)a->content))
		{
			max = *((int *)a->content);
			elem = i;
		}
		a = a->next;
		++i;
	}
	return (elem);
}

static int	find_pivot_if_tree(t_list	*actual, t_list	*temp, int *dif)
{
	if (actual == temp)
		temp = temp->next;
	if (temp == NULL)
		return (1);
	if (*((int *)actual->content) > *((int *)temp->content))
		*dif += 1;
	if (*((int *)actual->content) < *((int *)temp->content))
		*dif -= 1;
	return (0);
}

int	find_pivot(t_list *a)
{
	t_list	*temp;
	t_list	*actual;
	int		dif;
	int		elem;

	elem = 0;
	actual = a;
	while (actual)
	{
		dif = 0;
		temp = a;
		while (temp)
		{
			if (find_pivot_if_tree(actual, temp, &dif))
				return (elem);
			temp = temp->next;
		}
		if (dif == 0 || dif == 1 || dif == -1)
			return (elem);
		++elem;
		actual = actual->next;
	}
	return (elem);
}
