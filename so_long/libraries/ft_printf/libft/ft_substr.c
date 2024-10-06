/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:01:05 by hbourlot          #+#    #+#             */
/*   Updated: 2024/04/12 13:25:51 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function allocates (using 'malloc()') and returns a substring from the
** string 's'.
** The substring begins at index 'start' and is as maximum size 'len'.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (i < len && start <= ft_strlen(s))
	{
		temp[i] = s[start];
		i++;
		start++;
	}
	temp[i] = '\0';
	return (temp);
}
