/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:12:08 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/24 21:17:24 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

/// @brief Sorts three elements in a stack using a minimal
///				number of operations.
/// @param first The first element of the stack.
/// @param second The second element of the stack.
/// @param last The third element of the stack.
/// @param stack A pointer to the pointer to the head of
///			the stack (linked list).
/// @return The number of operations performed to sort the stack.
void	sort_three(int first, int second, int last, t_stack **stack)
{
	int	min;

	min = stack_idx(stack, stack_min_nbr(stack));
	if (min == 0)
	{
		if (second > last)
		{
			ft_shift_up(stack, "ra\n");
			ft_swap(stack, "sa\n");
		}
	}
	else if (min == 1)
	{
		if (first < last)
			ft_swap(stack, "sa\n");
	}
	else if (min == 2)
	{
		if (first > second)
			ft_swap(stack, "sa\n");
	}
}

/// @brief Moves the minimum element in the stack to the top.
/// @param stack Pointer to the stack.
/// @param str String to record the operations performed.
/// @return Always returns 0.
int	move_min_top(t_stack **stack, char *str)
{
	int	half;
	int	idx_min;

	idx_min = stack_idx(stack, stack_min_nbr(stack));
	half = (stack_n_elements(stack) - 1) / 2;
	if (idx_min <= half)
	{
		str++;
		while (idx_min-- > 0)
			ft_shift_up(stack, str);
	}
	else
	{
		idx_min = stack_n_elements(stack) - idx_min;
		while (idx_min-- > 0)
			ft_shift_down(stack, str);
	}
	return (0);
}

/// @brief Creates stack B by moving elements less
///			than or equal to the average value of stack A.
/// @param stack_a Pointer to stack A.
/// @param stack_b Pointer to stack B.
/// @return Always returns 0.
int	partition_stack_by_avg(t_stack **stack)
{
	t_stack		*temp;
	int			now;
	int			next;
	long long	avg;

	avg = 0;
	temp = (*stack);
	while (temp)
	{
		now = temp->content;
		avg += now;
		temp = temp->next;
	}
	avg = avg / stack_n_elements(stack);
	while ((*stack)->content > avg && (*stack)->next)
	{
		now = (*stack)->content;
		next = (*stack)->next->content;
		if (next < avg || next < avg)
			ft_swap(stack, "sa\n");
		else
			ft_shift_down(stack, "rra\n");
	}
	return (0);
}

/// @brief Returns the biggets of two integer values.
/// @param a First integer.
/// @param b Second integer.
/// @return The smaller of the two integers.
int	get_max_value(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

/// @brief  function frees all nodes in a linked list and
///			deallocates the memory used by each node.
/// @param stack A double pointer to the head of the
///			linked list (t_stack **stack).
/// @return Returns 0 if the linked list was successfully
///			freed, otherwise -1.
int	free_all(t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	if (*stack)
	{
		node = (*stack);
		while (node)
		{
			temp = node;
			node = node->next;
			free(temp);
		}
		(*stack) = NULL;
		return (0);
	}
	return (-1);
}
