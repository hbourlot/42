/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:08:09 by hbourlot          #+#    #+#             */
/*   Updated: 2024/04/11 12:22:57 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenth;
	char	*char_big;
	char	*char_little;

	char_little = (char *)little;
	char_big = (char *)big;
	i = 0;
	lenth = ft_strlen(little);
	if (lenth == 0)
		return ((char *)big);
	while (char_big[i] && i < len)
	{
		j = 0;
		while (char_big[i + j] == char_little[j] && i + j < len)
		{
			if (char_little[j + 1] == 0)
				return (char_big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
