/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:48:19 by ykot              #+#    #+#             */
/*   Updated: 2022/03/20 15:49:39 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_int(const char *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	if (len > 11 || (str[0] != '-' && len > 10))
		return (1);
	else if (len == 11 && str[0] == '-')
	{
		str++;
		if (ft_strcmp(str, "2147483648") > 0)
			return (1);
	}
	else if (len == 10 && ft_strcmp(str, "2147483647") > 0)
		return (1);
	i = 0;
	if (str[0] == '-')
		i = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		++i;
	}
	return (0);
}

static int	check_dup(t_list *a, int num)
{
	t_list *temp;

	temp = a;
	while (temp)
	{
		if (*(int *)(temp->content) == num)
			return (1);
		temp = temp->next; 
	}
	return (0);
}

static void	free_split(char ***str)
{
	size_t	i;

	i = 0;
	while ((*str)[i])
	{
		ft_strdel(&((*str)[i]));
		++i;
	}
	ft_strdel(&((*str)[i]));
	free(*str);
	*str = NULL;
}

static int	ret_freesplit(char ***str)
{
	free_split(&(*str));
	return (1);
}

int	read_arg(t_list **a, const char *argv)
{
	char	**str;
	int		num;
	int		*numptr;
	t_list	*temp;
	size_t	i;

	numptr = &num;
	i = 0;
	str = ft_strsplit(argv, ' ');
	if (!str)
		return (1);
	while (str[i])
	{
		if (check_int(str[i]))
			return (ret_freesplit(&str));
		num = ft_atoi(str[i]);
		if (check_dup(*a, num))
			return (ret_freesplit(&str));
		temp = ft_lstnew(numptr, sizeof(int));
		ft_lstappend(&(*a), temp);
		++i;
	}
	free_split(&str);
	return (0);
}
