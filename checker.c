/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:51:25 by ykot              #+#    #+#             */
/*   Updated: 2022/06/16 17:45:50 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_line(char *str)
{
	return (ft_strequ(str, "sa") || ft_strequ(str, "sb") || ft_strequ(str, "ss")
		|| ft_strequ(str, "pa") || ft_strequ(str, "pb") || ft_strequ(str, "ra")
		|| ft_strequ(str, "rb") || ft_strequ(str, "rr") || ft_strequ(str, "rra")
		|| ft_strequ(str, "rrb") || ft_strequ(str, "rrr"));
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
	while (get_next_line(0, &line))
	{
		if (!check_line(line))
		{
			ft_putendl("Error");
			free_lists(&a, &b);
			return (0);
		}
		dispatcher(line, &a, &b);
		ft_strdel(&line);
	}
	print_stack(a, b);
	ft_printf("StackBIsNFullSorted\t%d\n", full_sorted_b(b));
	print_result(a, b);
	free_lists(&a, &b);
	return (0);
}
