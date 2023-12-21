/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:22:38 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/21 15:04:25 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps **begining_a, t_ps **begining_b)
{
	t_ps	*first_node_a;
	t_ps	*first_node_b;
	t_ps	*next_a;
	t_ps	*next_b;

	first_node_a = *begining_a;
	first_node_b = *begining_b;
	next_a = first_node_a->next;
	next_b = first_node_b->next;
	add_sub_to_index(1, begining_a);
	add_sub_to_index(-1, &next_b);
	first_node_b->next = first_node_a;
	*begining_a = first_node_b;
	*begining_b = next_b;
}
void	pb(t_ps **begining_a, t_ps **begining_b)
{
	t_ps	*first_node_a;
	t_ps	*first_node_b;
	t_ps	*next_a;
	t_ps	*next_b;

	first_node_a = *begining_a;
	first_node_b = *begining_b;
	next_a = first_node_a->next;
	next_b = first_node_b->next;
	add_sub_to_index(1, begining_b);
	add_sub_to_index(-1, &next_a);
	first_node_a->next = first_node_b;
	*begining_b = first_node_a;
	*begining_a = next_a;
}