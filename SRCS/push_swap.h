/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:29:37 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/12 14:06:28 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

typedef struct s_ps
{
	int			number;
	int			index;
	int			median;
	int			to_median;
	int			move_number;
	int			true_cost;
	int			is_cheapest;
	int			sim_move;
	int			reverse;
	struct s_ps	*target;
	struct s_ps	*next;
}				t_ps;

void			push_swap(t_ps *stack_a);

void			check_args(char **args);

t_ps			*make_pile_a(char **args);

t_ps			*stack_lstlast(t_ps *lst);

void			stack_lstadd_back(t_ps **lst, t_ps *new);

void			stack_lstclear(t_ps **lst);

void			check_same_args(char **args);

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

void			find_median(t_ps **stack);

void			find_target_f(t_ps **stack_search, t_ps **stack_target);

void			find_target_l(t_ps **stack_search, t_ps **stack_target);

void			check_cost(t_ps **stack_search);

int				check_sort(t_ps *list);

t_ps			*find_cheapest(t_ps *to_search);

void			do_move_f(t_ps **stack_a, t_ps **stack_b, t_ps *cheapest,
					t_ps *target);

void			do_move_l(t_ps **stack_a, t_ps **stack_b, t_ps *cheapest,
					t_ps *target);

void			first_sort(t_ps **stack_a, t_ps **stack_b);

void			little_sort(t_ps **stack_a);

void			last_sort(t_ps **stack_b, t_ps **stack_a);

#endif
