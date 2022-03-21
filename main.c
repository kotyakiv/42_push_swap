/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:51:25 by ykot              #+#    #+#             */
/*   Updated: 2022/03/21 20:43:20 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	free_lists(t_list **a, t_list **b)
{
	ft_lstdel(&(*a), del);
	ft_lstdel(&(*b), del);
}

static void print_stack(t_list *a, t_list *b)
{
	t_list	*t_a;
	t_list	*t_b;
	size_t	i;
	size_t	j;
		
	t_a = a;
	t_b = b;
	i = 0;
	j = ft_bigger((long long)ft_lstsize(a), (long long)ft_lstsize(b));
	ft_printf("stack A\tstack B\n");
	while (i < j)
	{
		if (t_a)
		{
			ft_printf("%5d\t", *(int *)(t_a->content));
			t_a = t_a->next;
		}
		else
			ft_printf("%5c\t", ' ');
		if (t_b)
		{
			ft_printf("%5d", *(int *)(t_b->content));
			t_b = t_b->next;
		}
		else
			ft_printf("%5c\t", ' ');
		ft_putendl("");
		++i;
	}
}

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	size_t	c;
	char	*line;
	int		fd;
	
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
	while (get_next_line(0, &line))
	{
		dispatcher(line, &a, &b);
		ft_strdel(&line);
	}
	print_stack(a, b);
	print_result(a, b);
	free_lists(&a, &b);
	return (0);
}
