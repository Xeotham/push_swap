/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:45:46 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/12 15:17:15 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_ps	**stack_a, t_ps **stack_b, int to_comp,
	void move(t_ps **, t_ps **))
{
	int	i;

	i = 0;
	while (i < to_comp)
	{
		move(stack_a, stack_b);
		i++;
	}
}

void	do_move_f(t_ps **stack_a, t_ps **stack_b, t_ps *cheapest, t_ps *target)
{
	if (cheapest->true_cost == 0)
		return ;
	if (target->sim_move)
	{
		cheapest->move_number = cheapest->true_cost - cheapest->move_number;
		target->move_number = cheapest->true_cost - target->move_number;
	}
	if (cheapest->sim_move && ((cheapest->reverse && cheapest->move_number) ||
		(target->reverse && target->move_number)))
		move(stack_a, stack_b, cheapest->move_number, rrr);
	else if (cheapest->sim_move && ((!cheapest->reverse && cheapest->move_number) ||
		(target->reverse && target->move_number)))
		move(stack_a, stack_b, cheapest->move_number, rr);
	if (cheapest->reverse)
		move(stack_a, stack_b, cheapest->move_number, rra);
	else
		move(stack_a, stack_b, cheapest->move_number, ra);
	if (target->reverse)
		move(stack_a, stack_b, target->move_number, rrb);
	else
		move(stack_a, stack_b, target->move_number, rb);
}

void	do_move_l(t_ps **stack_a, t_ps **stack_b, t_ps *cheapest, t_ps *target)
{
	if (cheapest->true_cost == 0)
		return ;
	if (target->sim_move)
	{
		target->reverse = cheapest->reverse;
		target->move_number = cheapest->true_cost - target->move_number;
		cheapest->move_number = cheapest->true_cost - cheapest->move_number;
	}
	if (cheapest->sim_move && ((cheapest->reverse && cheapest->move_number) ||
		(target->reverse && target->move_number)))
		move(stack_a, stack_b, cheapest->move_number, rrr);
	else if (cheapest->sim_move && ((!cheapest->reverse && cheapest->move_number) ||
		(target->reverse && target->move_number)))
		move(stack_a, stack_b, cheapest->move_number, rr);
	if (cheapest->reverse)
		move(stack_a, stack_b, cheapest->move_number, rrb);
	else
		move(stack_a, stack_b, cheapest->move_number, rb);
	if (target->reverse)
		move(stack_a, stack_b, target->move_number, rra);
	else
		move(stack_a, stack_b, target->move_number, ra);
}
