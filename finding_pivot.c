#include "push_swap.h"

void	print_and_do_command( char *str, t_list **a, t_list **b)
{
	dispatcher(str, a, b);
	ft_putendl(str);
}

static int	count_dif_in_pivot(t_list	*actual, t_list	**temp, int *dif, int left)
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

static int find_pivot_elem(int dif, int size, char c)
{
	if (c == 'a' && (dif == 1 || dif == 0))
		return (1);
	if (c == 'b' && (dif == -1 || dif == 0))
		return (1);
	if (c == 'c' && (dif <= (int) (size * - 0.4) && dif >= (int) (size * -0.5)))
		return (1);
	if (c == 'd' && (dif >= (int) (size * 0.4) && dif <= (int) (size * 0.5)))
		return (1);
	return (0);
}

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
