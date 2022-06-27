/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:27:21 by ykot              #+#    #+#             */
/*   Updated: 2022/06/27 14:04:47 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	size_t	i;

	a = NULL;
	b = NULL;
	if (argc == 1)
	{
		ft_putendl("No arguments!");
		return (0);
	}
	i = 1;
	while ((int)i < argc)
	{
		if (read_arg(&a, argv[i]))
		{
			ft_putendl("Error");
			free_lists(&a, &b);
			return (0);
		}
		++i;
	}
	algorithm(&a, &b);
	//print_stack(a, b);
	free_lists(&a, &b);
	return (0);
}
