/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:04:08 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/26 20:49:20 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static int	mini_esq_close(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		ft_printf("You pressed %d (Esc)\n\n", keycode);
		close_game(game, NULL, 0);
	}
	return (0);
}

int	draw_pac_man_dead(t_game *game)
{
	static int	phase = 0;
	static int	frame_counter = 0;
	int			frame_delay;

	frame_delay = 40 * FRAME_RATE;
	if (!game->player.pac_dying)
		return (ft_printf("Error: pac_dying not initialized.\n"), 1);
	if (frame_counter >= frame_delay)
	{
		frame_counter = 0;
		phase++;
	}
	if (phase >= 10)
	{
		close_game(game, "--> GAME OVER <--\n", 0);
		return (0);
	}
	draw_obj(&(*game->player.pac_dying)[phase], game->player.pos_x,
		game->player.pos_y);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, mini_esq_close, game);
	mlx_hook(game->mlx_win, DestroyNotify, NoEventMask, ft_close_x, game);
	frame_counter++;
	return (0);
}

/// @brief Draws the player sprite based on direction and frame state.
/// @param game The game structure containing player and game information.
/// @param direction The direction in which the player is moving (e.g., left,
///	right).
/// @param frame_state The current animation frame of the player (e.g., open,
///	semi-open, closed).
static void	draw_player_sprite(t_game *game, int dir, int f_s)
{
	t_player	*player;
	t_exit		*exit;

	exit = &game->exit;
	player = &game->player;
	player->object.pos_x = game->exit.pos_x;
	player->object.pos_y = game->exit.pos_y;
	if (game->player.attempt_mov == -1)
		draw_obj(&game->player.sprites[DIR_RIGHT][f_s], game->player.pos_x,
			game->player.pos_y);
	else
	{
		if (!is_upon_object(game->player.pos_x, game->player.pos_y, exit->pos_x,
				exit->pos_y))
			draw_obj(&game->player.sprites[dir][f_s], game->player.pos_x,
				game->player.pos_y);
		else
			draw_with_no_collision(&game->player.sprites[dir][f_s],
				game->player.pos_x, game->player.pos_y, &player->object);
	}
}

void	draw_player(t_game *game)
{
	static int	frame_rate = 0;
	int			frame_state;
	int			direction;

	direction = game->player.direction;
	frame_state = (frame_rate / 10) % 3;
	draw_player_sprite(game, direction, frame_state);
	frame_rate = (frame_rate + 1) % 40;
}
