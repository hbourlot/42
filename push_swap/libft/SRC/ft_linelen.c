/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:47:35 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/09 23:47:36 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Calculates the length of a line in the string `src`
///				until it encounters a newline character.
/// @param src The string to calculate the line length from.
/// @return The length of the line in characters,
///			including the newline character if present.
int	ft_linelen(char *src)
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
