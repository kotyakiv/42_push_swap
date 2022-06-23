/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:27:21 by ykot              #+#    #+#             */
/*   Updated: 2022/06/23 21:29:40 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_full_sort(t_list **a, t_list **b)
{
	if (b == NULL && sorted_a(*a))
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

static int	sort_stack_less_four(t_list **a, t_list **b)
{
	int modflag;

	modflag = 0;
	if (ft_lstsize(*a) < 4 && !full_sorted_a(*a))
	{
		sort_three_a(a, b);
		modflag = 1;
	}
	if (*b != NULL && ft_lstsize(*b) < 4 && !full_sorted_b(*b))
	{
		sort_three_b(a, b);
		modflag = 1;
	}
	return (modflag);
}

static void quick_sort_b(t_list **a, t_list **b, t_list **stack, int *modflag)
{
	int num;
	int iter;
	int i;
	int *iterptr;
	int passed;
	int left;
	t_list	*temp_b;
	
	if (*stack != NULL && *(int *)(*stack)->content == 2)
	{
		ft_lstdelelem(stack, 0, del);
		print_and_do_command("pa", a, b);
		print_and_do_command("pa", a, b);
		if ( *(int *)(*a)->content >  *(int *)(*a)->next->content)
					print_and_do_command("sa", a, b);
	}
	
	while (*stack != NULL && *(int *)(*stack)->content > 2)
	{
		i = 0;
		num = *((int *)ft_lstelem(b, find_pivot_b(*b, *(int *)(*stack)->content))->content);
		temp_b = *b;
		iter = *(int *)(*stack)->content / 2;
		passed = iter;
		while (i < *(int *)(*stack)->content && iter)
		{
			if (*((int *)temp_b->content) > num)
			{
				print_and_do_command("pa", a, b);
				iter--;
			}
			else
			{
				print_and_do_command("rb", a, b);
				++i;
			}
			temp_b = temp_b->next;
		}
	
		while (ft_lstsize(*stack) > 1 && i--)
			print_and_do_command("rrb", a, b);


		if (passed == 2)
		{
			if ( *(int *)(*a)->content >  *(int *)(*a)->next->content)
					print_and_do_command("sa", a, b);
		}
		
		left = *(int *)(*stack)->content - passed;
		if (left == 2)
		{
			print_and_do_command("pa", a, b);
			print_and_do_command("pa", a, b);
			if ( *(int *)(*a)->content >  *(int *)(*a)->next->content)
				print_and_do_command("sa", a, b);
			ft_lstdelelem(stack, 0, del);
			break ;
		}
		
		if (left > 2)
		{
			iterptr = &left;
			ft_lstdelelem(stack, 0, del);
			ft_lstadd(stack, ft_lstnew(iterptr, sizeof(int)));
		}
		if (passed > 2)
		{
			*modflag = 1;
			iterptr = &passed;
			ft_lstadd(stack, ft_lstnew(iterptr, sizeof(int)));
			break ;
		}
	}
}

static void	quick_sort_a(t_list **a, t_list **b, t_list **stack, int *modflag)
{
	int	iter;
	int num;
	int	*iterptr;
	t_list *temp_a;
	int i;
	int passed;
	int left;

	if (*modflag && full_sorted_a(*a))
	{
		ft_lstdelelem(stack, 0, del);
		*modflag = 0;
		return ;
	}
	
	if (full_sorted_a(*a))
		return ;
	
	if (*stack == NULL)
	{
		while (ft_lstsize(*a) > 3)
		{
			num = *((int *)ft_lstelem(a, find_pivot_a(*a, ft_lstsize(*a)))->content);
			temp_a = *a;
			iter = ft_lstsize(*a) / 2;
			iterptr = &iter;
			ft_lstadd(&(*stack), ft_lstnew(iterptr, sizeof(int)));
			
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
		while (*stack != NULL && *(int *)(*stack)->content > 2)
		{
			i = 0;
			*modflag = 0;
			num = *((int *)ft_lstelem(a, find_pivot_a(*a, *(int *)(*stack)->content))->content);
			temp_a = *a;
			iter = *(int *)(*stack)->content / 2;
			passed = iter;
			while (temp_a && iter)
			{
				if (*((int *)temp_a->content) < num)
				{
					print_and_do_command("pb", a, b);
					iter--;
				}
				else
				{
					print_and_do_command("ra", a, b);
					++i;
				}
				temp_a = temp_a->next;
			}
			while (ft_lstsize(*stack) > 1 && i--)
				print_and_do_command("rra", a, b);

			left = *(int *)(*stack)->content - passed;
			ft_lstdelelem(stack, 0, del);
			
			if (left == 2)
			{
				if ( *(int *)(*a)->content >  *(int *)(*a)->next->content)
					print_and_do_command("sa", a, b);
			}
			if (passed == 1)
			{
				print_and_do_command("pa", a, b);
				break ;
			}
			if (passed >= 2)
			{
				iterptr = &passed;
				ft_lstadd(stack, ft_lstnew(iterptr, sizeof(int)));
			}
			if (left >= 3)
			{
				iterptr = &left;
				ft_lstadd(stack, ft_lstnew(iterptr, sizeof(int)));
				continue ;
			}
			if (left > 3)
			{
				iterptr = &left;
				ft_lstadd(stack, ft_lstnew(iterptr, sizeof(int)));
			}
		}
	}
	
}

static void algo_bigger_three(t_list **a, t_list **b)
{
	t_list	*stack;
	int modflag;
	
	modflag = 0;
	stack = NULL;
	while (/*full_sorted_a(*a) && b == NULL*/ 1)
	{
		//print_stack_s(*a, *b, stack);
		/* Checkng for full sort */
		if (b == NULL && check_full_sort(a, b))
			return ;
		
		/* Checking if both stacks are sorted */
		if (check_both_stacks_sort(a, b))
			return ;
		
		/* if one of stack less than 4, sort it */
		if (sort_stack_less_four(a, b))
			continue ;
		
		/* sort stack b */
		quick_sort_b(a, b, &stack, &modflag);

		//print_stack_s(*a, *b, stack);
		/* sort stack a */
		quick_sort_a(a, b, &stack, &modflag);
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
	//print_stack(a, b);
	//ft_printf("--------------\n");
	algorithm(&a, &b);
	//ft_printf("--------------\n");
	//print_stack(a, b);
	free_lists(&a, &b);
	return (0);
}
