/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_coin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:16:12 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/20 17:18:51 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Frees the resources associated with coin sprites.
/// @param game The game structure containing the coin sprite images.
static void	free_collectible_sprites(t_game *game)
{
	if (game->coin_sprites[RED].img)
	{
		mlx_destroy_image(game->mlx_ptr, game->coin_sprites[RED].img);
		game->coin_sprites[RED].img = NULL;
	}
	if (game->coin_sprites[YELLOW].img)
	{
		mlx_destroy_image(game->mlx_ptr, game->coin_sprites[YELLOW].img);
		game->coin_sprites[YELLOW].img = NULL;
	}
	if (game->coin_sprites[GREEN].img)
	{
		mlx_destroy_image(game->mlx_ptr, game->coin_sprites[GREEN].img);
		game->coin_sprites[GREEN].img = NULL;
	}
}

void	free_coin(t_game *game)
{
	t_coin	*coin;
	t_coin	*tmp;

	free_collectible_sprites(game);
	coin = game->coin;
	if (coin)
	{
		while (coin->next)
		{
			tmp = coin->next;
			free(coin);
			coin = tmp;
		}
		free(coin);
		game->coin = NULL;
	}
}
