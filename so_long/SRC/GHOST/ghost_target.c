/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:47:05 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/19 08:39:31 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static void	set_chase_target(t_game *game, t_ghost *gh)
{
	int			target_y;
	int			target_x;

	if (gh->mode == CHASE)
	{
		target_x = game->player.pos_x / BLOCK_SIZE;
		target_y = game->player.pos_y / BLOCK_SIZE;
		gh->ai_ghost.target = &gh->ai_ghost.map_nodes[target_y][target_x];
	}
}

static void	set_scatter_target(t_game *game, t_ghost *gh)
{
	int	map_h;
	int	map_w;

	map_h = game->map.height;
	map_w = game->map.width;
	if (gh->mode == SCATTER)
	{
		if (gh->id == BLINKY)
			gh->ai_ghost.target = &gh->ai_ghost.map_nodes[0][map_w - 1];
		else if (gh->id == PINKY)
			gh->ai_ghost.target = &gh->ai_ghost.map_nodes[0][0];
		else if (gh->id == INKY)
			gh->ai_ghost.target = &gh->ai_ghost.map_nodes[map_h - 1][map_w - 1];
		else if (gh->id == CLYDE)
			gh->ai_ghost.target = &gh->ai_ghost.map_nodes[map_h - 1][0];
	}
}

static void	set_frightened_target(t_ghost *gh)
{
	int	map_x;
	int	map_y;

	if (gh->mode == FRIGHTENED)
	{
		map_x = gh->start_x / BLOCK_SIZE;
		map_y = gh->start_y / BLOCK_SIZE;
		gh->ai_ghost.target = &gh->ai_ghost.map_nodes[map_y][map_x];
	}
}

void	select_ghost_target(t_game *game, t_ghost *ghost)
{
	set_scatter_target(game, ghost);
	set_chase_target(game, ghost);
	set_frightened_target(ghost);
}
