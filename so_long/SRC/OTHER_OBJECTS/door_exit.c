/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:51:51 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 21:49:17 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"
#include "stdlib.h"

/// @brief Checks if the player has reached the exit and closes
/// the game with a win message if so.
/// @param game The game structure containing player and
/// exit information.
static void	exit_game_in_exit(t_game *game)
{
	t_player	*p;
	t_exit		*e;

	p = &game->player;
	e = &game->exit;
	if (p->pos_x == e->pos_x && p->pos_y == e->pos_y)
		close_game(game, "--> You Won!! <--\n", 0);
}

void	draw_exit(t_game *game)
{
	t_coin	*coin;
	t_exit	*exit;

	coin = game->coin;
	exit = &game->exit;
	while (coin)
	{
		if (coin->removed == false)
		{
			draw_obj(&exit->closed, exit->pos_x, exit->pos_y);
			return ;
		}
		coin = coin->next;
	}
	draw_obj(&exit->open, exit->pos_x, exit->pos_y);
	exit_game_in_exit(game);
}
