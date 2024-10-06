/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:09:14 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/25 13:24:10 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

/// @brief Checks if the stack has duplicated value.
/// @param stack Pointer to the stack.
/// @return 0 if the stack is sorted, 1 otherwise.
int	ft_check_duplicate(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*node;
	int		i;
	int		j;

	temp = (*stack_a);
	j = 0;
	while (temp)
	{
		node = (*stack_a);
		i = 0;
		while (i++ < j)
		{
			if (node->content == temp->content)
			{
				write(2, &ERROR, 6);
				return (1);
			}
			node = node->next;
		}
		temp = temp->next;
		j++;
	}
	return (0);
}

/// @brief Checks if a stack is sorted in ascending order.
/// @param stack A pointer to the top of the stack to be checked.
/// @return Returns 0 if the stack is sorted in ascending order,
///			and 1 if it is not sorted or if the stack is NULL.
int	sort_checker(t_stack **stack)
{
	t_stack	*temp;

	if (stack)
	{
		temp = (*stack);
		while (temp->next)
		{
			if (temp->content > temp->next->content)
			{
				return (1);
			}
			temp = temp->next;
		}
		return (0);
	}
	return (1);
}

/// @brief Returns the index of the given value in the stack, or
///			-1 if not found.
/// @param stack A pointer to the pointer to the head of the
///			stack (linked list).
/// @param value The value to find in the stack.
/// @return The index of the value in the stack, or
///			-1 if the value is not found.
int	stack_idx(t_stack **stack, int value)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = (*stack);
	if (*stack)
	{
		while (temp)
		{
			if (temp->content == value)
				return (i);
			i++;
			temp = temp->next;
		}
	}
	return (-1);
}

/// @brief Returns the value at a specified index in the stack.
/// @param stack Pointer to the stack.
/// @param idx Index of the desired element.
/// @return The value at the specified index,
///	or 0 if the index is out of bounds.
int	stack_value(t_stack **stack, int idx)
{
	t_stack	*temp;

	temp = (*stack);
	while (idx >= 0 && idx--)
	{
		if (temp->next == NULL)
			return (temp->content);
		temp = temp->next;
	}
	return (temp->content);
}

/// @brief Counts the number of elements in the stack.
/// @param stack Pointer to the stack.
/// @return The number of elements in the stack.
int	stack_n_elements(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	if (*stack)
	{
		temp = (*stack);
		while (temp)
		{
			i++;
			temp = temp->next;
		}
		return (i);
	}
	return (i);
}
