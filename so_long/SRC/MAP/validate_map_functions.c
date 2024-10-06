/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:05:41 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 17:12:17 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

int	is_surrounded_by_walls(char **map)
{
	int	i;
	int	len;
	int	last_row;

	i = 0;
	while (map[0][i])
		if (map[0][i++] != '1')
			return (0);
	last_row = 0;
	while (map[last_row])
		last_row++;
	last_row--;
	i = 0;
	while (map[last_row][i])
		if (map[last_row][i++] != '1')
			return (0);
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

/// @brief Processes a row of the map to count players and exits,
///	and checks for invalid characters.
/// @param row The row of the map to process.
/// @param n_player Pointer to count of players found.
/// @param n_exit Pointer to count of exits found.
/// @return 1 if there is an invalid character, 0 otherwise.
static int	process_map_row(char *row, int *n_player, int *n_exit)
{
	int		x;
	char	c;

	x = 0;
	while (row[x])
	{
		c = row[x];
		if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P'
			&& c != 'G')
		{
			perror("Invalid character");
			return (1);
		}
		*n_player += (c == 'P');
		*n_exit += (c == 'E');
		x++;
	}
	return (0);
}

int	check_letter(t_map *map)
{
	int	y;
	int	n_player;
	int	n_exit;

	y = 0;
	n_player = 0;
	n_exit = 0;
	while (map->map_grid[y])
	{
		if (process_map_row(map->map_grid[y], &n_player, &n_exit))
			return (1);
		y++;
	}
	if (n_player != 1 || n_exit != 1)
		return (perror("Missing or extra number of player || exit"), 1);
	return (0);
}

int	is_invalid_format(t_map *map)
{
	int		x;
	int		y;
	char	**tmp;

	y = 0;
	tmp = map->map_grid;
	while (tmp[y])
	{
		x = 0;
		while (tmp[y][x])
			x++;
		if (x != map->width)
		{
			perror("Invalid map format (square map)");
			return (1);
		}
		y++;
	}
	return (0);
}
