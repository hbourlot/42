/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:44:19 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/27 08:16:35 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Frees the resources associated with the player’s dying sprites.
/// This includes all sprite images related to the player's dying animation.
/// @param game The game structure containing player sprite information.
static void	free_player_dying_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (game->pac_dying[i].img)
		{
			mlx_destroy_image(game->mlx_ptr, game->pac_dying[i].img);
			game->pac_dying[i].img = NULL;
		}
		i++;
	}
}

void	free_player(t_game *game)
{
	int	dir;
	int	state;

	dir = 0;
	while (dir < 4)
	{
		state = 0;
		while (state < 3)
		{
			if (game->player.sprites[dir][state].img)
			{
				mlx_destroy_image(game->mlx_ptr,
					game->player.sprites[dir][state].img);
				game->player.sprites[dir][state].img = NULL;
			}
			state++;
		}
		dir++;
	}
	free_player_dying_sprites(game);
}
