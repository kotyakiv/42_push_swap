/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:00:03 by ykot              #+#    #+#             */
/*   Updated: 2022/03/21 21:04:03 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	del(void *content, size_t size)
{
	ft_memdel(&content);
	size++;
}

void	ft_swap(t_list **a)
{
	t_list	*temp;
	
	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = ft_lstnew((*a)->next->content, sizeof(int));
	ft_lstdelelem(a, 1, del);
	ft_lstadd(a, temp);
}

void	ft_push(t_list **a, t_list **b)
{
	t_list	*temp;
	
	if (*b == NULL)
		return ;
	temp = ft_lstnew((*b)->content, (*b)->content_size);
	ft_lstdelelem(b, 0, del);
	ft_lstadd(a, temp);
}

void	ft_rotate(t_list **a)
{
	t_list	*temp;
	
	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = ft_lstnew((*a)->content, (*a)->content_size);
	ft_lstdelelem(a, 0, del);
	ft_lstappend(a, temp);
}

void	ft_revrotate(t_list **a)
{
	t_list	*temp;
	t_list	*prev;
	t_list	*new;
	
	temp = *a;	
	if (temp == NULL || temp->next == NULL)
		return ;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	new = ft_lstnew(temp->content, temp->content_size);
	ft_lstdel(&temp, del);
	prev->next = NULL;
	ft_lstadd(a, new);
}