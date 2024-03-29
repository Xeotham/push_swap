/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:10:08 by mhaouas           #+#    #+#             */
/*   Updated: 2023/11/20 11:03:42 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_new_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i])
	{
		i++;
	}
	if (buff[i] == '\n')
		return (i + 1);
	return (-1);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*buff;

	if (!s1)
		return (ft_strjoin("", s2));
	else if (!s2)
		return (NULL);
	else
	{
		buff = ft_strjoin(s1, s2);
		free(s1);
		return (buff);
	}
}
