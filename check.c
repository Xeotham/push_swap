/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:47:12 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/20 16:10:31 by mhaouas          ###   ########.fr       */
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
			if (!ft_isdigit(args[i][j]))
			{
				free_2d_array(args);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
