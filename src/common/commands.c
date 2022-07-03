/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:00:03 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 17:17:10 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	del(void *content, size_t size)
{
	ft_memdel(&content);
	size++;
}

int	ft_swap(t_list **a)
{
	t_list	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	temp = ft_lstnew((*a)->next->content, sizeof(int));
	if (!temp)
		return (1);
	ft_lstdelelem(a, 1, del);
	ft_lstadd(a, temp);
	return (0);
}

int	ft_push(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*b == NULL)
		return (0);
	temp = ft_lstnew((*b)->content, (*b)->content_size);
	if (!temp)
		return (1);
	ft_lstdelelem(b, 0, del);
	ft_lstadd(a, temp);
	return (0);
}

int	ft_rotate(t_list **a)
{
	t_list	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	temp = ft_lstnew((*a)->content, (*a)->content_size);
	if (!temp)
		return (1);
	ft_lstdelelem(a, 0, del);
	ft_lstappend(a, temp);
	return (0);
}

int	ft_revrotate(t_list **a)
{
	t_list	*temp;
	t_list	*prev;
	t_list	*new;

	temp = *a;
	if (temp == NULL || temp->next == NULL)
		return (0);
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	new = ft_lstnew(temp->content, temp->content_size);
	if (!new)
		return (1);
	ft_lstdel(&temp, del);
	prev->next = NULL;
	ft_lstadd(a, new);
	return (0);
}
