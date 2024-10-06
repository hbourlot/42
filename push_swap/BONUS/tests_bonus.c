/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:56:06 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/24 21:59:58 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

static int	apply_swap_moves(char *move, t_stack **stack_a, t_stack **stack_b)
{
	const char	*opt[] = {"sb\n", "ss\n", NULL};
	int			i;

	i = 0;
	while (opt[i])
	{
		if (ft_strcmp(opt[i], move) == 0)
		{
			if (i == 0 && ft_swap(stack_b, ""))
				return (1);
			if (i == 1 && (ft_swap(stack_a, "") || ft_swap(stack_b, "")))
				return (1);
		}
		i++;
	}
	return (0);
}

static int	apply_stack_a_moves(char *move, t_stack **stack_a,
		t_stack **stack_b)
{
	const char	*opt[] = {"ra\n", "rra\n", "rr\n", "pb\n", "sa\n", NULL};
	int			i;

	i = 0;
	while (opt[i])
	{
		if (ft_strcmp(opt[i], move) == 0)
		{
			if (i == 0 && ft_shift_up(stack_a, ""))
				return (1);
			else if (i == 1 && ft_shift_down(stack_a, ""))
				return (1);
			else if (i == 2 && (ft_shift_up(stack_a, "") || ft_shift_up(stack_b,
						"")))
				return (1);
			else if (i == 3 && ft_push(stack_a, stack_b, ""))
				return (1);
			else if (i == 4 && ft_swap(stack_a, ""))
				return (1);
		}
		i++;
	}
	return (0);
}

static int	apply_stack_b_moves(char *move, t_stack **stack_a,
		t_stack **stack_b)
{
	const char	*opt[] = {"rb\n", "rrb\n", "rrr\n", "pa\n", NULL};
	int			i;

	i = 0;
	while (opt[i])
	{
		if (ft_strcmp(opt[i], move) == 0)
		{
			if (i == 0 && ft_shift_up(stack_b, ""))
				return (1);
			if (i == 1 && ft_shift_down(stack_b, ""))
				return (1);
			if (i == 2 && (ft_shift_down(stack_a, "") || ft_shift_down(stack_b,
						"")))
				return (1);
			if (i == 3 && ft_push(stack_b, stack_a, ""))
				return (1);
		}
		i++;
	}
	return (0);
}

int	execute_move(char *src, t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	char	char_tmp;
	int		line_start;

	i = 0;
	line_start = 0;
	while (src[i])
	{
		if (src[i] == '\n' || src[i + 1] == '\0')
		{
			char_tmp = src[i + 1];
			src[i + 1] = '\0';
			if (apply_swap_moves(&src[line_start], stack_a, stack_b)
				|| apply_stack_a_moves(&src[line_start], stack_a, stack_b)
				|| apply_stack_b_moves(&src[line_start], stack_a, stack_b))
				return (1);
			src[i + 1] = char_tmp;
			line_start = i + 1;
		}
		i++;
	}
	return (0);
}
