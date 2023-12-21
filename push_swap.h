/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:29:37 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/21 15:18:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/libft.h"

typedef struct s_ps
{
	int				number;
	int				index;
	struct s_ps_a	*next;
} t_ps;


void	check_args(char **args);

t_ps	*make_pile_a(char **args);

t_ps	*ft_stack_a_lstlast(t_ps *lst);

void	ft_stack_a_lstadd_back(t_ps **lst, t_ps *new);

void	ft_stack_a_lstclear(t_ps **lst);

void	ft_Stack_a_lstadd_prev(t_ps *node, t_ps *prev);

void	check_same_args(char **args);

void	add_sub_to_index(int to_add, t_ps **stack);

#endif