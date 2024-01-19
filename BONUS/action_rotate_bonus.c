/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:35:41 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/19 13:05:32 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_ps **to_rotate)
{
	t_ps	*first_node;
	t_ps	*last_node;
	t_ps	*next;

	first_node = *to_rotate;
	next = first_node->next;
	last_node = stack_lstlast(first_node);
	last_node->next = first_node;
	first_node->next = NULL;
	*to_rotate = next;
}

void	ra(t_ps **stack_a, t_ps **stack_b)
{
	(void)stack_b;
	rotate(stack_a);
}

void	rb(t_ps **stack_a, t_ps **stack_b)
{
	(void) stack_a;
	rotate(stack_b);
}

void	rr(t_ps **stack_a, t_ps **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
