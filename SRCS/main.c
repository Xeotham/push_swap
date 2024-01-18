/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:42:15 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/18 11:04:21 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*tmp;
	char	**all_args;
	t_ps	*stack_a;

	if (argc < 2)
		return (1);
	tmp = ft_unsplit(argv + 1, " ");
	if (!tmp)
		error_case();
	all_args = ft_split(tmp, ' ');
	free(tmp);
	if (!all_args)
		error_case();
	check_args(all_args);
	stack_a = make_stack_a(all_args);
	free_2d_array(all_args);
	check_same_args(stack_a);
	if (check_sort(stack_a))
	{
		stack_lstclear(&stack_a);
		return (0);
	}
	push_swap(stack_a);
}
