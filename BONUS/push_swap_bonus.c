/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:29:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/19 16:20:08 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_swap(t_ps *stack_a)
{
	t_ps	*stack_b;

	stack_b = NULL;
	make_move(&stack_a, &stack_b);
	if (stack_b || !check_sort(stack_a))
		fail_case(&stack_a, &stack_b);
	else
		success_case(&stack_a, &stack_b);
}
