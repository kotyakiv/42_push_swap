#include "checker.h"

void	free_lists(t_list **a, t_list **b)
{
	ft_lstdel(&(*a), del);
	ft_lstdel(&(*b), del);
}

void print_stack(t_list *a, t_list *b)
{
	t_list	*t_a;
	t_list	*t_b;
	size_t	i;
	size_t	j;

	t_a = a;
	t_b = b;
	i = 0;
	j = ft_bigger((long long)ft_lstsize(a), (long long)ft_lstsize(b));
	ft_printf("stack A\t\t\tstack B\n");
	while (i < j)
	{
		if (t_a)
		{
			ft_printf("%5d\t\t\t", *(int *)(t_a->content));
			t_a = t_a->next;
		}
		else
			ft_printf("%5c\t\t\t", ' ');
		if (t_b)
		{
			ft_printf("%5d", *(int *)(t_b->content));
			t_b = t_b->next;
		}
		else
			ft_printf("%5c\t\t\t", ' ');
		ft_putendl("");
		++i;
	}
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
