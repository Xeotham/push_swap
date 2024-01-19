/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:16:29 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/19 16:23:15 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_sort(t_ps	**stack_a)
{
	t_ps	*node;

	find_median(stack_a);
	node = find_smallest(*stack_a);
	if (node->reverse)
		move(stack_a, stack_a, node->move_number, rra);
	else
		move(stack_a, stack_a, node->move_number, ra);
}

void	second_sort(t_ps **stack_b, t_ps **stack_a)
{
	t_ps	*node_a;
	t_ps	*node_b;

	node_b = *stack_b;
	node_a = *stack_a;
	while (node_b)
	{
		find_median(&node_a);
		find_median(&node_b);
		find_target_l(&node_b, &node_a);
		make_best_move_l(&node_b, &node_a);
	}
	*stack_b = node_b;
	*stack_a = node_a;
}

void	first_sort(t_ps **stack_a, t_ps **stack_b)
{
	t_ps	*node_a;
	t_ps	*node_b;
	int		size_stack_a;

	node_a = *stack_a;
	node_b = *stack_b;
	size_stack_a = stack_lstcount(*stack_a);
	while (size_stack_a > 3)
	{
		find_median(&node_a);
		find_median(&node_b);
		find_target_f(&node_a, &node_b);
		make_best_move_f(&node_a, &node_b);
		size_stack_a--;
	}
	*stack_a = node_a;
	*stack_b = node_b;
}

void	little_sort(t_ps **stack_a)
{
	t_ps	*first_node;
	t_ps	*second_node;
	t_ps	*third_node;
	t_ps	*biggest_node;

	first_node = *stack_a;
	second_node = first_node->next;
	third_node = second_node->next;
	biggest_node = find_biggest(*stack_a);
	if (stack_lstcount(*stack_a) == 2)
		sa(stack_a, &first_node);
	else
	{
		if (first_node == biggest_node)
			ra(stack_a, &first_node);
		else if (second_node == biggest_node)
			rra(stack_a, &second_node);
		if (!check_sort(*stack_a))
			sa(stack_a, &first_node);
	}
}
