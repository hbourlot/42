/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ghost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:36:46 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 21:48:17 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static void	free_game_ghost_panic_eyes_sprites(t_game *game)
{
	if (game->ghost_panic_sprite[0].img)
		mlx_destroy_image(game->mlx_ptr, game->ghost_panic_sprite[0].img);
	if (game->ghost_panic_sprite[1].img)
		mlx_destroy_image(game->mlx_ptr, game->ghost_panic_sprite[1].img);
	if (game->ghost_panic_sprite[2].img)
		mlx_destroy_image(game->mlx_ptr, game->ghost_panic_sprite[2].img);
	if (game->ghost_panic_sprite[3].img)
		mlx_destroy_image(game->mlx_ptr, game->ghost_panic_sprite[3].img);
	if (game->ghost_eyes_sprite[0].img)
		mlx_destroy_image(game->mlx_ptr, game->ghost_eyes_sprite[0].img);
	if (game->ghost_eyes_sprite[1].img)
		mlx_destroy_image(game->mlx_ptr, game->ghost_eyes_sprite[1].img);
	if (game->ghost_eyes_sprite[2].img)
		mlx_destroy_image(game->mlx_ptr, game->ghost_eyes_sprite[2].img);
	if (game->ghost_eyes_sprite[3].img)
		mlx_destroy_image(game->mlx_ptr, game->ghost_eyes_sprite[3].img);
	ft_bzero(game->ghost_panic_sprite, sizeof(t_sprite) * 4);
	ft_bzero(game->ghost_eyes_sprite, sizeof(t_sprite) * 4);
}

static void	free_game_ghost_alive_sprites(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < GHOST_COUNT)
	{
		j = 0;
		while (j < DIR_COUNT)
		{
			if (game->ghost_alive_sprite[i][j][0].img)
			{
				mlx_destroy_image(game->mlx_ptr,
					game->ghost_alive_sprite[i][j][0].img);
				game->ghost_alive_sprite[i][j][0].img = NULL;
			}
			if (game->ghost_alive_sprite[i][j][1].img)
			{
				mlx_destroy_image(game->mlx_ptr,
					game->ghost_alive_sprite[i][j][1].img);
				game->ghost_alive_sprite[i][j][1].img = NULL;
			}
			j++;
		}
		i++;
	}
}

/// @brief Frees the memory allocated for ghost logic nodes in each ghost's AI.
/// @param game The game structure containing the ghosts.
/// @param height The height of the map, used for freeing the map nodes.
static void	free_ghost_logic_nodes(t_game *game, int height)
{
	int		i;
	t_ghost	*ghost;

	ghost = game->ghost;
	while (ghost)
	{
		if (ghost->ai_ghost.map_nodes)
		{
			i = 0;
			while (i < height)
			{
				if (ghost->ai_ghost.map_nodes[i])
					free(ghost->ai_ghost.map_nodes[i]);
				i++;
			}
			free(ghost->ai_ghost.map_nodes);
			ghost->ai_ghost.map_nodes = NULL;
		}
		ghost = ghost->next;
	}
}

void	free_ghosts(t_game *game)
{
	t_ghost	*current_ghost;
	t_ghost	*next_ghost;

	free_game_ghost_alive_sprites(game);
	free_game_ghost_panic_eyes_sprites(game);
	current_ghost = game->ghost;
	free_ghost_logic_nodes(game, game->map.height);
	if (game->ghost_panic_sprite[0].img)
	{
		mlx_destroy_image(game->mlx_ptr, game->ghost_panic_sprite[0].img);
		mlx_destroy_image(game->mlx_ptr, game->ghost_panic_sprite[1].img);
		mlx_destroy_image(game->mlx_ptr, game->ghost_panic_sprite[2].img);
		mlx_destroy_image(game->mlx_ptr, game->ghost_panic_sprite[3].img);
		current_ghost->panic_sprite[0]->img = NULL;
		current_ghost->panic_sprite[1]->img = NULL;
		current_ghost->panic_sprite[2]->img = NULL;
		current_ghost->panic_sprite[3]->img = NULL;
	}
	while (current_ghost)
	{
		next_ghost = current_ghost->next;
		free(current_ghost);
		current_ghost = next_ghost;
	}
	game->ghost = NULL;
}

void	free_priority_queue(t_queue_node **pq)
{
	if (pq)
	{
		while (*pq)
			dequeue(pq);
	}
}
