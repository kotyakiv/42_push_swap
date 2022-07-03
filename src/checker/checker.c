/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:51:25 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 18:00:32 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/** 
 * Read lines one by one, and check if the input is correct
**/

static void	read_instructions(t_list **a, t_list **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		dispatcher(line, a, b, NULL);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

static void	print_result(t_list *a, t_list *b)
{
	if (full_sorted_a(a) && b == NULL)
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		num_arg;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	num_arg = 0;
	while (++num_arg < argc)
		if (read_arg(&a, argv[num_arg]))
			error_mes(&a, &b, NULL);
	read_instructions(&a, &b);
	print_result(a, b);
	free_lists(&a, &b, NULL);
	return (0);
}
