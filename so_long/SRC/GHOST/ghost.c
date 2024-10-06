/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:21:35 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/19 08:36:09 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Detects if the player has collided with a ghost
/// and triggers the death sequence if necessary.
/// @param player Pointer to the player structure.
/// @param ghost Pointer to the ghost structure.
/// @param game Pointer to the game structure.
static void	detect_player_death(t_player *p, t_ghost *gh)
{
	bool	same_position;
	bool	neighboring_position;
	int		gh_x;
	int		gh_y;

	if (!gh->alive)
		return ;
	gh_x = gh->pos_x;
	gh_y = gh->pos_y;
	same_position = (p->pos_x == gh->pos_x && p->pos_y == gh->pos_y);
	neighboring_position = (p->pos_x >= gh_x && p->pos_x <= gh_x + BLOCK_SIZE
			- 6 && p->pos_y >= gh_y && p->pos_y <= gh_y + BLOCK_SIZE - 6)
		|| (p->pos_y + BLOCK_SIZE - 6 >= gh_y && p->pos_y <= gh_y + BLOCK_SIZE
			- 6 && p->pos_x + BLOCK_SIZE - 6 >= gh_x && p->pos_x <= gh_x
			+ BLOCK_SIZE - 6);
	if (same_position || neighboring_position)
		p->dead = true;
}

static void	draw_ghost_sprite(t_ghost *gh, int sprite_index)
{
	static int	frame = 0;
	static int	state = 0;

	if (frame >= 60)
	{
		state = (state + 1) % 4;
		frame = 0;
	}
	if (gh->alive && (gh->mode == CHASE || gh->mode == SCATTER))
		draw_obj(&(*gh->alive_sprite)[gh->direction][sprite_index], gh->pos_x,
			gh->pos_y);
	else if (gh->alive && gh->mode == FRIGHTENED)
		draw_obj(&(*gh->panic_sprite)[state], gh->pos_x, gh->pos_y);
	else if (gh->mode == EYES)
		draw_obj(&(*gh->eyes_sprite)[gh->direction], gh->pos_x, gh->pos_y);
	frame++;
}

static void	draw_ghost_sprite_no_collision(t_ghost *gh, int s_i)
{
	static int	frame = 0;
	static int	state = 0;

	if (frame >= 60)
	{
		state = (state + 1) % 4;
		frame = 0;
	}
	if (gh->alive && (gh->mode == CHASE || gh->mode == SCATTER))
	{
		draw_with_no_collision(&(*gh->alive_sprite)[gh->direction][s_i],
			gh->pos_x, gh->pos_y, &gh->object);
	}
	else if (gh->alive && gh->mode == FRIGHTENED)
		draw_with_no_collision(&(*gh->panic_sprite)[state], gh->pos_x,
			gh->pos_y, &gh->object);
	else if (gh->mode == EYES)
		draw_with_no_collision(&(*gh->eyes_sprite)[gh->direction], gh->pos_x,
			gh->pos_y, &gh->object);
	frame++;
}

static void	select_properly_draw(t_game *game, t_ghost *ghost, int sprite_index)
{
	bool	upon_exit;

	upon_exit = is_upon_object(ghost->pos_x, ghost->pos_y, game->exit.pos_x,
			game->exit.pos_y);
	if (upon_exit)
	{
		ghost->object.pos_x = game->exit.pos_x;
		ghost->object.pos_y = game->exit.pos_y;
		draw_ghost_sprite_no_collision(ghost, sprite_index);
		return ;
	}
	draw_ghost_sprite(ghost, sprite_index);
}

void	draw_ghost(t_game *game)
{
	t_ghost		*g_t;
	static int	frame_state = 0;
	int			sprite_index;

	g_t = game->ghost;
	sprite_index = 1;
	if (frame_state <= 20)
		sprite_index = 0;
	while (g_t)
	{
		if (g_t->mode != FRIGHTENED)
			detect_player_death(&game->player, g_t);
		select_properly_draw(game, g_t, sprite_index);
		g_t = g_t->next;
	}
	frame_state = (frame_state + 1) % 40;
}
