/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:54:50 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/20 16:09:21 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_a	*ft_stack_a_lstlast(t_ps_a *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_stack_a_lstadd_back(t_ps_a **lst, t_ps_a *new)
{
	t_ps_a	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = ft_stack_a_lstlast(*lst);
		tmp->next = new;
	}
}

void	ft_stack_a_lstclear(t_ps_a **lst)
{
	t_ps_a	*tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_Stack_a_lstadd_prev(t_ps_a *node, t_ps_a *prev)
{
	if (!prev || !node)
		return ;
	node->prev = prev;
}
