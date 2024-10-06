/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:04:58 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/24 14:54:36 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

/// @brief Swaps the first two elements of the stack.
/// @param stack Pointer to the stack.
/// @return 0 on success.
int	ft_swap(t_stack **stack, char *str)
{
	t_stack	*temp;
	int		temp_value;

	if ((*stack) && stack && (*stack)->next)
	{
		temp = (*stack)->next;
		temp_value = (*stack)->content;
		(*stack)->content = temp->content;
		temp->content = temp_value;
		ft_printf("%s", str);
		return (0);
	}
	return (1);
}

/// @brief Moves the top element from stack_1 to stack_2 and
///			prints the operation.
/// @param stack_1 Pointer to the first stack.
/// @param stack_2 Pointer to the second stack.
/// @param str The operation string to be printed.
/// @return 0 on success.
int	ft_push(t_stack **stack_1, t_stack **stack_2, char *str)
{
	t_stack	*temp;

	if (!stack_1 || !stack_2 || !str)
		return (1);
	if (!(*stack_2) && stack_1)
	{
		(*stack_2) = (*stack_1);
		(*stack_1) = (*stack_1)->next;
		(*stack_2)->next = NULL;
	}
	else
	{
		if (stack_1 && *stack_1)
		{
			temp = (*stack_1);
			(*stack_1) = (*stack_1)->next;
			temp->next = (*stack_2);
			(*stack_2) = temp;
		}
	}
	ft_printf("%s", str);
	return (0);
}

/// @brief Shifts all elements of the stack down by 1.
/// @param stack_1 Pointer to the stack.
/// @return 0 on success.
int	ft_shift_down(t_stack **stack, char *str)
{
	t_stack	*b_last;
	t_stack	*last;

	if (stack && *stack && (*stack)->next)
	{
		b_last = (*stack);
		while (b_last->next->next)
			b_last = b_last->next;
		last = b_last->next;
		b_last->next = NULL;
		ft_printf("%s", str);
		if (!stack_add_front(&(*stack), last))
			return (0);
	}
	return (1);
}

/// @brief Shifts all elements of the stack up by 1.
/// @param stack_1 Pointer to the stack.
/// @return 0 on success.
int	ft_shift_up(t_stack **stack, char *str)
{
	t_stack	*node;

	if (*stack && stack && (*stack)->next)
	{
		node = (*stack)->next;
		stack_add_back(&node, (*stack));
		(*stack)->next = NULL;
		(*stack) = node;
		ft_printf("%s", str);
		return (0);
	}
	return (1);
}
