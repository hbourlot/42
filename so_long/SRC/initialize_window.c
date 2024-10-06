/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:48:55 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/27 08:16:18 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Opens the map file, loads the map grid, and
/// processes the map layout.
/// @param game The game structure containing map information.
/// @return 0 on success, 1 on failure.
static int	initialize_map(t_game *game)
{
	int	fd;

	fd = open(game->map.path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	game->map.map_grid = load_grid_map(fd);
	close(fd);
	if (game->map.map_grid == NULL)
	{
		perror("Error on initialize_map function (map_grid == NULL)");
		return (1);
	}
	if (process_map_layout(game))
		return (1);
	if (is_invalid_map(game))
		return (1);
	return (0);
}

/// @brief Initializes the graphics environment and creates a new window.
/// @param game The game structure for managing graphics.
/// @return 0 on success, 1 on failure.
static int	initialize_graphics(t_game *game)
{
	int	extra_map;

	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (1);
	extra_map = 12;
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->map.width * BLOCK_SIZE,
			(game->map.height * BLOCK_SIZE + LAYOUT) + extra_map, "PacMan");
	if (!game->mlx_win)
		return (1);
	return (0);
}

static int	check_ber_end(t_game *game)
{
	char		*path;
	int			len;
	const char	end[] = ".ber";
	const char	error[] = "Map doesn't end with '.ber'\n";

	path = game->map.path;
	len = (int)ft_strlen(path);
	if (len >= 4)
	{
		if (ft_strcmp(path + (len - 4), end))
		{
			write(2, error, ft_strlen(error));
			return (1);
		}
	}
	return (0);
}

int	initialize_window(t_game *game)
{
	if (check_ber_end(game))
		return (1);
	if (initialize_map(game) || initialize_graphics(game))
	{
		free_window(game);
		return (1);
	}
	if (malloc_ghost_logic_nodes(game, game->map.width, game->map.height))
	{
		close_game(game, "Error malloc ghost_logic_nodes\n", 1);
		return (1);
	}
	return (0);
}
