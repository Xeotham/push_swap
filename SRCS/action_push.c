/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:22:38 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/11 20:54:55 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_ps **push_to, t_ps **push_from)
{
	t_ps	*first_node_a;
	t_ps	*first_node_b;
	t_ps	*next_b;

	if (!push_from || !*push_from)
		return ;
	first_node_a = *push_to;
	first_node_b = *push_from;
	next_b = first_node_b->next;
	first_node_b->next = first_node_a;
	*push_to = first_node_b;
	*push_from = next_b;
	index_maker(*push_to);
	index_maker(*push_from);
}

void	pa(t_ps **begining_a, t_ps **begining_b)
{
	push(begining_a, begining_b);
	write(1, "pa\n", 3);
}

void	pb(t_ps **begining_a, t_ps **begining_b)
{
	push(begining_b, begining_a);
	write(1, "pb\n", 3);
}
