/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:27:21 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 17:50:20 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	i = 0;
	while (++i < argc)
		if (read_arg(&a, argv[i]))
			error_mes(&a, &b, NULL);
	algorithm(&a, &b);
	free_lists(&a, &b, NULL);
	return (0);
}
