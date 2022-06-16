/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:51:25 by ykot              #+#    #+#             */
/*   Updated: 2022/06/16 15:14:28 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		dispatcher(line, &a, &b);
		ft_strdel(&line);
	}
	print_stack(a, b);
	ft_printf("StackBIsNFullSorted\t%d\n", full_sorted_b(b));
	print_result(a, b);
	free_lists(&a, &b);
	return (0);
}
