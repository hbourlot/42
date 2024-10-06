/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:43:18 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/11 16:50:34 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lib_pushswap.h"

/// @brief Initializes the stacks and validates the input.
/// @param argc Argument count.
/// @param argv Argument vector.
/// @param stack_a Pointer to the stack A.
/// @return 0 if successful, 1 if an error occurs.
static int	initialize_stacks(int argc, char *argv[], t_stack **stack_a)
{
	if (argc > 1)
	{
		if (validate_input(argv))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (create_stack(stack_a, argv))
		{
			return (1);
		}
	}
	return (0);
}

/// @brief Processes and executes the moves from input.
/// @param stack_a Pointer to stack A.
/// @param stack_b Pointer to stack B.
/// @return 0 if successful, 1 if an error occurs.
static int	handle_moves(t_stack **stack_a, t_stack **stack_b)
{
	if (process_moves(stack_a, stack_b))
	{
		free_all(stack_a);
		free_all(stack_b);
		return (1);
	}
	if (*stack_b)
	{
		free_all(stack_a);
		free_all(stack_b);
		return (write(2, "KO\n", 3), 1);
	}
	return (0);
}

/// @brief Checks if the stack is sorted and frees the stacks.
/// @param stack_a Pointer to stack A.
/// @return 0 if stack is sorted, 1 if not.
static int	check_and_cleanup(t_stack **stack_a)
{
	if (sort_checker(stack_a))
	{
		free_all(stack_a);
		return (ft_printf("KO\n"), 1);
	}
	free_all(stack_a);
	ft_printf("OK\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (1);
	if (initialize_stacks(argc, argv, &stack_a))
		return (1);
	if (handle_moves(&stack_a, &stack_b))
		return (1);
	return (check_and_cleanup(&stack_a));
}
