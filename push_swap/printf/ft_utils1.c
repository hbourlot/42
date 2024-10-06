/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:20:56 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/03 19:48:13 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// /// @brief Calculate the length of a null-terminated string.
// /// @param s Pointer to the input string.
// /// @return The length of the string (number of characters 
// // before the null terminator).
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

/// @brief Handle different format specifiers for custom printf-like function.
/// @param fmt Pointer to the format string (single character expected).
/// @param ap Pointer to a list of arguments to be formatted.
/// @return The number of characters written for the given format specifier.
int	ft_format(const char *fmt, va_list *ap)
{
	int	i;

	i = 0;
	if (fmt[0] == 'c')
		i += ft_putchar(va_arg(*ap, int));
	else if (fmt[0] == 's')
		i += ft_putstr(va_arg(*ap, char *));
	else if (fmt[0] == 'p')
		i += handle_flags((long)va_arg(*ap, unsigned long), 'p',
				"0123456789abcdef");
	else if (fmt[0] == 'd' || fmt[0] == 'i')
		i += handle_flags(va_arg(*ap, int), 'i', "0123456789");
	else if (fmt[0] == 'u')
		i += handle_flags(va_arg(*ap, unsigned int), 'u', "0123456789");
	else if (fmt[0] == 'X')
		i += handle_flags(va_arg(*ap, unsigned int), 'X', "0123456789ABCDEF");
	else if (fmt[0] == 'x')
		i += handle_flags(va_arg(*ap, unsigned int), 'x', "0123456789abcdef");
	else if (fmt[0] == '%')
		i += ft_putchar('%');
	return (i);
}

/// @brief Custom implementation of printf function to format and print data.
/// @param fmt Pointer to the format string.
/// @param ... Variable number of arguments to be formatted.
/// @return The total number of characters written, or
/// -1 if the format string is NULL.
int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		result;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	result = 0;
	i = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			result += ft_format(++fmt, &ap);
		else
		{
			ft_putchar(*fmt);
			i++;
		}
		fmt++;
	}
	va_end(ap);
	return (result + i);
}
