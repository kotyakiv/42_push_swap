#include "push_swap.h"

static int	find_pivot_if_tree(t_list	*actual, t_list	**temp, int *dif, int left)
{
	if (actual == *temp)
	{
		*temp = (*temp)->next;
		left--;
	}
	if (left == 0 || *temp == NULL)
		return (1);
	if (*((int *)actual->content) > *((int *)(*temp)->content))
		*dif += 1;
	if (*((int *)actual->content) < *((int *)(*temp)->content))
		*dif -= 1;
	return (0);
}

int	find_pivot_a(t_list *a, int size)
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
		while (temp && i < size)
		{
			if (find_pivot_if_tree(actual, &temp, &dif, size - elem))
				return (elem);
			temp = temp->next;
			++i;
		}
		if (dif == 1 || dif == 0)
			return (elem);
		++elem;
		actual = actual->next;
	}
	return (-1);
}

int	find_pivot_b(t_list *a, int size)
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
		//ft_printf("%d\n", (*(int *)temp->content));
		while (temp && i < size)
		{
			if (find_pivot_if_tree(actual, &temp, &dif, size - elem))
				return (elem);
			temp = temp->next;
			++i;
		}
		if (dif == -1 || dif == 0)
			return (elem);
		++elem;
		actual = actual->next;
	}
	return (-1);
}