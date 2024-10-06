/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_ghost_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:48:01 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/19 08:39:51 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Checks if the ghost's movement to a new position is valid.
/// @param game Pointer to the game structure.
/// @param ghost Pointer to the ghost structure.
/// @param new_w New x-coordinate of the move.
/// @param new_y New y-coordinate of the move.
/// @return Returns 1 if the move is valid, 0 otherwise.
static int	is_valid_move(t_game *game, t_ghost *ghost, int new_w, int new_y)
{
	t_node		**map_nodes;
	t_node		**next;

	next = &ghost->ai_ghost.next;
	map_nodes = ghost->ai_ghost.map_nodes;
	if (new_w < 0 || new_w >= game->map.width || new_y < 0
		|| new_y >= game->map.height)
		return (0);
	*next = &map_nodes[new_y][new_w];
	if (game->map.map_grid[new_y][new_w] == '1' || (*next)->visited)
		return (0);
	return (1);
}

/// @brief Processes and evaluates the next move for the ghost AI.
/// @param game Pointer to the game structure.
/// @param ghost Pointer to the ghost structure.
/// @param ai_ghost Pointer to the AI logic structure for the ghost.
/// @param pq Pointer to the priority queue structure.
static void	process_next(t_game *game, t_ghost *ghost, t_logic_ghost *ai_ghost,
		t_queue_node **pq)
{
	int			i;
	int			new_x;
	int			new_y;
	int			new_dist;
	const int	direction[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

	i = 0;
	while (i < 4)
	{
		new_x = ai_ghost->current->x + direction[i][0];
		new_y = ai_ghost->current->y + direction[i][1];
		if (is_valid_move(game, ghost, new_x, new_y))
		{
			new_dist = ai_ghost->current->distance + 1;
			if (new_dist < ai_ghost->next->distance)
			{
				ai_ghost->next->distance = new_dist;
				ai_ghost->next->prev = ai_ghost->current;
				enqueue(pq, ai_ghost->next);
			}
		}
		i++;
	}
}

/// @brief Handles the ghost moving around corners or dead ends
/// by checking possible directions.
/// @param game Pointer to the game structure.
/// @param ghost Pointer to the ghost structure.
/// @param pq Pointer to the priority queue structure.
/// @return Returns the next valid node for movement.
static t_node	*loop_around_corner(t_game *game, t_ghost *ghost,
		t_queue_node **pq)
{
	int				new_x;
	int				new_y;
	t_logic_ghost	*ai_ghost;
	int				step;
	const int		directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

	ai_ghost = &ghost->ai_ghost;
	step = 0;
	while (step < 4)
	{
		new_x = ai_ghost->current->x + directions[step][0];
		new_y = ai_ghost->current->y + directions[step][1];
		if (is_valid_move(game, ghost, new_x, new_y))
		{
			ai_ghost->next = &ai_ghost->map_nodes[new_y][new_x];
			ai_ghost->next->prev = ai_ghost->current;
			return (ai_ghost->next);
		}
		free_priority_queue(pq);
		step = (step + 1) % 5;
	}
	free_priority_queue(pq);
	return (ai_ghost->current);
}

/// @brief Checks if the ghost's current position is near its target
/// based on a threshold distance.
/// @param ai_ghost Pointer to the AI logic structure for the ghost.
/// @param ghost Pointer to the ghost structure.
/// @param threshold Distance threshold to determine proximity.
/// @return Returns 1 if the ghost is near its target, 0 otherwise.
static int	is_near_target(t_logic_ghost *ai_ghost, int threshold)
{
	int	dist_x;
	int	dist_y;

	if (ai_ghost->current && ai_ghost->target)
	{
		dist_x = abs(ai_ghost->current->x - ai_ghost->target->x);
		dist_y = abs(ai_ghost->current->y - ai_ghost->target->y);
		return (dist_x <= threshold && dist_y <= threshold);
	}
	return (0);
}

t_node	*cal_route(t_game *game, t_ghost *ghost)
{
	t_logic_ghost	*ai_ghost;
	t_queue_node	*priority_queue;

	ai_ghost = &ghost->ai_ghost;
	priority_queue = NULL;
	if (enqueue(&priority_queue, ai_ghost->start))
		return (NULL);
	while (priority_queue)
	{
		ai_ghost->current = dequeue(&priority_queue);
		if (ai_ghost->current->visited)
			continue ;
		ai_ghost->current->visited = true;
		if (ghost->mode == SCATTER && is_near_target(ai_ghost, 1))
			return (loop_around_corner(game, ghost, &priority_queue));
		if (ai_ghost->current == ai_ghost->target)
		{
			free_priority_queue(&priority_queue);
			break ;
		}
		process_next(game, ghost, ai_ghost, &priority_queue);
	}
	return (ai_ghost->current);
}
