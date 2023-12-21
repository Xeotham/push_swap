/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:47:12 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/21 13:33:56 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (j == 0 && (ft_strlen(args[i]) > 11 || (ft_strlen(args[i]) == 11
						&& ft_strnstr(args[i], "-2147483649", 11) == 0)))
			{
				free_2d_array(args);
				exit(EXIT_FAILURE);
			}
			if (j == 0 && args[i][j] == '-')
				j++;
			if (!ft_isdigit(args[i][j]) )
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
