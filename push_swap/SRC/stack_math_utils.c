/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_math_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:15:34 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/25 13:28:49 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

/// @brief Finds the minimum value in the stack.
/// @param stack Pointer to the stack.
/// @return The minimum value in the stack.
int	stack_min_nbr(t_stack **stack)
{
	t_stack	*temp;
	int		min;

	temp = (*stack);
	min = temp->content;
	while (temp)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

/// @brief Finds the maximum value in the stack.
/// @param stack Pointer to the stack.
/// @return The maximum value in the stack.
int	stack_max_nbr(t_stack **stack)
{
	t_stack	*temp;
	int		max;

	temp = (*stack);
	max = temp->content;
	while (temp)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	return (max);
}

/// @brief Converts a given integer to its positive equivalent.
/// @param nbr The integer to be converted.
/// @return The positive equivalent of the input integer.
int	make_positive(int nbr)
{
	if (nbr < 0)
		nbr = -(nbr);
	return (nbr);
}

/// @brief Returns the smaller of two integer values.
/// @param a First integer.
/// @param b Second integer.
/// @return The smaller of the two integers.
int	get_min_value(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
