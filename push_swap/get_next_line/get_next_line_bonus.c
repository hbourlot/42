/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:56:49 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/09 21:26:52 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*rest;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			bytes;

	rest = NULL;
	bytes = 42;
	if (BUFFER_SIZE < 1 || fd >= FOPEN_MAX || fd == -1)
		return (NULL);
	while (bytes != 0)
	{
		if (!buffer[fd][0])
			bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes < 0)
		{
			if (rest)
				free(rest);
			return (NULL);
		}
		rest = ft_strjoin_mod(rest, buffer[fd]);
		if (set_buffer(buffer[fd]) == 1)
			return (rest);
	}
	return (rest);
}
