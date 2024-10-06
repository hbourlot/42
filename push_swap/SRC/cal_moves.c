/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:10:22 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/12 19:42:01 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

/// @brief Move elements up in two stacks simultaneously when possible.
/// @param b_s Number of elements to move up in stack_1 (negative value).
/// @param b_r Number of elements to move up in stack_2 (negative value).
/// @param stack_1 Pointer to the first stack.
/// @param stack_2 Pointer to the second stack.
/// @return Always returns 0.
static int	mv_up(int b_s, int b_r, t_stack **stack_1, t_stack **stack_2)
{
	while (b_s < 0 && b_r < 0)
	{
		ft_shift_up(stack_1, "");
		ft_shift_up(stack_2, "");
		ft_printf("rr\n");
		b_s++;
		b_r++;
	}
	while (b_s++ < 0)
		ft_shift_up(stack_1, "rb\n");
	while (b_r++ < 0)
		ft_shift_up(stack_2, "ra\n");
	return (0);
}

/// @brief Move elements down in two stacks simultaneously when possible.
/// @param b_s Number of elements to move down in stack_1.
/// @param b_r Number of elements to move down in stack_2.
/// @param stack_1 Pointer to the first stack.
/// @param stack_2 Pointer to the second stack.
/// @return Always returns 0.
static int	mv_down(int b_s, int b_r, t_stack **stack_1, t_stack **stack_2)
{
	while (b_s > 0 && b_r > 0)
	{
		ft_shift_down(stack_1, "");
		ft_shift_down(stack_2, "");
		ft_printf("rrr\n");
		b_s--;
		b_r--;
	}
	while (b_s-- > 0)
		ft_shift_down(stack_1, "rrb\n");
	while (b_r-- > 0)
		ft_shift_down(stack_2, "rra\n");
	return (0);
}

/// @brief Calculate the number of moves to bring an element at a given
///         index to the top of the stack.
/// @param idx Pointer to the index of the element.
/// @param stack Pointer to the stack structure.
/// @return The number of moves required to bring the element to the top
///         of the stack.
static int	cal_mvs(int *idx, t_stack **stack)
{
	int	half;

	half = stack_n_elements(stack) / 2;
	if (*idx <= half)
		*idx = -(*idx);
	else
		*idx = stack_n_elements(stack) - *idx;
	return (*idx);
}

/// @brief Orchestrate the movement of elements between two stacks based
///         on a condition.
/// @param stack_1 Pointer to the first stack.
/// @param stack_2 Pointer to the second stack.
/// @param cond Condition to determine the best move strategy.
void	make_mvs(t_stack **stack_1, t_stack **stack_2, int cond)
{
	int	b_s;
	int	b_r;

	b_s = best_to_send(stack_1, stack_2, cond);
	b_r = to_go(stack_value(stack_1, b_s), stack_2, cond);
	b_s = cal_mvs(&b_s, stack_1);
	b_r = cal_mvs(&b_r, stack_2);
	if (b_s <= 0 && b_r <= 0)
		mv_up(b_s, b_r, stack_1, stack_2);
	else if (b_s >= 0 && b_r >= 0)
		mv_down(b_s, b_r, stack_1, stack_2);
	else if (b_s >= 0 && b_r <= 0)
	{
		while (b_s-- > 0)
			ft_shift_down(stack_1, "rrb\n");
		while (b_r++ < 0)
			ft_shift_up(stack_2, "ra\n");
	}
	else if (b_s <= 0 && b_r >= 0)
	{
		while (b_r-- > 0)
			ft_shift_down(stack_2, "rra\n");
		while (b_s++ < 0)
			ft_shift_up(stack_1, "rb\n");
	}
}
