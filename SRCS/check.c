/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:47:12 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/12 13:16:05 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_int_min_max(char *args)
{
	long	tmp_l;
	int		tmp_i;

	tmp_i = ft_atoi(args);
	tmp_l = ft_atol(args);
	if ((long)tmp_i != tmp_l)
		return (0);
	return (1);
}

void	check_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '-' && j == 0)
				j++;
			if ((j < 2 && !check_int_min_max(args[i])) || !ft_isdigit(args[i][j]))
			{
				free_2d_array(args);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	check_same_args(args);
}

void	check_same_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (!ft_strcmp(args[i], args[j]))
			{
				free_2d_array(args);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	
}

int	check_sort(t_ps	*list)
{
	int		list_size;
	int		i;
	t_ps	*node;
	t_ps	*next_node;

	i = 0;
	node = list;
	if (!node->next)
		return (1);
	list_size = stack_lstcount(node);
	while (i < list_size)
	{
		next_node = node->next;
		if (node->number > next_node->number)
			return (0);
		node = next_node;
		i++;
	}
	return (1);
}
