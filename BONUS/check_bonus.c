/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:47:12 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/18 18:25:21 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_int_min_max(char *args, char **all_args)
{
	long	tmp_l;
	int		tmp_i;

	tmp_i = ft_atoi(args);
	tmp_l = ft_atol(args);
	if ((long)tmp_i != tmp_l)
	{
		free_2d_array(all_args);
		error_case();
	}
}

void	check_args_bis(char *args, char **all_args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		check_int_min_max(args, all_args);
		if ((args[i] == '-' || args[i] == '+')
			&& ft_isdigit(args[i + 1]))
			i++;
		if (!ft_isdigit(args[i]))
		{
			free_2d_array(all_args);
			error_case();
		}
		i++;
	}
}

void	check_args(char **args)
{
	int	i;

	i = 0;
	if (!*args)
	{
		free_2d_array(args);
		error_case();
	}
	while (args[i])
	{
		check_args_bis(args[i], args);
		i++;
	}
}

void	check_same_args(t_ps *lst)
{
	t_ps	*node_1;
	t_ps	*node_2;

	node_1 = lst;
	while (node_1)
	{
		node_2 = node_1->next;
		while (node_2)
		{
			if (node_1->number == node_2->number)
			{
				stack_lstclear(&lst);
				error_case();
			}
			node_2 = node_2->next;
		}
		node_1 = node_1->next;
	}
}

int	check_sort(t_ps *list)
{
	t_ps	*node;
	t_ps	*next_node;

	node = list;
	if (!node->next)
		return (1);
	while (node->next)
	{
		next_node = node->next;
		if (node->number > next_node->number)
			return (0);
		node = next_node;
	}
	return (1);
}
