/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:40:55 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 21:39:14 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

void	load_pac_dead_sprites(t_game *game)
{
	int			i;
	const char	*filenames[10] = {"assets/player_dying/dying1.xpm",
		"assets/player_dying/dying2.xpm", "assets/player_dying/dying3.xpm",
		"assets/player_dying/dying4.xpm", "assets/player_dying/dying5.xpm",
		"assets/player_dying/dying6.xpm", "assets/player_dying/dying7.xpm",
		"assets/player_dying/dying8.xpm", "assets/player_dying/dying9.xpm",
		"assets/player_dying/dying10.xpm"};

	i = 0;
	while (i < 10)
	{
		creat_sprite(game, filenames[i], &game->pac_dying[i]);
		i++;
	}
	game->player.pac_dying = &game->pac_dying;
}

void	load_player_sprites(t_game *game)
{
	t_player	*player;

	player = &game->player;
	creat_sprite(game, PAC_OPEN_RIGHT, &player->sprites[DIR_RIGHT][0]);
	creat_sprite(game, PAC_SEMI_RIGHT, &player->sprites[DIR_RIGHT][1]);
	creat_sprite(game, PAC_CLOSED, &player->sprites[DIR_RIGHT][2]);
	creat_sprite(game, PAC_OPEN_UP, &player->sprites[DIR_UP][0]);
	creat_sprite(game, PAC_SEMI_UP, &player->sprites[DIR_UP][1]);
	creat_sprite(game, PAC_CLOSED, &player->sprites[DIR_UP][2]);
	creat_sprite(game, PAC_OPEN_LEFT, &player->sprites[DIR_LEFT][0]);
	creat_sprite(game, PAC_SEMI_LEFT, &player->sprites[DIR_LEFT][1]);
	creat_sprite(game, PAC_CLOSED, &player->sprites[DIR_LEFT][2]);
	creat_sprite(game, PAC_OPEN_DOWN, &player->sprites[DIR_DOWN][0]);
	creat_sprite(game, PAC_SEMI_DOWN, &player->sprites[DIR_DOWN][1]);
	creat_sprite(game, PAC_CLOSED, &player->sprites[DIR_DOWN][2]);
	load_pac_dead_sprites(game);
}
