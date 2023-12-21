/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:36:45 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/21 15:04:14 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps **begining)
{
	t_ps	*first_node;
	t_ps	*seconde_node;
	t_ps	*next;
	int		tmp_index;

	first_node = *begining;
	seconde_node = first_node->next;
	next = seconde_node->next;
	tmp_index = first_node->index;
	first_node->index = seconde_node->index;
	seconde_node->index = tmp_index;
	seconde_node->next = first_node;
	first_node->next = next;
	*begining = seconde_node;
}
void	sb(t_ps **begining)
{
	t_ps	*first_node;
	t_ps	*seconde_node;
	t_ps	*next;
	int		tmp_index;

	first_node = *begining;
	seconde_node = first_node->next;
	next = seconde_node->next;
	tmp_index = first_node->index;
	first_node->index = seconde_node->index;
	seconde_node->index = tmp_index;
	seconde_node->next = first_node;
	first_node->next = next;
	*begining = seconde_node;
}
void	ss(t_ps **begining_a, t_ps **begining_b)
{
	sa(begining_a);
	sb(begining_b);
}
