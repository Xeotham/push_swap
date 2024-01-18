/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:45:46 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/17 15:39:26 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	move(t_ps **stack_a, t_ps **stack_b, int to_comp, void move(t_ps **,
			t_ps **))
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
	if (cheapest->sim_move)
	{
		if (cheapest->move_number >= target->move_number)
			cheapest->sim_move_cost = target->move_number;
		else
			cheapest->sim_move_cost = cheapest->move_number;
		cheapest->move_number = cheapest->move_number - cheapest->sim_move_cost;
		target->move_number = target->move_number - cheapest->sim_move_cost;
	}
	if (cheapest->sim_move && cheapest->reverse)
		move(stack_a, stack_b, cheapest->sim_move_cost, rrr);
	else if (cheapest->sim_move && !cheapest->reverse)
		move(stack_a, stack_b, cheapest->sim_move_cost, rr);
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
	if (cheapest->sim_move)
	{
		if (cheapest->move_number >= target->move_number)
			cheapest->sim_move_cost = target->move_number;
		else
			cheapest->sim_move_cost = cheapest->move_number;
		cheapest->move_number = cheapest->move_number - cheapest->sim_move_cost;
		target->move_number = target->move_number - cheapest->sim_move_cost;
	}
	if (cheapest->sim_move && cheapest->reverse)
		move(stack_a, stack_b, cheapest->sim_move_cost, rrr);
	else if (cheapest->sim_move && !cheapest->reverse)
		move(stack_a, stack_b, cheapest->sim_move_cost, rr);
	if (cheapest->reverse)
		move(stack_a, stack_b, cheapest->move_number, rrb);
	else
		move(stack_a, stack_b, cheapest->move_number, rb);
	if (target->reverse)
		move(stack_a, stack_b, target->move_number, rra);
	else
		move(stack_a, stack_b, target->move_number, ra);
}
