/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:44:03 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/21 15:03:25 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*make_node(char *args, int index)
{
	t_ps	*node;

	node = malloc(sizeof(t_ps));
	if (!node)
		return (NULL);
	node->c_number = args;
	node->i_number = ft_atoi(args);
	node->index = index;
	node->next = NULL;
	return (node);
}

t_ps	*make_pile_a(char **args)
{
	int		index;
	t_ps	*first_node;
	t_ps	*prev_node;
	t_ps	*node;

	index = 1;
	first_node = make_node(args[0], 0);
	prev_node = first_node;
	while(args[++index])
	{
		node = make_node(args[index], index);
		ft_stack_a_lstadd_back(&first_node, node);
		prev_node = node;
	}
	return (first_node);
}
