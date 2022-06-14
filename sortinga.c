#include "push_swap.h"

static int	fastest_way_to_sort_ra(t_list *a)
{
	int	num;
	int elem;
	int	size;

	size = ft_lstsize(a);
	elem = 0;
	while (a)
	{
		num = *((int *)a->content);
		a = a->next;
		if (a == NULL)
			break ;
		if (num > *((int *)a->content))
		{
			if (size / 2 > elem)
				return (1);
		}
		elem++;
	}
	return (0);
}

void	sort_isnfullsort_list(t_list **a)
{
	char *str;

	if (fastest_way_to_sort_ra(*a))
		str = ft_strdup("ra");
	else
		str = ft_strdup("rra");
	while (!sorted(*a))
	{
		dispatcher(str, a, a);
		ft_putendl(str);
	}
}

void	sort_three(t_list **a)
{
	if (sorted(*a))
		return ;
	if (!is_nfsort(*a))
	{
		dispatcher("sa", a, a);
		ft_putendl("sa");
	}
	sort_isnfullsort_list(a);
}
