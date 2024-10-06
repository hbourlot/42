/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:00:21 by hbourlot          #+#    #+#             */
/*   Updated: 2024/05/05 21:18:36 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_line_lenth(char *src)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		if (src[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *src1, char *src2)
{
	char	*temp;
	char	*result;
	int		i;

	if (!src1 && src2[0] == '\0')
		return (NULL);
	temp = malloc(sizeof(char) * get_line_lenth(src1) + get_line_lenth(src2)
			+ 1);
	if (!temp)
		return (NULL);
	result = temp;
	i = 0;
	while (src1 && src1[i])
		*temp++ = src1[i++];
	free(src1);
	i = 0;
	while (src2 && src2[i])
	{
		*temp++ = src2[i];
		if (src2[i] == '\n')
			break ;
		i++;
	}
	*temp = '\0';
	return (result);
}

int	set_buffer(char *buffer)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (buffer[i])
	{
		if (k == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			k = 1;
		buffer[i] = 0;
		i++;
	}
	buffer[j] = '\0';
	return (k);
}
