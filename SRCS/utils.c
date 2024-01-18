/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:41:17 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/18 11:15:32 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*find_cheapest(t_ps *to_search)
{
	t_ps	*node;
	t_ps	*worthest;

	node = to_search;
	if (!node)
		return (NULL);
	worthest = node;
	while (node)
	{
		if (node->true_cost < worthest->true_cost)
			worthest = node;
		node = node->next;
	}
	return (worthest);
}

t_ps	*find_biggest(t_ps *stack)
{
	t_ps	*tmp_biggest;

	tmp_biggest = stack;
	while (stack)
	{
		if (tmp_biggest->number < stack->number)
			tmp_biggest = stack;
		stack = stack->next;
	}
	return (tmp_biggest);
}

t_ps	*find_smallest(t_ps *stack)
{
	t_ps	*tmp_smallest;

	tmp_smallest = stack;
	while (stack)
	{
		if (tmp_smallest->number > stack->number)
			tmp_smallest = stack;
		stack = stack->next;
	}
	return (tmp_smallest);
}
