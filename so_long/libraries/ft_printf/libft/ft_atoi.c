/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:03:00 by hbourlot          #+#    #+#             */
/*   Updated: 2024/04/10 10:46:58 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	tot;
	int	sign;
	int	number;

	number = 0;
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
	while (nptr[tot] >= '0' && nptr[tot] <= '9')
	{
		number = (number * 10) + nptr[tot] - '0';
		tot++;
	}
	return (number * sign);
}
