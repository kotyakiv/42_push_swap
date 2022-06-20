/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:27:21 by ykot              #+#    #+#             */
/*   Updated: 2022/06/20 16:49:03 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_and_do_command( char *str, t_list **a, t_list **b)
{
	dispatcher(str, a, b);
	ft_putendl(str);
}

static int	check_full_sort(t_list **a, t_list **b)
{
	if (sorted_a(*a) && b == NULL)
	{
		final_list_sort_a(a, b);
		return (1);
	}
	return (0);
}

static int	check_both_stacks_sort(t_list **a, t_list **b)
{
	if ((sorted_a(*a) || full_sorted_a(*a)) && (sorted_b(*b) || full_sorted_b(*b)))
	{
		if (sorted_a(*a))
			final_list_sort_a(a, b);
		if (sorted_b(*b))	
			final_list_sort_b(a, b);
		while (*b != NULL)
			print_and_do_command("pa", a, b);
		return (1);
	}
	return (0);
}

static void	sort_stack_less_four(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 4)
		sort_three_a(a, b);
	if (*b != NULL && ft_lstsize(*b) < 4 )
		sort_three_b(a, b);
}

static void	quick_sort_a(t_list **a, t_list **b, t_list **stack)
{
	int	iter;
	int num;
	int	*iterptr;
	t_list *temp_a;
	t_list *temp;
	
	if (full_sorted_a(*a))
		return ;
	
	if (*stack == NULL)
	{
		while (ft_lstsize(*a) > 3)
		{
			num = *((int *)ft_lstelem(a, find_pivot(*a))->content);
			temp_a = *a;
			iter = ft_lstsize(*a) / 2;
			iterptr = &iter;
			temp = ft_lstnew(iterptr, sizeof(int));
			ft_lstappend(&(*stack), temp);
			while (temp_a && iter)
			{
				if (*((int *)temp_a->content) < num)
				{
					print_and_do_command("pb", a, b);
					iter--;
				}
				else
					print_and_do_command("ra", a, b);
				temp_a = temp_a->next;
			}
		}
	}
	else
	{
		
	}
}

static void quick_sort_b(t_list **a, t_list **b, t_list **stack)
{
	int num;
	int iter;
	t_list	*temp_b;

	while (ft_lstsize(*b) > 3)
	{
		num = *((int *)ft_lstelem(b, find_pivot(*b))->content);
		temp_b = *b;
		iter = ft_lstsize(*b) / 2;
		while (temp_b && iter)
		{
			if (*((int *)temp_b->content) < num)
			{
				print_and_do_command("pa", a, b);
				iter--;
			}
			else
				print_and_do_command("rb", a, b);
			temp_b = temp_b->next;
		}
	}
}

static void algo_bigger_three(t_list **a, t_list **b)
{
	t_list	*stack;
	
	stack = NULL;
	while (/*full_sorted_a(*a) && b == NULL*/ 1)
	{
		/* Checkng for full sort */
		if (check_full_sort(a, b))
			return ;
		
		/* Checking if both stacks are sorted */
		if (check_both_stacks_sort(a, b))
			return ;
		
		/* if one of stack less than 4, sort it */
		sort_stack_less_four(a, b);
		
		/* sort stack a */
		quick_sort_a(a, b, &stack);
		
		/* sort stack b */
		quick_sort_b(a, b, &stack);
	}
}

static void	algorithm(t_list **a, t_list **b)
{
	if (full_sorted_a(*a))
			return ;
	if (sorted_a(*a))
	{
		final_list_sort_a(a, b);
		return ;
	}
	if (ft_lstsize(*a) <= 3)
	{
		sort_three_a(a, b);
		return ;
	}
	algo_bigger_three(a, b);
}

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	size_t	c;

	a = NULL;
	b = NULL;
	if (argc == 1)
	{
		ft_putendl("No arguments!");
		return (0);
	}
	c = 1;
	while ((int)c < argc)
	{
		if (read_arg(&a, argv[c]))
		{
			ft_putendl("Error");
			free_lists(&a, &b);
			return (0);
		}
		++c;
	}
	print_stack(a, b);
	ft_printf("--------------\n");
	algorithm(&a, &b);
	ft_printf("--------------\n");
	print_stack(a, b);
	free_lists(&a, &b);
	return (0);
}
