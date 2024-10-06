/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:29:26 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/12 19:42:31 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

/// @brief Counts the number of moves to position value_a optimally on stack_b.
/// @param value_a Value to position optimally on stack_b.
/// @param stack_b A pointer to the pointer to the head of stack_b.
/// @return The index of the closest minimum value in stack_b.
static int	count_moves(int idx_a, int idx_b, t_stack **stack_a,
		t_stack **stack_b)
{
	int	i;
	int	half_a;
	int	half_b;
	int	idx_ta;
	int	idx_tb;

	idx_ta = stack_n_elements(stack_a);
	idx_tb = stack_n_elements(stack_b);
	half_a = (stack_n_elements(stack_a) - 1) / 2;
	half_b = (stack_n_elements(stack_b) - 1) / 2;
	i = 0;
	if (idx_a <= half_a && idx_b <= half_b)
		i = get_max_value(idx_a, idx_b);
	else if (idx_a <= half_a && idx_b >= half_b)
		i = (idx_tb - idx_b) + idx_a;
	else if (idx_a >= half_a && idx_b <= half_b)
		i = (idx_ta - idx_a) + idx_b;
	else if (idx_a >= half_a && idx_b >= half_b)
		i = get_max_value(idx_tb - idx_b, idx_ta - idx_a);
	return (i);
}

/// @brief Counts the number of moves to position value_a optimally on stack_b.
/// @param value_a Value to position optimally on stack_b.
/// @param stack_b A pointer to the pointer to the head of stack_b.
/// @param cond 0 = makes ascendente 0123 | 1 = makes desc 3210
/// @return The index of the closest minimum value in stack_b.
int	to_go(int value_a, t_stack **stack_b, int cond)
{
	int	to_go;

	to_go = get_closest_min(value_a, stack_b);
	if (to_go == -1)
		to_go += get_closest_max(value_a, stack_b);
	if (to_go == -1)
		to_go = stack_idx(stack_b, stack_max_nbr(stack_b));
	if (to_go > stack_n_elements(stack_b))
	{
		to_go = 0;
		return (to_go);
	}
	return (to_go + cond);
}

/// @brief Determines the best element index to move from stack_1 to
///			stack_2 based on a condition.
/// @param stack_1 Pointer to the first stack.
/// @param stack_2 Pointer to the second stack.
/// @param cond Condition to determine the best move strategy.
/// @return Returns the index of the best element in stack_1 to move.
int	best_to_send(t_stack **stack_1, t_stack **stack_2, int cond)
{
	t_stack	*temp_1;
	int		current_move;
	int		moves;
	int		i;
	int		res;

	temp_1 = (*stack_1);
	i = 0;
	res = INT_MAX;
	moves = INT_MAX;
	while (temp_1)
	{
		current_move = count_moves(i, to_go(temp_1->content, stack_2, cond),
				stack_1, stack_2);
		if (current_move < moves)
		{
			moves = current_move;
			res = i;
		}
		temp_1 = temp_1->next;
		i++;
	}
	return (res);
}
