/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_ghost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:12:42 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 22:05:35 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Checks if the ghost is at an intersection
/// (more than two possible exits).
/// @param map Pointer to the map structure containing the grid.
/// @param ghost Pointer to the ghost structure to check.
/// @return Returns 1 if the ghost is at an intersection, otherwise 0.
static int	is_ghost_at_intersection(t_map *map, t_ghost *ghost)
{
	int			i;
	const int	movement_vectors[DIR_COUNT][2] = {{-1, 0}, {1, 0}, {0, -1}, {0,
		1}};
	int			pos_x;
	int			pos_y;
	int			exit;

	exit = 0;
	i = 0;
	if (ghost->pos_x % 32 == 0 && ghost->pos_y % 32 == 0)
	{
		while (i < DIR_COUNT)
		{
			pos_x = movement_vectors[i][0] + (ghost->pos_x / BLOCK_SIZE);
			pos_y = movement_vectors[i][1] + (ghost->pos_y / BLOCK_SIZE);
			if (map->map_grid[pos_y][pos_x] == '0')
				exit++;
			i++;
		}
	}
	if (exit > 2)
		return (1);
	return (0);
}

void	switch_scatter_chase(t_ghost *gh)
{
	if (gh->alive)
	{
		gh->mode_timer--;
		if (gh->mode_timer == 0)
		{
			if (gh->mode == CHASE)
			{
				gh->mode = SCATTER;
				gh->mode_timer = SCATTER_TIMER;
			}
			else if (gh->mode == SCATTER)
			{
				gh->mode = CHASE;
				gh->mode_timer = CHASE_TIMER;
			}
			else if (gh->mode == FRIGHTENED)
			{
				gh->mode = CHASE;
				gh->mode_timer = CHASE_TIMER;
			}
			gh->swap_mode = true;
		}
	}
}

int	ai_ghost(t_game *game)
{
	t_ghost	*ghost;

	ghost = game->ghost;
	while (ghost)
	{
		manage_ghost_behavior(game, ghost);
		if (is_ghost_at_intersection(&game->map, ghost) || ghost->cal_route)
		{
			init_logic(game, ghost);
			ghost->path = cal_route(game, ghost);
			if (!ghost->path)
				close_game(game, "Error cal_route\n", 1);
			remake_path(&ghost->path);
		}
		move_ghost(ghost, game, ghost->path);
		ghost = ghost->next;
	}
	return (0);
}
