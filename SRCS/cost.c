/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:22:30 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/12 15:16:10 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_worthest(t_ps **stack_search)
{
	t_ps	*node;
	t_ps	*worthest;
	int		tmp_cost_1;
	int		tmp_cost_2;

	node = *stack_search;
	if (!node)
		return ;
	worthest = node;
	worthest->is_cheapest = 1;
	tmp_cost_1 = worthest->true_cost;
	while (node)
	{
		tmp_cost_2 = node->true_cost;
		if (tmp_cost_2 < tmp_cost_1)
		{
			worthest->is_cheapest = 0;
			node->is_cheapest = 1;
			worthest = node;
		}
		node = node->next;
	}
}

void	change_move(t_ps *node_a)
{
	t_ps	*target;

	target = node_a->target;
	if (target->reverse)
			target->move_number = node_a->true_cost - (target->to_median + target->median);
	else
			target->move_number = node_a->true_cost - (target->to_median - target->median);
}

void	check_sim_move(t_ps *node_a, t_ps *node_b)
{
	if (node_a->index == 0 || node_b->index == 0)
		node_a->sim_move = 0;
	else if (node_b->index < node_b->median && node_a->index < node_b->median &&
			node_a->move_number < node_b->move_number)
		{
			change_move(node_a);
			node_a->sim_move = 1;
		}
	else if (node_a->index < node_a->median && node_b->index < node_a->median &&
		node_a->move_number > node_b->move_number)
	{
		change_move(node_a);
		node_a->sim_move = 1;
	}
	else if ((node_a->to_median > 0 && node_b->to_median > 0) ||
		(node_b->to_median < 0 && node_b->to_median < 0))
	{
		change_move(node_a);
		node_a->sim_move = 1;
	}
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
		if (node_a->move_number >= node_b->move_number)
			node_a->true_cost = node_a->move_number;
		else
			node_a->true_cost = node_b->move_number;
		node_a = node_a->next;
	}
	check_worthest(stack_search);
}
