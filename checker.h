/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:25:24 by ykot              #+#    #+#             */
/*   Updated: 2022/06/16 15:14:53 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"

int		read_arg(t_list **a, const char *argv);
int		full_sorted_a(t_list *a);
void	del(void *content, size_t size);
void	ft_swap(t_list **a);
void	ft_push(t_list **a, t_list **b);
void	ft_rotate(t_list **a);
void	ft_revrotate(t_list **a);
void	dispatcher(const char *str, t_list **a, t_list **b);
void	print_result(t_list *a, t_list *b);
void	print_list(t_list *a);
void	free_lists(t_list **a, t_list **b);
void	print_stack(t_list *a, t_list *b);
int		sorted_b(t_list *b);
int		sorted_a(t_list *a);
int		full_sorted_b(t_list *b);

#endif
