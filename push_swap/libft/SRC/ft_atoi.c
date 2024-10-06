/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:03:00 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/16 14:58:36 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Converts a string representation of a number to an integer.
/// @param nptr Pointer to the string to be converted.
/// @return The converted integer.
long	ft_atoi(const char *nptr)
{
	int		tot;
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	tot = 0;
	while ((nptr[tot] >= 9 && nptr[tot] <= 13) || nptr[tot] == ' ')
		tot++;
	if (nptr[tot] == '+' || nptr[tot] == '-')
	{
		if (nptr[tot] == '-')
			sign = -1;
		tot++;
	}
	while (nptr[tot] && nptr[tot] >= '0' && nptr[tot] <= '9')
	{
		nbr = (nbr * 10) + nptr[tot] - '0';
		if (((-nbr) < (long)INT_MIN && sign == -1) || (nbr > (long)INT_MAX
				&& sign == 1))
			return ((long)INT_MAX + 1);
		tot++;
	}
	return (nbr * sign);
}
