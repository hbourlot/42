/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:48:46 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/25 15:22:40 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_only_valid_numbers(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-') && j != 0 && argv[i][j
				- 1] != ' ')
				return (0);
			if ((argv[i][j] == '+' || argv[i][j] == '-') && argv[i][j + 1]
				&& ft_isdigit(argv[i][j + 1]))
			{
				j++;
				continue ;
			}
			else if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parsing(int argc, char *argv[])
{
	if (!is_only_valid_numbers(argv))
		return (ft_putstr_fd("Arguments invalid!\n", 2), -1);
	if (argc != 5 && argc != 6)
		return (ft_putstr_fd("Arguments invalid!\n", 2), 1);
	if (ft_atoi(argv[1]) < 1)
		return (ft_putstr_fd("Invalid number of philosophers.\n", 2), 1);
	if (ft_atoi(argv[2]) < 0)
		return (ft_putstr_fd("Invalid time_to_die.\n", 2), 1);
	if (ft_atoi(argv[3]) < 0)
		return (ft_putstr_fd("Invalid time_to_eat.\n", 2), 1);
	if (ft_atoi(argv[4]) < 0)
		return (ft_putstr_fd("Invalid time_to_sleep.\n", 2), 1);
	return (0);
}
