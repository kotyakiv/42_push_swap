/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:25:24 by ykot              #+#    #+#             */
/*   Updated: 2022/07/03 18:01:35 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"

int		read_arg(t_list **a, const char *argv);
int		full_sorted_a(t_list *a);
void	del(void *content, size_t size);
int		ft_swap(t_list **a);
int		ft_push(t_list **a, t_list **b);
int		ft_rotate(t_list **a);
int		ft_revrotate(t_list **a);
void	dispatcher(const char *str, t_list **a, t_list **b, t_list **stack);
void	free_lists(t_list **a, t_list **b, t_list **stack);
void	error_mes(t_list **a, t_list **b, t_list **stack);

#endif
