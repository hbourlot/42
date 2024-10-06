/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:36:32 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/25 13:24:52 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

/// @brief Implements an algorithm to sort elements in stack_1
///        using stack_2 as auxiliary storage.
/// @param stack_1 A double pointer to the head of the first stack.
/// @param stack_2 A double pointer to the head of the second stack (auxiliary).
/// @return Returns `0` after sorting stack_1 in ascending order
///			and freeing allocated memory.
int	algorithm(t_stack **stack_1, t_stack **stack_2)
{
	int	first;
	int	second;

	while (stack_n_elements(stack_1) > 3)
	{
		partition_stack_by_avg(stack_1);
		if ((*stack_1))
			ft_push(stack_1, stack_2, "pb\n");
	}
	if (stack_n_elements(stack_1) == 3)
	{
		first = (*stack_1)->content;
		second = (*stack_1)->next->content;
		sort_three(first, second, stack_last(stack_1)->content, stack_1);
	}
	while ((*stack_2))
	{
		make_mvs(stack_2, stack_1, 1);
		ft_push(stack_2, stack_1, "pa\n");
	}
	move_min_top(stack_1, "rra\n");
	free_all(stack_1);
	return (0);
}

/// @brief Adds elements to the stack from a given string
///			and checks for duplicates.
/// @param stack_1 A double pointer to the head of the stack.
/// @param arg A string representing the input argument.
/// @return Returns `0` if elements are added successfully.
///         Returns `1` if a duplicate value is found in the stack.
static int	add_elements_to_stack(t_stack **stack_1, char *arg)
{
	t_stack	*temp;
	char	**split;
	int		j;

	j = 0;
	split = ft_split(arg, ' ');
	while (split[j])
	{
		temp = stack_new(ft_atoi(split[j]));
		if (stack_add_back(stack_1, temp))
		{
			free_split(split);
			free_all(stack_1);
			return (write(2, ERROR, 6));
		}
		j++;
	}
	free_split(split);
	if (ft_check_duplicate(stack_1))
	{
		free_all(stack_1);
		return (1);
	}
	return (0);
}

/// @brief Creates a stack from the input arguments and adds each
///			element to the stack.
/// @param stack_1 A double pointer to the head of the stack.
/// @param argv An array of strings representing the input arguments.
/// @return Returns `0` if the stack is created successfully.
///         Returns `1` if a duplicate value is found in the stack.
int	create_stack(t_stack **stack_1, char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (add_elements_to_stack(stack_1, argv[i]))
			return (1);
		i++;
	}
	return (0);
}
