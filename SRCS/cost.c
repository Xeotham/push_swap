/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:22:30 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/18 11:12:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sim_move(t_ps *node_a, t_ps *node_b)
{
	if (node_a->index == 0 || node_b->index == 0)
		node_a->sim_move = 0;
	else if (node_a->reverse == node_b->reverse)
		node_a->sim_move = 1;
	else
		node_a->sim_move = 0;
}

void	check_cost(t_ps **stack_search)
{
	t_ps	*node_a;
	t_ps	*node_b;

	node_a = *stack_search;
	while (node_a)
	{
		node_b = node_a->target;
		check_sim_move(node_a, node_b);
		if (node_a->reverse != node_b->reverse)
			node_a->true_cost = node_a->move_number + node_b->move_number;
		else if (node_a->move_number >= node_b->move_number)
			node_a->true_cost = node_a->move_number;
		else
			node_a->true_cost = node_b->move_number;
		node_a = node_a->next;
	}
}
