/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:29:37 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/20 16:08:14 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/libft.h"

typedef struct s_ps_a
{
	char			*c_number;
	int				i_number;
	int				index;
	struct s_ps_a	*prev;
	struct s_ps_a	*next;
} t_ps_a;

typedef struct s_ps_b
{
	char			*c_number;
	int				i_number;
	struct s_ps_b	*prev;
	struct s_ps_b	*next;
} t_ps_b;

void	check_args(char **args);

t_ps_a	*make_pile_a(char **args);

t_ps_a	*ft_stack_a_lstlast(t_ps_a *lst);

void	ft_stack_a_lstadd_back(t_ps_a **lst, t_ps_a *new);

void	ft_stack_a_lstclear(t_ps_a **lst);

void	ft_Stack_a_lstadd_prev(t_ps_a *node, t_ps_a *prev);

#endif