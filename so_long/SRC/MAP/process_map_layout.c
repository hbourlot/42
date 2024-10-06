/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map_layout.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:06:21 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/20 17:21:13 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Handles different objects in the map and updates the game state.
/// @param game The game structure to update.
/// @param x The x position of the object in the map (in tiles).
/// @param y The y position of the object in the map (in tiles).
/// @param obj The character representing the object ('C', 'G', 'E', 'P').
/// @return 0 if successful, -1 if an error occurs.
static int	handle_object(t_game *game, int x, int y, char obj)
{
	if (obj == 'C')
	{
		if (coin_add_back(&game->coin, new_coin(x * BLOCK_SIZE, y
					* BLOCK_SIZE)))
			return (1);
	}
	else if (obj == 'G')
	{
		if (!ghost_add_back(&game->ghost, new_ghost(x * BLOCK_SIZE, y
					* BLOCK_SIZE)))
			return (1);
	}
	else if (obj == 'E')
	{
		game->exit.pos_x = x * BLOCK_SIZE;
		game->exit.pos_y = y * BLOCK_SIZE;
	}
	else if (obj == 'P')
	{
		game->player.pos_x = x * BLOCK_SIZE;
		game->player.pos_y = y * BLOCK_SIZE;
	}
	return (0);
}

/// @brief Parses a line of the map and handles objects found in that line.
/// @param game The game structure to update.
/// @param line The line of the map to parse.
/// @param y The y position of the line in the map (in tiles).
/// @return 0 if successful, -1 if an error occurs.
static int	get_obj_lct(t_game *game, char *line, int y)
{
	int	i;

	i = 0;
	while (line[i++])
	{
		if (line[i] == '\n')
			return (0);
		if (handle_object(game, i, y, line[i]) == -1)
			return (-1);
	}
	return (0);
}

int	process_map_layout(t_game *game)
{
	int	i;
	int	line;

	i = 0;
	while (game->map.map_grid[i])
	{
		line = ft_linelen(game->map.map_grid[i]);
		if (get_obj_lct(game, game->map.map_grid[i], i))
		{
			perror("Error in function get_obj_lct");
			return (1);
		}
		if (line * BLOCK_SIZE > game->map.width)
			game->map.width = line;
		i++;
	}
	game->map.height = i;
	return (0);
}
