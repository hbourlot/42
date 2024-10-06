/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:13:59 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/27 15:12:50 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

static char	*str_join(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2 && s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

/// @brief Reads and accumulates moves from standard input.
/// @param stack_a A pointer to stack A.
/// @param stack_b A pointer to stack B.
/// @return A string containing all the accumulated moves,
///		     or NULL if an error occurs.
static char	*read_and_accumulate_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	char	*src;

	src = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (check_movs(line, stack_a, stack_b))
		{
			free(line);
			free(src);
			return (NULL);
		}
		src = str_join(src, line);
		if (!src)
		{
			free(line);
			return (NULL);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	return (src);
}

/// @brief Processes and executes the accumulated moves.
/// @param stack_a A pointer to stack A.
/// @param stack_b A pointer to stack B.
/// @param moves A string containing the accumulated moves.
/// @return 0 if successful, 1 if an error occurs during execution.
static int	process_and_execute_moves(t_stack **stack_a, t_stack **stack_b,
		char *moves)
{
	if (execute_move(moves, stack_a, stack_b))
	{
		free(moves);
		return (write(1, "KO\n", 3), 1);
	}
	free(moves);
	return (0);
}

int	process_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*moves;

	moves = read_and_accumulate_moves(stack_a, stack_b);
	if (!moves)
	{
		if (!sort_checker(stack_a))
			return (write(1, "OK\n", 3));
		return (write(1, "KO\n", 3));
	}
	return (process_and_execute_moves(stack_a, stack_b, moves));
}
