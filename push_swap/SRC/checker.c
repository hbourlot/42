/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:31:50 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/24 11:51:20 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

/// @brief Checks if the input strings contain any alphabetic
///			characters or periods.
/// @param str An array of strings to be checked.
/// @return Returns `0` if the input contains no alphabetic
///			characters or periods. Returns `-1` if any
///			alphabetic character or period is found.
int	check_letter(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '+' && argv[i][j] != '-')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

/// @brief Checks if the input arguments contain valid integers
///			within the range of `INT_MAX` and `INT_MIN`.
/// @param argv An array of strings representing the input arguments.
/// @return Returns `0` if all input arguments are valid integers
///			within the range. Returns `-1` if any input argument
///				is outside the valid integer range.
int	check_int(char *argv[])
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (argv[i])
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		while (split[j])
		{
			if ((long)INT_MAX + 1 == ft_atoi(split[j])
				|| ft_atoi(split[j]) > INT_MAX || ft_atoi(split[j]) < INT_MIN)
			{
				free_split(split);
				return (-1);
			}
			j++;
		}
		i++;
		free_split(split);
	}
	return (0);
}

int	validate_numbers(char *argv[])
{
	int	i;
	int	j;
	int	valid;

	i = 1;
	while (argv[i])
	{
		j = 0;
		valid = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				valid = 1;
			if ((argv[i][j] == '+' || argv[i][j] == '-') && j > 0 && argv[i][j
				- 1] != ' ')
			{
				return (1);
			}
			j++;
		}
		if (valid == 0)
			return (1);
		i++;
	}
	return (0);
}

/// @brief Validates the input arguments by checking for letters and integers.
/// @param argv An array of strings representing the input arguments.
/// @return Returns `0` if the input is valid.
///         Returns `-1` if the input contains letters or invalid integers.
int	validate_input(char **argv)
{
	if (validate_numbers(argv))
		return (-1);
	if (check_letter(argv))
		return (-1);
	if (check_int(argv))
		return (-1);
	return (0);
}
