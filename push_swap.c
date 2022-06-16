/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:27:21 by ykot              #+#    #+#             */
/*   Updated: 2022/06/16 17:31:20 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_and_do_command( char *str, t_list **a, t_list **b)
{
	dispatcher(str, a, b);
	ft_putendl(str);
}

static void algo_bigger_three(t_list **a, t_list **b)
{
	int	size;
	int num;
	t_list *temp;

	while (/*full_sorted_a(*a) && b == NULL*/ 1)
	{
		if (sorted_a(*a) && b == NULL)
			final_list_sort_a(a);
			
		else if ( (sorted_a(*a) || full_sorted_a(*a)) && (sorted_a(*b) || full_sorted_a(*b)) )
		{
			final_list_sort_a(a);
			final_list_sort_b(b);
			while (*b != NULL)
				print_and_do_command("pa", a, b);
			return ;
		}
		if (ft_lstsize(*a) < 4)
			sort_three_a(a);
		if (*b != NULL && ft_lstsize(*b) < 4 )
			sort_three_a(b);
			
		else if (!sorted_a(*a) && ft_lstsize(*a) > 3)
		{
			num = *((int *)ft_lstelem(a, find_pivot(*a))->content);
			temp = *a;
			size = ft_lstsize(*a);
			while (size--)
			{
				if (*((int *)temp->content) < num)
					print_and_do_command("pb", a, b);
				else
					print_and_do_command("ra", a, b);
				temp = temp->next;
			}
		}
		
	}
}

static void	algorithm(t_list **a, t_list **b)
{
	if (full_sorted_a(*a))
			return ;
	if (sorted_a(*a))
	{
		final_list_sort_a(a);
		return ;
	}
	if (ft_lstsize(*a) <= 3)
	{
		sort_three_a(a);
		return ;
	}
	algo_bigger_three(a, b);
}

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	size_t	c;
	char	*line;

	a = NULL;
	b = NULL;
	line = NULL;
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
