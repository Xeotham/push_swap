/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:54:50 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/15 10:11:43 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*stack_lstlast(t_ps *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	stack_lstcount(t_ps *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_ps	*stack_lst_before_last(t_ps *lst)
{
	while (lst != NULL)
	{
		if (lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	stack_lstadd_back(t_ps **lst, t_ps *new)
{
	t_ps	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = stack_lstlast(*lst);
		tmp->next = new;
	}
}

void	stack_lstclear(t_ps **lst)
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
