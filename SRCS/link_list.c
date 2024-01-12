/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:44:03 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/09 18:14:39 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*make_node(char *args, int index)
{
	t_ps	*node;

	node = malloc(sizeof(t_ps));
	if (!node)
		return (NULL);
	node->number = ft_atoi(args);
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

	index = 0;
	first_node = make_node(args[0], 0);
	prev_node = first_node;
	while(args[++index])
	{
		node = make_node(args[index], index);
		stack_lstadd_back(&first_node, node);
		prev_node = node;
	}
	index_maker(first_node);
	free_2d_array(args);
	return (first_node);
}
