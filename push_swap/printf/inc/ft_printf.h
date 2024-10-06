/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:31:33 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/03 19:42:24 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../../inc/lib_pushswap.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MSG1 "(nil)"
# define HEX_MSG "0x"

// size_t	ft_strlen(const char *s);
int	ft_putstr(char *c);
int	ft_putchar(char c);
int	ft_printf(const char *fmt, ...);
int	number_base(long nbr, char *fmt);
int	ft_format(const char *fmt, va_list *ap);
int	base_p_negative(unsigned long nbr, char *fmt);
int	handle_flags(long nbr, char fmt, char *base);

#endif
