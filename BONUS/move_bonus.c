/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:45:46 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/19 16:16:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	do_move(int move, t_ps **stack_a, t_ps **stack_b)
{
	void	(*make_move[11])(t_ps **, t_ps **);	

	make_move[SA] = sa;
	make_move[SB] = sb;
	make_move[SS] = ss;
	make_move[PA] = pa;
	make_move[PB] = pb;
	make_move[RA] = ra;
	make_move[RB] = rb;
	make_move[RR] = rr;
	make_move[RRA] = rra;
	make_move[RRB] = rrb;
	make_move[RRR] = rrr;
	(make_move[move])(stack_a, stack_b);
}

int	verif_move(char *move)
{
	int		i;
	char	*move_type[11];

	i = 0;
	move_type[SA] = "sa\n";
	move_type[SB] = "sb\n";
	move_type[SS] = "ss\n";
	move_type[PA] = "pa\n";
	move_type[PB] = "pb\n";
	move_type[RA] = "ra\n";
	move_type[RB] = "rb\n";
	move_type[RR] = "rr\n";
	move_type[RRA] = "rra\n";
	move_type[RRB] = "rrb\n";
	move_type[RRR] = "rrr\n";
	while (i < 11)
	{
		if (!ft_strncmp(move, move_type[i], ft_strlen(move_type[i]) + 1))
			return (i);
		i++;
	}
	return (-1);
}

void	make_move(t_ps **stack_a, t_ps **stack_b)
{
	int		move;
	char	*tmp;

	move = 1;
	while (move >= 0)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		move = verif_move(tmp);
		free(tmp);
		if (move == -1)
		{
			stack_lstclear(stack_a);
			stack_lstclear(stack_b);
			error_case();
		}
		do_move(move, stack_a, stack_b);
	}
}
