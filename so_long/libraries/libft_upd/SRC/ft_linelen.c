/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:45:15 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/11 11:44:09 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Calculates the length of a line in the string `src`
///				until it encounters a newline character.
/// @param src The string to calculate the line length from.
/// @return The length of the line in characters,
///			NOT including the newline character if present.
int	ft_linelen(char *src)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		if (src[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
