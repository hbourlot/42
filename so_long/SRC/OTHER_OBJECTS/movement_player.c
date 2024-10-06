/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:08:06 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 21:36:30 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Erases the trail left by the player based on
/// movement direction and position.
/// @param game Pointer to the game structure containing
/// the map and player data.
/// @param x Horizontal movement offset (can be 0).
/// @param y Vertical movement offset (can be 0).
static void	erase_player_trail(t_game *game, int x, int y)
{
	t_player	player;
	int			pos_x;
	int			pos_y;
	int			offset;

	player = game->player;
	pos_y = player.pos_y + y;
	pos_x = player.pos_x + x;
	if (x != 0)
	{
		offset = pos_x % 32;
		if (x > 0 && offset >= 5 && offset <= 21)
			draw_obj(&game->map.sprite_black, (pos_x / 32) * 32 + 32, pos_y);
		else if (x < 0 && offset >= 5 && offset <= 26)
			draw_obj(&game->map.sprite_black, (pos_x / 32) * 32, pos_y);
	}
	else if (y != 0)
	{
		offset = pos_y % 32;
		if (y > 0 && offset >= 11 && offset <= 21)
			draw_obj(&game->map.sprite_black, pos_x, (pos_y / 32) * 32 + 32);
		else if (y < 0 && offset >= 11 && offset <= 21)
			draw_obj(&game->map.sprite_black, pos_x, (pos_y / 32) * 32);
	}
}

/// @brief Moves the player character if no collision is detected.
/// @param game Pointer to the game structure containing player
/// and map information.
/// @param movement Movement direction
/// (use direction constants like DIR_UP, DIR_DOWN, etc.).
/// @return Returns 1 if the character moved successfully,
///	0 if a collision occurred.
static int	move_character(t_game *game, int movement)
{
	int	new_pos[2];

	game->player.object.pos_x = game->player.pos_x;
	game->player.object.pos_y = game->player.pos_y;
	game->player.object.map = &game->map;
	game->player.object.speed = 2;
	if (!is_collision(&game->player.object, movement, new_pos))
	{
		game->player.pos_x += new_pos[0];
		game->player.pos_y += new_pos[1];
		game->player.direction = movement;
		erase_player_trail(game, new_pos[0], new_pos[1]);
		return (1);
	}
	return (0);
}

int	automatic_moves_player(t_game *game)
{
	static int	last_mov = -1;
	t_player	*pac_man;

	pac_man = &game->player;
	if (pac_man->attempt_mov != last_mov)
	{
		if (((pac_man->attempt_mov == DIR_RIGHT
					|| pac_man->attempt_mov == DIR_LEFT) && pac_man->pos_y
				% 32 == 0) || ((pac_man->attempt_mov == DIR_UP
					|| pac_man->attempt_mov == DIR_DOWN) && pac_man->pos_x
				% 32 == 0))
		{
			if (move_character(game, pac_man->attempt_mov))
			{
				last_mov = pac_man->attempt_mov;
				return (1);
			}
		}
	}
	if (last_mov != -1)
		move_character(game, pac_man->direction);
	return (0);
}
