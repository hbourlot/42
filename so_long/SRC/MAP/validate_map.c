/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:15:50 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 21:30:39 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Frees a 2D array of `bool` values.
/// @param visited The 2D array to be freed.
/// @param rows The number of rows in the array.
static void	free_map_bool(bool **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

/// @brief Performs a flood fill algorithm to mark reachable areas on
/// the map starting from a specific point.
/// @param game Contains map and game state.
/// @param x The starting x-coordinate for the flood fill.
/// @param y The starting y-coordinate for the flood fill.
/// @param map_visited 2D array to keep track of visited cells.
/// @return Always returns 0.
static int	flood_fill(t_game *game, int x, int y, bool **map_visited)
{
	if (x < 0 || y < 0 || y >= game->map.height
		|| x >= (int)ft_strlen(game->map.map_grid[y])
		|| game->map.map_grid[y][x] == '1' || map_visited[y][x])
		return (0);
	map_visited[y][x] = true;
	flood_fill(game, x + 1, y, map_visited);
	flood_fill(game, x - 1, y, map_visited);
	flood_fill(game, x, y + 1, map_visited);
	flood_fill(game, x, y - 1, map_visited);
	return (0);
}

/// @brief Allocates and initializes a 2D array of `bool`
/// values to track visited cells.
/// @param map Contains map dimensions.
/// @return Pointer to the allocated 2D array or NULL if allocation fails.
static bool	**allocate_visited(t_map *map)
{
	bool	**visited;
	int		rows;
	int		i;

	i = 0;
	visited = malloc(map->height * sizeof(bool *));
	if (!visited)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	while (i < map->height)
	{
		rows = ft_strlen(map->map_grid[i]);
		visited[i] = malloc(rows * sizeof(bool));
		if (!visited[i])
		{
			free_map_bool(visited, i);
			return (NULL);
		}
		ft_memset(visited[i], 0, rows * sizeof(bool));
		i++;
	}
	return (visited);
}

/// @brief Checks if all important locations (player, exit,
///	and coins) are reachable from the player's starting position.
/// @param game Contains map, player, and coin information.
/// @param map_visited 2D array indicating reachable cells.
/// @return 0 if all locations are reachable, 1 otherwise.
static int	check_path_reachability(t_game *game, bool **map_visited)
{
	t_coin	*coin;

	coin = game->coin;
	flood_fill(game, game->player.pos_x / 32, game->player.pos_y / 32,
		map_visited);
	if (!map_visited[game->exit.pos_y / 32][game->exit.pos_x / 32])
	{
		fprintf(stderr, "No path found from the player to the exit\n");
		return (1);
	}
	while (coin)
	{
		if (coin->pos_x > 0 && coin->pos_x > 0 && !map_visited[coin->pos_y
				/ 32][coin->pos_x / 32])
		{
			fprintf(stderr,
				"No path found from the player to coin at [%d][%d]\n",
				coin->pos_x, coin->pos_y);
			return (1);
		}
		coin = coin->next;
	}
	return (0);
}

int	is_invalid_map(t_game *game)
{
	bool	**map_visited;

	if (!is_surrounded_by_walls(game->map.map_grid))
	{
		fprintf(stderr, "Map isn't surrounded by walls!");
		return (1);
	}
	if (is_invalid_format(&game->map))
		return (1);
	map_visited = allocate_visited(&game->map);
	if (!map_visited)
		return (1);
	if (check_letter(&game->map))
	{
		free_map_bool(map_visited, game->map.height);
		return (1);
	}
	if (check_path_reachability(game, map_visited))
	{
		free_map_bool(map_visited, game->map.height);
		return (1);
	}
	free_map_bool(map_visited, game->map.height);
	return (0);
}
