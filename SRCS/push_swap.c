/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:29:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/12 13:37:56 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_swap(t_ps *stack_a)
{
	t_ps	*stack_b;

	stack_b = NULL;
	if (stack_lstcount(stack_a) < 3)
		little_sort(&stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	first_sort(&stack_a, &stack_b);
	if (!check_sort(stack_a))
		little_sort(&stack_a);
	last_sort(&stack_b, &stack_a);
	printf("--- stack a ---\n");
	while (stack_a)
	{
		printf("%d\n", stack_a->number);
		stack_a = stack_a->next;
	}
	printf("--- stack b ---\n");
	while (stack_b)
	{
		printf("%d\n", stack_b->number);
		stack_b = stack_b->next;
	}
}
