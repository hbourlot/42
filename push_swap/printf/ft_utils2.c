/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:12:38 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/03 19:47:45 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Writes a single character to the standard output.
/// @param c The character to write.
/// @return The number of characters written (always 1).
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/// @brief Writes a string to the standard output.
/// @param c The string to write.
/// @return The number of characters written.	
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

/// @brief Handles formatting for various specifiers and 
// prints the formatted output.
/// @param nbr The number to format.
/// @param fmt The format specifier.
/// @param base The base used for number conversion.
/// @return The number of characters written.
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

/// @brief Converts a number to the given base and prints it.
/// @param nbr The number to convert and print.
/// @param fmt The base characters for conversion.
/// @return The number of characters written.
int	number_base(long nbr, char *fmt)
{
	int	i;
	int	len;

	len = ft_strlen(fmt);
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

/// @brief Converts a number to the given base for pointer 
// formatting and prints it.
/// @param nbr The number to convert and print.
/// @param fmt The base characters for conversion.
/// @return The number of characters written.
int	base_p_negative(unsigned long nbr, char *fmt)
{
	int	i;
	int	len;

	len = ft_strlen(fmt);
	i = 0;
	if (nbr >= 16)
	{
		i = base_p_negative(nbr / len, fmt);
		return (i + base_p_negative(nbr % len, fmt));
	}
	else
		return (ft_putchar("0123456789abcdef"[nbr]));
}
