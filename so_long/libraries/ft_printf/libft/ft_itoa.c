/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:48:46 by hbourlot          #+#    #+#             */
/*   Updated: 2024/04/17 13:25:44 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	static int	i;

	i = 0;
	if (n < 0)
	{
		n = -(n);
	}
	if (n)
	{
		get_len(n / 10);
		i++;
	}
	if (n == 0)
		return (1);
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			len;
	int			sign;
	long int	nbr;

	nbr = n;
	sign = 0;
	if (nbr < 0)
		sign++;
	len = get_len(n);
	result = (char *)malloc(sizeof(char) * (len + sign + 1));
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -(nbr);
	result[len + sign] = '\0';
	while (len > 0)
	{
		len--;
		result[len + sign] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	if (sign)
		result[0] = '-';
	return (result);
}
