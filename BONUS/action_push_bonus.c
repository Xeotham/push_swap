/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:22:38 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/19 13:05:15 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	pa(t_ps **begining_a, t_ps **begining_b)
{
	push(begining_a, begining_b);
}

void	pb(t_ps **begining_a, t_ps **begining_b)
{
	push(begining_b, begining_a);
}
