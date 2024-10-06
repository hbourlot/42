/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:14:13 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/23 21:15:09 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

/// @brief Finds the closest value in the stack that is greater
///			than the given number and returns its index.
/// @param nbr The number to compare against the values in the stack.
/// @param stack A double pointer to the head of the linked
///			list (`t_stack **stack`).
/// @return The index of the closest value in the stack
///			that is greater than `nbr`.
///         Returns `-1` if no such value exists.
int	get_closest_max(int nbr, t_stack **stack)
{
	t_stack	*temp;
	int		res;

	res = stack_min_nbr(stack);
	temp = (*stack);
	if (nbr > stack_max_nbr(stack))
		return (-1);
	while (temp)
	{
		if (temp->content > nbr && temp->content < res)
			res = temp->content;
		temp = temp->next;
	}
	return (stack_idx(stack, res));
}

/// @brief Finds the index of the closest smaller number
///			in the stack that is greater than nbr.
/// @param nbr The number to compare against.
/// @param stack A pointer to the pointer to the head of
///			the stack (linked list).
/// @return The index of the closest smaller number in the stack or the
///			closest bigger if nbr is < min_stack_nbr.
int	get_closest_min(int nbr, t_stack **stack)
{
	t_stack	*temp;
	int		closest;

	temp = (*stack);
	closest = stack_min_nbr(stack);
	if (nbr < closest)
		return (-1);
	while (temp)
	{
		if (temp->content < nbr && temp->content > closest)
		{
			closest = temp->content;
			temp = (*stack);
		}
		temp = temp->next;
	}
	return (stack_idx(stack, closest));
}

/// @brief Prints the contents of the stack with
///			their positions.
/// @param stack Pointer to the stack.
/// @return Always returns 0.
int	print_stack(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 1;
	temp = (*stack);
	while (temp)
	{
		ft_printf("%d -> STACK: %d\n", i, temp->content);
		temp = temp->next;
		i++;
	}
	return (0);
}

void	free_split(char **split)
{
	int	ctd;

	ctd = 0;
	while (split[ctd])
		free(split[ctd++]);
	free(split);
}
