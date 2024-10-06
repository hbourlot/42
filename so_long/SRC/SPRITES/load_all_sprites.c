/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_all_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:31:36 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/19 08:32:08 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Loads numbered sprites (0-9) for a given counter.
/// @param game The game structure where sprites are added.
/// @param sprite_path Path prefix for the sprites.
/// @param c The counter structure to which sprites are added.
static void	load_counter_sprites(t_game *game, const char *sprite_path,
		t_counter *c)
{
	int			i;
	char		sprite_file[256];
	char		number[2];
	const char	*suffix = ".xpm";

	i = 0;
	while (i < 10)
	{
		sprite_file[0] = '\0';
		number[1] = '\0';
		number[0] = '0' + i;
		ft_strcpy(sprite_file, sprite_path);
		ft_strcat(sprite_file, number);
		ft_strcat(sprite_file, suffix);
		creat_sprite(game, sprite_file, &c->sprites[i]);
		i++;
	}
}

/// @brief Loads sprites for coins and exit objects in the game.
/// @param game The game structure where sprites are added.
static void	load_coin_exit_sprites(t_game *game)
{
	t_coin	*coin;

	coin = game->coin;
	creat_sprite(game, "assets/exit/door1.xpm", &game->exit.closed);
	creat_sprite(game, "assets/exit/door2.xpm", &game->exit.open);
	creat_sprite(game, "assets/collectible/red_star.xpm",
		&game->coin_sprites[RED]);
	creat_sprite(game, "assets/collectible/yellow_star.xpm",
		&game->coin_sprites[YELLOW]);
	creat_sprite(game, "assets/collectible/green_star.xpm",
		&game->coin_sprites[GREEN]);
	if (game->coin)
	{
		while (coin)
		{
			coin->sprites = &game->coin_sprites;
			coin = coin->next;
		}
	}
}

/// @brief Loads map-related sprites for walls and paths.
/// @param game The game structure where sprites are added.
static void	load_map_sprites(t_game *game)
{
	creat_sprite(game, "assets/map/path_star.xpm", &game->map.sprite_star);
	creat_sprite(game, "assets/map/WALL.xpm", &game->map.sprite_wall);
	creat_sprite(game, "assets/map/path_black.xpm", &game->map.sprite_black);
}

void	load_all_sprites(t_game *game)
{
	load_map_sprites(game);
	load_player_sprites(game);
	load_coin_exit_sprites(game);
	load_ghost_sprites(game);
	load_counter_sprites(game, "assets/numbers/", &game->counter);
}

void	creat_sprite(t_game *game, const char *sprite, t_sprite *image)
{
	image->mlx_ptr = game->mlx_ptr;
	image->mlx_win = game->mlx_win;
	image->img = mlx_xpm_file_to_image(game->mlx_ptr, (char *)sprite,
			&image->size_x, &image->size_y);
	if (!image->img)
	{
		ft_printf("Sprite ->: '%s'\n", sprite);
		perror("Failed to load sprite\n");
		close_game(game, NULL, 1);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->size_line,
			&image->endian);
	if (!image->addr)
	{
		ft_printf("Sprite ->: '%s'\n", sprite);
		perror("Failed to get addr\n");
		close_game(game, NULL, 1);
	}
}
