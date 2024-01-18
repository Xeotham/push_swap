/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:13:36 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/18 18:21:11 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_case(void)
{
	ft_printf_fd(2, "Error\n");
	exit(EXIT_FAILURE);
}

void	fail_case(t_ps **stack_a, t_ps **stack_b)
{
	stack_lstclear(stack_a);
	if (stack_b)
		stack_lstclear(stack_b);
	ft_printf("KO\n");
	exit(EXIT_SUCCESS);
}

void	success_case(t_ps **stack_a, t_ps **stack_b)
{
	stack_lstclear(stack_a);
	if (stack_b)
		stack_lstclear(stack_b);
	ft_printf("OK\n");
	exit(EXIT_SUCCESS);
}
