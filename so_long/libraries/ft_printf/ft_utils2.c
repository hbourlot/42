/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:12:38 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/21 19:12:16 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (ft_putstr("(null)"));
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
	return (i);
}

int	handle_flags(long nbr, char fmt, char *base)
{
	if (fmt == 'p' && nbr <= 0)
	{
		if (nbr == 0)
			return (ft_putstr(ERROR_MSG1));
		return (ft_putstr(HEX_MSG) + base_p_negative(nbr, base));
	}
	else if (fmt == 'p')
		return (ft_putstr(HEX_MSG) + base_p_negative(nbr, base));
	else if (fmt == 'x' || fmt == 'X')
		return (number_base(nbr, base));
	else
		return (number_base(nbr, base));
}

int	number_base(long nbr, char *fmt)
{
	int	i;
	int	len;

	len = ft_str_len(fmt);
	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		return (number_base(-nbr, fmt) + 1);
	}
	if (nbr >= len)
	{
		i = number_base(nbr / len, fmt);
		return (i + number_base(nbr % len, fmt));
	}
	else
		return (ft_putchar(fmt[nbr]));
}

int	base_p_negative(unsigned long nbr, char *fmt)
{
	int	i;
	int	len;

	len = ft_str_len(fmt);
	i = 0;
	if (nbr >= 16)
	{
		i = base_p_negative(nbr / len, fmt);
		return (i + base_p_negative(nbr % len, fmt));
	}
	else
		return (ft_putchar("0123456789abcdef"[nbr]));
}

// int get_len(long nbr)
// {
//   if (nbr < 0)
// 	return (get_len(-nbr) + 1);
//   if (nbr > 9)
//     return (get_len(nbr / 10) + 1);
//   return (1);
// }

// char	*ft_itoa_iter(long nbr)
// {
// 	int	len;
// 	char *temp;

// 	len = get_len(nbr);
// 	temp = malloc(sizeof(char) * (len + 1));
// 	if (!temp)
// 		return (NULL);
// 	temp[len] = '\0';
// 	if (nbr < 0)
// 	{
// 		temp[0] = '\0';
// 		nbr = -nbr;
// 	}
// 	while (nbr > 0)
// 	{
// 		temp[--len] = (nbr % 10) + '0';
// 		nbr = nbr / 10;
// 	}
// 	return (temp);
// }
// int number_u_negative(long nbr)
// {
//   long base;
//   char *number;
