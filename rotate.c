/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:35:41 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/21 15:41:53 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps **stack_a)
{
	t_ps	*first_node;
	t_ps	*last_node;

	first_node = *stack_a;
	last_node = ft_stack_a_lstlast(first_node);
	last_node->next = first_node;
	add_sub_to_index(-1, stack_a);
	first_node->index = last_node->index + 1;
	first_node->next = NULL;
	*stack_a = *stack_a->next;
}