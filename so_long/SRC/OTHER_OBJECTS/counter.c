/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:31:54 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 13:34:35 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Retrieves the sprite for a specific digit in a number.
/// @param counter The structure holding digit sprites.
/// @param number The number from which to extract the digit.
/// @param idx The index of the digit to retrieve (starting from the left).
/// @return The sprite corresponding to the specified digit.
static t_sprite	*get_nbr_in_idx(t_counter *counter, int number, int idx)
{
	int	value;
	int	digit;

	value = 100;
	while (idx > 0)
	{
		value /= 10;
		idx--;
	}
	digit = (number / value) % 10;
	return (&counter->sprites[digit]);
}

/// @brief Draws the number of moves the player has made on the screen.
/// @param game The game structure containing game and player information.
/// @return 0 on success.
static int	draw_count_moves(t_game *game)
{
	static int	counter = 1;
	int			y;
	int			x;
	t_sprite	*number;

	y = game->map.height * BLOCK_SIZE + 1;
	x = game->map.width * BLOCK_SIZE / 2;
	number = get_nbr_in_idx(&game->counter, counter, 2);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, number->img, x, y);
	number = get_nbr_in_idx(&game->counter, counter, 1);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, number->img, x - 10,
		y);
	number = get_nbr_in_idx(&game->counter, counter, 0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, number->img, x - 20,
		y);
	counter++;
	return (0);
}

int	draw_counter(t_game *game)
{
	static int	prev_mov = -1;

	if (game->player.direction != prev_mov)
	{
		prev_mov = game->player.direction;
		draw_count_moves(game);
		return (0);
	}
	return (1);
}
