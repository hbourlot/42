/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_aighost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:35:55 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/19 08:37:36 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

int	malloc_ghost_logic_nodes(t_game *game, int width, int height)
{
	int		i;
	t_ghost	*ghost;

	ghost = game->ghost;
	while (ghost)
	{
		ghost->ai_ghost.map_nodes = malloc(height * sizeof(t_node *));
		if (!ghost->ai_ghost.map_nodes)
			return (-1);
		i = -1;
		while (++i < height)
		{
			ghost->ai_ghost.map_nodes[i] = malloc(width * sizeof(t_node));
			if (!ghost->ai_ghost.map_nodes[i])
			{
				while (--i >= 0)
					free(ghost->ai_ghost.map_nodes[i]);
				free(ghost->ai_ghost.map_nodes);
				return (-1);
			}
		}
		ghost = ghost->next;
	}
	return (0);
}

static void	init_opposite(t_game *game, t_ghost *gh)
{
	int			x;
	int			y;
	const int	opposite_direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	x = (gh->pos_x / BLOCK_SIZE) + opposite_direction[gh->direction][0];
	y = (gh->pos_y / BLOCK_SIZE) + opposite_direction[gh->direction][1];
	if (x >= 0 && x < game->map.width && y >= 0 && y < game->map.height)
		gh->ai_ghost.map_nodes[y][x].visited = true;
	gh->swap_mode = false;
}

static void	init_front(t_ghost *gh)
{
	int			x;
	int			y;
	const int	direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	x = (gh->pos_x / BLOCK_SIZE) + direction[gh->direction][0];
	y = (gh->pos_y / BLOCK_SIZE) + direction[gh->direction][1];
	gh->ai_ghost.map_nodes[y][x].visited = true;
	gh->swap_mode = false;
}

void	init_nodes(t_game *game, t_ghost *gh)
{
	int			i;
	int			j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			gh->ai_ghost.map_nodes[i][j].distance = __INT_MAX__;
			gh->ai_ghost.map_nodes[i][j].visited = false;
			gh->ai_ghost.map_nodes[i][j].x = j;
			gh->ai_ghost.map_nodes[i][j].y = i;
			gh->ai_ghost.map_nodes[i][j].prev = NULL;
			gh->ai_ghost.map_nodes[i][j].next = NULL;
		}
	}
	if (gh->mode == SCATTER && gh->swap_mode)
		init_opposite(game, gh);
	if (gh->mode == FRIGHTENED && gh->swap_mode)
		init_front(gh);
}

void	init_logic(t_game *game, t_ghost *ghost)
{
	t_logic_ghost	*ai_logic;
	t_node			**map_nodes;

	ai_logic = &ghost->ai_ghost;
	map_nodes = ghost->ai_ghost.map_nodes;
	ai_logic->start = &map_nodes[ghost->pos_y / 32][ghost->pos_x / 32];
	ai_logic->current = NULL;
	ai_logic->prev = NULL;
	ai_logic->next = NULL;
	ai_logic->start->distance = 0;
	init_nodes(game, ghost);
}
