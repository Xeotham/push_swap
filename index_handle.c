/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:33:57 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/21 14:44:29 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	add_sub_to_index(int to_add, t_ps **stack)
{
	t_ps	*node;

	node = *stack;
	while (node)
	{
		node->index += to_add;
		node = node->next;
	}
}
