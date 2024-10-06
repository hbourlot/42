/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_ghost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:38:59 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/19 08:41:27 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Sets the ghost's direction based on the next node in the path.
/// @param path Pointer to the current path node.
/// @param ghost Pointer to the ghost structure to update.
static void	set_direction(t_node **path, t_ghost *gh)
{
	int	x;
	int	y;
	int	p_x;
	int	p_y;

	x = gh->pos_x;
	y = gh->pos_y;
	p_x = (*path)->x * BLOCK_SIZE;
	p_y = (*path)->y * BLOCK_SIZE;
	if (x < p_x && y == p_y)
		gh->direction = DIR_RIGHT;
	else if (x > p_x && y == p_y)
		gh->direction = DIR_LEFT;
	else if (y < p_y && x == p_x)
		gh->direction = DIR_DOWN;
	else if (y > p_y && x == p_x)
		gh->direction = DIR_UP;
}

static void	init_ghost_object(t_game *game, t_ghost *gh)
{
	gh->object.pos_x = gh->pos_x;
	gh->object.pos_y = gh->pos_y;
	gh->object.speed = 1;
	gh->object.map = &game->map;
	if (gh->mode == EYES && gh->pos_x % 2 == 0 && gh->pos_y % 2 == 0)
		gh->object.speed = 2;
	else
		gh->object.speed = 1;
}

void	move_ghost(t_ghost *gh, t_game *game, t_node *path)
{
	int	new_pos[2];

	if (!is_in_tile(gh->pos_x, gh->pos_y, BLOCK_SIZE))
		set_direction(&path, gh);
	else if ((path->x * BLOCK_SIZE == gh->pos_x && path->y
			* BLOCK_SIZE == gh->pos_y) || gh->cal_route)
	{
		if (path->next)
			path = path->next;
		else
		{
			gh->cal_route = true;
			return ;
		}
	}
	set_direction(&path, gh);
	init_ghost_object(game, gh);
	if (!is_collision(&gh->object, gh->direction, new_pos))
	{
		gh->pos_x += new_pos[0];
		gh->pos_y += new_pos[1];
	}
	gh->cal_route = false;
	gh->path = path;
}
