/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:41:02 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/20 17:18:46 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (game->counter.sprites[i].img)
		{
			mlx_destroy_image(game->mlx_ptr, game->counter.sprites[i].img);
			game->counter.sprites[i].img = NULL;
		}
		i++;
	}
	if (game->map.sprite_black.img)
		mlx_destroy_image(game->mlx_ptr, game->map.sprite_black.img);
	if (game->map.sprite_star.img)
		mlx_destroy_image(game->mlx_ptr, game->map.sprite_star.img);
	if (game->map.sprite_wall.img)
		mlx_destroy_image(game->mlx_ptr, game->map.sprite_wall.img);
	if (game->map.layout.img)
		mlx_destroy_image(game->mlx_ptr, game->map.layout.img);
	if (game->map.map_grid)
	{
		free_split(game->map.map_grid);
		game->map.map_grid = NULL;
	}
}
