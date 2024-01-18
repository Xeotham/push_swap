/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_target_handle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:33:57 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/17 11:20:31 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_maker(t_ps *stack)
{
	int		i;
	t_ps	*node;

	i = 0;
	node = stack;
	while (node)
	{
		node->index = i++;
		node = node->next;
	}
}

void	find_target_f(t_ps **stack_search, t_ps **stack_target)
{
	t_ps	*node_a;
	t_ps	*node_b;
	t_ps	*tmp_target;
	t_ps	*biggest;

	node_a = *stack_search;
	biggest = find_biggest(*stack_target);
	while (node_a)
	{
		tmp_target = find_smallest(*stack_target);
		node_b = *stack_target;
		while (node_b)
		{
			if (node_a->number > node_b->number
				&& tmp_target->number < node_b->number)
				tmp_target = node_b;
			node_b = node_b->next;
		}
		if (tmp_target->number > node_a->number)
			node_a->target = biggest;
		else
			node_a->target = tmp_target;
		node_a = node_a->next;
	}
	check_cost(stack_search);
}

void	find_target_l(t_ps **stack_search, t_ps **stack_target)
{
	t_ps	*node_a;
	t_ps	*node_b;
	t_ps	*tmp_target;
	t_ps	*smallest;

	node_b = *stack_search;
	smallest = find_smallest(*stack_target);
	while (node_b)
	{
		tmp_target = find_biggest(*stack_target);
		node_a = *stack_target;
		while (node_a)
		{
			if (node_b->number < node_a->number
				&& tmp_target->number > node_a->number)
				tmp_target = node_a;
			node_a = node_a->next;
		}
		if (tmp_target->number < node_b->number)
			node_b->target = smallest;
		else
			node_b->target = tmp_target;
		node_b = node_b->next;
	}
	check_cost(stack_search);
}
