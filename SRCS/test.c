/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:35:09 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/12 12:36:47 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	int	i;

	i = 0;
	while (i++ < 15)
		printf("%d / 2 = %d\n", i, i/2);
}