/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:27:21 by ykot              #+#    #+#             */
/*   Updated: 2022/06/30 17:24:47 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	size_t	i;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (error_mes(&a, &b));
	i = 1;
	while ((int)i < argc)
	{
		if (read_arg(&a, argv[i]))
			return (error_mes(&a, &b));
		++i;
	}
	algorithm(&a, &b);
	free_lists(&a, &b);
	return (0);
}
