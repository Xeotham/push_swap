/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:36:45 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/18 18:27:49 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_ps	*swap(t_ps **to_swap)
{
	t_ps	*first_node;
	t_ps	*seconde_node;
	t_ps	*next;

	first_node = *to_swap;
	seconde_node = first_node->next;
	next = seconde_node->next;
	seconde_node->next = first_node;
	first_node->next = next;
	*to_swap = seconde_node;
	return (seconde_node);
}

void	sa(t_ps **stack_a, t_ps **stack_b)
{
	(void) stack_b;
	*stack_a = swap(stack_a);
}

void	sb(t_ps **stack_a, t_ps **stack_b)
{
	(void) stack_a;
	swap(stack_b);
}

void	ss(t_ps **stack_a, t_ps **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
