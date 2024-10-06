/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:12:38 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/05 14:46:35 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_str(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (ft_put_str("(null)"));
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
			return (ft_put_str(ERROR_MSG1));
		return (ft_put_str(HEX_MSG) + base_p_negative(nbr, base));
	}
	else if (fmt == 'p')
		return (ft_put_str(HEX_MSG) + base_p_negative(nbr, base));
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
