/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:23:02 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/27 14:59:18 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

int	check_movs(char *line, t_stack **stack_a, t_stack **stack_b)
{
	int			i;
	int			invalid;
	const char	*opt[] = {"ra\n", "rra\n", "rr\n", "rb\n", "rrb\n", "rrr\n",
		"pa\n", "pb\n", "sa\n", "ss\n", "sb\n", NULL};

	invalid = 1;
	i = 0;
	while (opt[i])
	{
		if (ft_strcmp((const char *)line, opt[i]) == 0)
			invalid = 0;
		i++;
	}
	if (invalid)
		return (1);
	return (invalid);
}
