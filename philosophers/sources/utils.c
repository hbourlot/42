/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 05:45:48 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/25 15:24:46 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "limits.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

int	ft_atoi(const char *nptr)
{
	int		tot;
	int		sign;
	long	number;

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
		if (number > 2147483647 || number < 0)
			return (-1);
		tot++;
	}
	return (number * sign);
}

int	get_think_time(int time_to_die, int time_to_eat, int time_to_sleep)
{
	int	time_to_think;

	time_to_think = time_to_die - ((time_to_eat * 2) + time_to_sleep);
	if (time_to_think < 0)
		time_to_think = 0;
	return (time_to_think);
}

void	delay_simulation(t_data *table)
{
	while (get_time() < table->start_time)
		continue ;
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
