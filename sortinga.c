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

static int	fastest_way_to_sort_rb(t_list *b)
{
	int	num;
	int elem;
	int	size;

	size = ft_lstsize(b);
	elem = 0;
	while (b)
	{
		num = *((int *)b->content);
		b = b->next;
		if (b == NULL)
			break ;
		if (num < *((int *)b->content))
		{
			if (size / 2 > elem)
				return (1);
		}
		elem++;
	}
	return (0);
}

void	final_list_sort_a(t_list **a)
{
	char *str;

	if (full_sorted_a(*a))
		return ;
	if (fastest_way_to_sort_ra(*a))
		str = ft_strdup("ra");
	else
		str = ft_strdup("rra");
	while (!full_sorted_a(*a))
		print_and_do_command(str, a, a);
}

void	final_list_sort_b(t_list **b)
{
	char *str;

	if (full_sorted_b(*b))
		return ;
	if (fastest_way_to_sort_rb(*b))
		str = ft_strdup("rb");
	else
		str = ft_strdup("rrb");
	while (!full_sorted_b(*b))
		print_and_do_command(str, b, b);
}

void	sort_three_a(t_list **a)
{
	if (full_sorted_a(*a))
		return ;
	if (!sorted_a(*a))
		print_and_do_command("sa", a, a);
	final_list_sort_a(a);
}

void	sort_three_b(t_list **b)
{
	if (full_sorted_b(*b))
		return ;
	if (!sorted_b(*b))
	print_and_do_command("sb", b, b);
	final_list_sort_b(b);
}