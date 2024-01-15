/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:16:29 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/15 12:56:24 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	make_best_move_f(t_ps **stack_a, t_ps **stack_b)
{
	t_ps	*cheapest;
	t_ps	*target;

	cheapest = find_cheapest(*stack_a);
	if (!cheapest)
		return ;
	target = cheapest->target;
	do_move_f(stack_a, stack_b, cheapest, target);
	pb(stack_a, stack_b);
}

void	make_best_move_l(t_ps **stack_b, t_ps **stack_a)
{
	t_ps	*cheapest;
	t_ps	*target;

	cheapest = find_cheapest(*stack_b);
	if (!cheapest)
		return ;
	target = cheapest->target;
	do_move_l(stack_a, stack_b, cheapest, target);
	pa(stack_a, stack_b);
}

void	last_sort(t_ps **stack_b, t_ps **stack_a)
{
	t_ps	*node_a;
	t_ps	*node_b;
	t_ps	*test1;
	t_ps	*test2;

	node_b = *stack_b;
	node_a = *stack_a;
			test1 = node_a;
		test2 = node_b;
			printf("--- stack a ---\n");
		while (test1)
		{
			printf("%d\n", test1->number);
			test1 = test1->next;
		}
		printf("--- stack b ---\n");
		while (test2)
		{
			printf("%d\n", test2->number);
			test2 = test2->next;
		}
	while (node_b)
	{
		find_median(&node_a);
		find_median(&node_b);
		find_target_l(&node_b, &node_a);
		make_best_move_l(&node_b, &node_a);
		test1 = node_a;
		test2 = node_b;
		printf("--- stack a ---\n");
		while (test1)
		{
			printf("%d\n", test1->number);
			test1 = test1->next;
		}
		printf("--- stack b ---\n");
		while (test2)
		{
			printf("%d\n", test2->number);
			test2 = test2->next;
		}
	}
	*stack_b = node_b;
	*stack_a = node_a;
}

void	first_sort(t_ps **stack_a, t_ps **stack_b)
{
	t_ps	*node_a;
	t_ps	*node_b;
		t_ps	*test1;
	t_ps	*test2;
	int	size_stack_a;

	node_a = *stack_a;
	node_b = *stack_b;
	size_stack_a = stack_lstcount(*stack_a);
	while (size_stack_a > 3)
	{
		find_median(&node_a);
		find_median(&node_b);
		find_target_f(&node_a, &node_b);
		make_best_move_f(&node_a, &node_b);
		test1 = node_a;
		test2 = node_b;
		printf("--- stack a ---\n");
		while (test1)
		{
			printf("%d\n", test1->number);
			test1 = test1->next;
		}
		printf("--- stack b ---\n");
		while (test2)
		{
			printf("%d\n", test2->number);
			test2 = test2->next;
		}
		printf("\n\n");
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

	first_node = *stack_a;
	second_node = first_node->next;
	if (!second_node)
		return ;
	third_node = second_node->next;
	while (!check_sort(first_node))
	{
		if (first_node->number > second_node->number)
			sa(&first_node, &second_node);
		else if (first_node->number > third_node->number)
			rra(&first_node, &third_node);
		else if (first_node->number < third_node->number)
			ra(&first_node, &third_node);
	}
	*stack_a = first_node;
}
