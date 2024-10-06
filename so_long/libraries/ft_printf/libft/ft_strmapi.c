/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:23:04 by hbourlot          #+#    #+#             */
/*   Updated: 2024/04/15 16:16:07 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*temp;

	len = ft_strlen(s);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	if (s)
	{
		i = 0;
		while ((char)s[i])
		{
			temp[i] = f(i, (char)s[i]);
			i++;
		}
		temp[i] = '\0';
	}
	return (temp);
}
