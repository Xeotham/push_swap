/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:29:40 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/20 16:12:37 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*tmp;
	char	**all_args;
	t_ps_a	*stack_a;

	if (argc < 2)
		return (1);
	tmp = ft_unsplit(argv + 1, " ");
	all_args = ft_split(tmp, ' ');
	free(tmp);
	check_args(all_args);
	stack_a = make_pile_a(all_args);
	while (stack_a)
	{
		printf("Number (characters) :%s, Number (int) : %d, Index : %d\n", stack_a->c_number, stack_a->i_number, stack_a->index);
		stack_a = stack_a->next;
	}
}