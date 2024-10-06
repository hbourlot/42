/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:07:59 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 21:50:36 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Frees the memory and resources associated with the exit images.
/// @param game Pointer to the game structure.
static void	free_exit(t_game *game)
{
	if (game->exit.open.img)
	{
		mlx_destroy_image(game->mlx_ptr, game->exit.open.img);
		game->exit.open.img = NULL;
	}
	if (game->exit.closed.img)
	{
		mlx_destroy_image(game->mlx_ptr, game->exit.closed.img);
		game->exit.closed.img = NULL;
	}
}

/// @brief Frees resources for the game and handles error
/// messages before exiting.
/// @param game Pointer to the game structure.
/// @param error_msg Pointer to the error message string.
static void	free_game(t_game *game, const char *error_msg)
{
	if (game->mlx_win)
	{
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		game->mlx_win = NULL;
	}
	if (error_msg)
		write(1, error_msg, ft_strlen(error_msg));
	mlx_loop_end(game->mlx_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
}

void	close_game(t_game *game, const char *error_msg, int state)
{
	free_exit(game);
	free_coin(game);
	free_ghosts(game);
	free_map(game);
	free_player(game);
	free_game(game, error_msg);
	if (state)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

int	ft_close_x(t_game *game)
{
	close_game(game, NULL, 0);
	return (0);
}

void	free_window(t_game *game)
{
	if (game)
	{
		if (game->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
			game->mlx_ptr = NULL;
		}
		if (game->map.map_grid)
			free_split(game->map.map_grid);
		free_exit(game);
		free_coin(game);
		free_player(game);
		free_ghosts(game);
	}
}
