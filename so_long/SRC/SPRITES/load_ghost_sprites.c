/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ghost_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:00:46 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 21:41:13 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Loads a single sprite for a ghost in a specified
/// direction and prefix.
/// @param game The game structure to which the sprite is added.
/// @param ghost_index Index of the ghost in the sprite array.
/// @param dir_index Index of the direction for the sprite.
/// @param prefix Path prefix for the sprite file.
static void	load_single_ghost_alive_sprite(t_game *game, int ghost_index,
		int dir_index, const char *prefix)
{
	const char	*suffix[] = {G_L1, G_L2, G_R1, G_R2, G_U1, G_U2, G_D1, G_D2};
	char		sprite[100];

	ft_bzero(sprite, sizeof(char) * 100);
	ft_strcat(sprite, prefix);
	ft_strcat(sprite, suffix[dir_index * 2]);
	creat_sprite(game, sprite,
		&game->ghost_alive_sprite[ghost_index][dir_index][0]);
	ft_bzero(sprite, sizeof(char) * 100);
	ft_strcat(sprite, prefix);
	ft_strcat(sprite, suffix[dir_index * 2 + 1]);
	creat_sprite(game, sprite,
		&game->ghost_alive_sprite[ghost_index][dir_index][1]);
	ft_bzero(sprite, sizeof(char) * 100);
}

/// @brief Loads the panic mode sprites for the ghosts.
/// @param game The game structure where the ghost panic
/// sprites will be stored.
static void	load_ghost_panic_sprite(t_game *game)
{
	const char	*suffix[] = {G_PANIC_BLUE1, G_PANIC_WHITE1, G_PANIC_BLUE2,
		G_PANIC_BLUE2};
	const char	prefix[] = "assets/ghost/PANIC/";
	char		sprite[100];
	int			i;

	i = 0;
	while (i < 4)
	{
		ft_bzero(&sprite, sizeof(sprite));
		ft_strcat(sprite, prefix);
		ft_strcat(sprite, suffix[i]);
		creat_sprite(game, sprite, &game->ghost_panic_sprite[i]);
		i++;
	}
}

/// @brief Assigns the proper sprite array to each ghost based on its index.
/// @param game The game structure containing ghosts and sprite arrays.
static void	assign_properly_sprite(t_game *game)
{
	t_ghost	*ghost;
	int		index;

	ghost = game->ghost;
	index = 0;
	while (ghost)
	{
		ghost->alive_sprite = &game->ghost_alive_sprite[index];
		ghost = ghost->next;
		index++;
		if (index >= GHOST_COUNT)
			index = 0;
	}
	ghost = game->ghost;
	while (ghost)
	{
		ghost->panic_sprite = &game->ghost_panic_sprite;
		ghost = ghost->next;
	}
}

static void	load_ghost_eyes_sprite(t_game *game)
{
	const char	prefix[] = G_EYES_PATH;
	const char	*suffix[] = {G_EYES_LEFT, G_EYES_RIGHT, G_EYES_UP, G_EYES_DOWN};
	int			i;
	char		sprite[100];
	t_ghost		*ghost;

	ghost = game->ghost;
	i = 0;
	while (i < 4)
	{
		ft_bzero(sprite, 100);
		ft_strcat(sprite, prefix);
		ft_strcat(sprite, suffix[i]);
		creat_sprite(game, sprite, &game->ghost_eyes_sprite[i]);
		i++;
	}
	i = 0;
	while (ghost)
	{
		ghost->eyes_sprite = &game->ghost_eyes_sprite;
		ghost = ghost->next;
	}
}

void	load_ghost_sprites(t_game *game)
{
	int			i;
	int			j;
	const char	*prefix[] = {PINKY_PATH, BLINKY_PATH, INKY_PATH, CLYDE_PATH};

	i = 0;
	while (i < GHOST_COUNT)
	{
		j = 0;
		while (j < DIR_COUNT)
		{
			load_single_ghost_alive_sprite(game, i, j, prefix[i]);
			j++;
		}
		i++;
	}
	load_ghost_panic_sprite(game);
	load_ghost_eyes_sprite(game);
	assign_properly_sprite(game);
}
