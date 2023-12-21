/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:54:50 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/21 15:03:52 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ft_stack_a_lstlast(t_ps *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_stack_a_lstadd_back(t_ps **lst, t_ps *new)
{
	t_ps	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = ft_stack_a_lstlast(*lst);
		tmp->next = new;
	}
}

void	ft_stack_a_lstclear(t_ps **lst)
{
	t_ps	*tmp;

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
