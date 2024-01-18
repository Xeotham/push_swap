/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:44:03 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/18 18:29:15 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_ps	*make_node(char *args)
{
	t_ps	*node;

	node = malloc(sizeof(t_ps));
	if (!node)
		return (NULL);
	node->number = ft_atoi(args);
	node->next = NULL;
	return (node);
}

t_ps	*make_stack_a(char **args)
{
	int		index;
	t_ps	*first_node;
	t_ps	*node;

	index = 0;
	first_node = make_node(args[0]);
	if (!first_node)
		error_case();
	while (args[++index])
	{
		node = make_node(args[index]);
		if (!node)
		{
			stack_lstclear(&first_node);
			error_case();
		}
		stack_lstadd_back(&first_node, node);
	}
	return (first_node);
}
