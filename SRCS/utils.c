/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:41:17 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/11 20:07:41 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*find_cheapest(t_ps *to_search)
{
	if (to_search == NULL)
		return (NULL);
	while (!to_search->is_cheapest)
		to_search = to_search->next;
	return (to_search);
}