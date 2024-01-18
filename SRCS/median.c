/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:03:00 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/15 16:58:27 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_median(t_ps **stack)
{
	t_ps	*node;
	int		lst_size;
	int		median;

	node = *stack;
	lst_size = stack_lstcount(node);
	median = lst_size / 2;
	while (node)
	{
		node->stack = stack;
		node->median = median;
		if (node->index <= median)
		{
			node->reverse = 0;
			node->move_number = node->index;
		}
		else if (node->index > median)
		{
			node->reverse = 1;
			node->move_number = lst_size - node->index;
		}
		node = node->next;
	}
}
