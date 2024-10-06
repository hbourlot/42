/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:24:54 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/26 20:48:04 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Draws the background of the game window based on the map grid.
/// This includes drawing walls and empty spaces or exits.
/// @param game The game structure containing map and sprite information.
/// @return Always returns 0.
static void	draw_back_ground(t_game *game)
{
	int		x;
	int		y;
	char	**map_grid;

	y = 0;
	map_grid = game->map.map_grid;
	while (y < game->map.height)
	{
		x = 0;
		while (map_grid[y][x])
		{
			if (map_grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->map.sprite_wall.img, x * game->map.sprite_wall.size_x,
					y * game->map.sprite_wall.size_y);
			x++;
		}
		y++;
	}
	draw_layout(game);
}

/// @brief The main game loop function. Updates game state and
/// redraws the screen.
/// This includes handling automatic moves, drawing counters, exits, coins,
///	ghosts, and the player.
/// @param game The game structure containing all relevant data.
/// @return Always returns 0.
static int	loop_game(t_game *game)
{
	if (game->player.dead)
		draw_pac_man_dead(game);
	else
	{
		if (automatic_moves_player(game))
			draw_counter(game);
		draw_exit(game);
		ai_ghost(game);
		draw_coin(game);
		draw_ghost(game);
		draw_player(game);
		my_usleep(10000000 / FRAME_RATE);
	}
	return (0);
}

/// @brief Handles key press events. Updates player movement direction
/// and handles special keys.
/// @param keycode The key code of the pressed key.
///	@param game The game structure containing player and control information.
///	@return Always returns 0.
static int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_a || keycode == XK_Left)
		game->player.attempt_mov = DIR_LEFT;
	else if (keycode == XK_d || keycode == XK_Right)
		game->player.attempt_mov = DIR_RIGHT;
	else if (keycode == XK_w || keycode == XK_Up)
		game->player.attempt_mov = DIR_UP;
	else if (keycode == XK_s || keycode == XK_Down)
		game->player.attempt_mov = DIR_DOWN;
	if (keycode == XK_Escape)
	{
		ft_printf("You pressed %d (Esc)\n\n", keycode);
		close_game(game, NULL, 0);
	}
	return (0);
}

int	initialize_game_loop(t_game *game)
{
	load_all_sprites(game);
	draw_back_ground(game);
	mlx_hook(game->mlx_win, DestroyNotify, NoEventMask, ft_close_x, game);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, key_press, game);
	mlx_loop_hook(game->mlx_ptr, loop_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
