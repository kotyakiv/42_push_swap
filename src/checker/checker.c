/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:51:25 by ykot              #+#    #+#             */
/*   Updated: 2022/06/30 17:19:11 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/** 
 * If there is no matches, means that command is incorrect
**/

static int	check_line(char *str)
{
	return (ft_strequ(str, "sa") || ft_strequ(str, "sb") || ft_strequ(str, "ss")
		|| ft_strequ(str, "pa") || ft_strequ(str, "pb") || ft_strequ(str, "ra")
		|| ft_strequ(str, "rb") || ft_strequ(str, "rr") || ft_strequ(str, "rra")
		|| ft_strequ(str, "rrb") || ft_strequ(str, "rrr"));
}

/** 
 * Read lines one by one, and check if the input is correct
**/

static int	read_instructions(t_list **a, t_list **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!check_line(line))
		{
			ft_strdel(&line);
			return (error_mes(a, b));
		}
		dispatcher(line, a, b);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		num_arg;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (error_mes(&a, &b));
	num_arg = 0;
	while (++num_arg < argc)
		if (read_arg(&a, argv[num_arg]))
			return (error_mes(&a, &b));
	if (read_instructions(&a, &b))
		return (-1);
	print_result(a, b);
	free_lists(&a, &b);
	return (0);
}
