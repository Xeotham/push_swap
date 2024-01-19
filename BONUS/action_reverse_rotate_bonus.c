/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reverse_rotate_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:26:32 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/19 13:05:23 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_ps **to_rotate)
{
	t_ps	*first_node;
	t_ps	*last_node;
	t_ps	*before_last;

	first_node = *to_rotate;
	before_last = stack_lst_before_last(first_node);
	last_node = stack_lstlast(first_node);
	last_node->next = first_node;
	before_last->next = NULL;
	*to_rotate = last_node;
}

void	rra(t_ps **stack_a, t_ps **stack_b)
{
	(void) stack_b;
	reverse_rotate(stack_a);
}

void	rrb(t_ps **stack_a, t_ps **stack_b)
{
	(void) stack_a;
	reverse_rotate(stack_b);
}

void	rrr(t_ps **stack_a, t_ps **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
