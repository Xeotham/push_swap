/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:35:41 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/11 20:55:55 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	index_maker(*to_rotate);
}

void	ra(t_ps **stack_a, t_ps **stack_b)
{
	(void)stack_b;
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_ps **stack_a, t_ps **stack_b)
{
	(void) stack_a;
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_ps **stack_a, t_ps **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
