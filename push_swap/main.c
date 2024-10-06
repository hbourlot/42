/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:59:26 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/24 11:51:59 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lib_pushswap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (validate_input(argv))
			return (write(2, ERROR, 6));
		if (create_stack(&stack_a, argv))
			return (1);
		if (!sort_checker(&stack_a))
		{
			free_all(&stack_a);
			return (0);
		}
		algorithm(&stack_a, &stack_b);
	}
	return (0);
}
