/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:29:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/19 13:14:39 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_ps *stack_a)
{
	t_ps	*stack_b;

	stack_b = NULL;
	if (stack_lstcount(stack_a) <= 3)
		little_sort(&stack_a);
	else
	{
		pb(&stack_a, &stack_b);
		if (stack_lstcount(stack_a) != 3)
		{
			pb(&stack_a, &stack_b);
			first_sort(&stack_a, &stack_b);
		}
		if (!check_sort(stack_a))
			little_sort(&stack_a);
		second_sort(&stack_b, &stack_a);
		last_sort(&stack_a);
	}
	stack_lstclear(&stack_a);
}
