/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:29:37 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/18 18:28:09 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../Libft/libft.h"

typedef struct s_ps
{
	int			number;
	struct s_ps	*next;
}				t_ps;

enum			e_move
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

void			push_swap(t_ps *stack_a);

void			check_args(char **args);

t_ps			*make_stack_a(char **args);

t_ps			*stack_lstlast(t_ps *lst);

void			stack_lstadd_back(t_ps **lst, t_ps *new);

void			stack_lstclear(t_ps **lst);

void			check_same_args(t_ps *lst);

void			index_maker(t_ps *stack);

t_ps			*stack_lst_before_last(t_ps *lst);

int				stack_lstcount(t_ps *lst);

void			rrr(t_ps **stack_a, t_ps **stack_b);

void			rrb(t_ps **stack_a, t_ps **stack_b);

void			rra(t_ps **stack_a, t_ps **stack_b);

void			rr(t_ps **stack_a, t_ps **stack_b);

void			rb(t_ps **stack_a, t_ps **stack_b);

void			ra(t_ps **stack_a, t_ps **stack_b);

void			pa(t_ps **begining_a, t_ps **begining_b);

void			pb(t_ps **begining_a, t_ps **begining_b);

void			ss(t_ps **stack_a, t_ps **stack_b);

void			sb(t_ps **stack_a, t_ps **stack_b);

void			sa(t_ps **stack_a, t_ps **stack_b);

void			make_move(t_ps **stack_a, t_ps **stack_b);

int				check_sort(t_ps *list);

void			move(t_ps **stack_a, t_ps **stack_b, int to_comp,
					void move(t_ps **, t_ps **));

void			error_case(void);

void			success_case(t_ps **stack_a, t_ps **stack_b);

void			fail_case(t_ps **stack_a, t_ps **stack_b);

#endif
