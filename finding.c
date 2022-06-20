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

int	find_pivot(t_list *a, int size)
{
	t_list	*temp;
	t_list	*actual;
	int		dif;
	int		elem;
	int		i;

	i = 1;
	elem = 0;
	actual = a;
	while (elem < size && actual)
	{
		dif = 0;
		temp = a;
		while (temp && i <= size)
		{
			if (find_pivot_if_tree(actual, &temp, &dif, size - i))
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
