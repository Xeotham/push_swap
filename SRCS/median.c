/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:03:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/15 13:14:21 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_number(t_ps *node)
{
	while (node)
	{
		if (node->to_median >= 0)
		{
			node->reverse = 0;
			node->move_number = node->median - node->to_median;
		}
		else if (node->to_median < 0)
		{
			node->reverse = 1;
			node->move_number = node->median + node->to_median;
		}
		node = node->next;
	}
}

void	find_median(t_ps **stack)
{
	int		i;
	t_ps	*node;
	int		median;

	node = *stack;
	median = stack_lstcount(node);
	if (median == 5)
		i = 1;
	else
		i = 0;
	median = (median / 2) + i; 
	while (node)
	{
		node->median = median;
		node->to_median = median - i++;
		node = node->next;
	}
	node = *stack;
	move_number(node);
}
