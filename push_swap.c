/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:27:21 by ykot              #+#    #+#             */
/*   Updated: 2022/06/14 17:38:55 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("IsNotFullSorted\t%d\n", is_nfsort(a));
	ft_printf("Pivot\t%d\n", find_pivot(a));
	ft_printf("Size\t%d\n", ft_lstsize(a));
	print_stack(a, b);
	ft_printf("--------------\n");
	if (sorted(a))
		ft_printf("OK\n");
	else if (is_nfsort(a))
		sort_isnfullsort_list(&a);
	if (ft_lstsize(a) < 4)
		sort_three(&a);
	print_stack(a, b);
	free_lists(&a, &b);
	return (0);
}
