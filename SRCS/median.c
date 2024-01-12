/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:03:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/12 16:43:21 by mhaouas          ###   ########.fr       */
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
		else if (node->to_median < 0 && ft_is_even(node->median))
		{
			node->reverse = 1;
			node->move_number = node->median + node->to_median + 1;
		}
		else if (node->to_median < 0 && !ft_is_even(node->median))
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

	i = 0;
	node = *stack;
	median = stack_lstcount(node);
	if (ft_is_even(median))
		median /= 2;
	else
		median = (median / 2) + 1; 
	while (node)
	{
		node->median = median;
		node->to_median = median - i++;
		node = node->next;
	}
	node = *stack;
	move_number(node);
}
