/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:34:46 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/19 08:30:18 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

static int	eat_frightened_ghost(t_ghost *gh, t_player *p)
{
	bool	neighboring_position;
	int		gh_x;
	int		gh_y;

	gh_x = gh->pos_x;
	gh_y = gh->pos_y;
	neighboring_position = (p->pos_x >= gh_x && p->pos_x <= gh_x + BLOCK_SIZE
			- 6 && p->pos_y >= gh_y && p->pos_y <= gh_y + BLOCK_SIZE - 6)
		|| (p->pos_y + BLOCK_SIZE - 6 >= gh_y && p->pos_y <= gh_y + BLOCK_SIZE
			- 6 && p->pos_x + BLOCK_SIZE - 6 >= gh_x && p->pos_x <= gh_x
			+ BLOCK_SIZE - 6);
	if (gh->mode == FRIGHTENED && neighboring_position)
	{
		gh->mode = EYES;
		gh->alive = false;
	}
	else if (gh->pos_x == gh->start_x && gh->pos_y == gh->start_y)
	{
		gh->alive = true;
		gh->mode = CHASE;
	}
	return (0);
}

void	manage_ghost_behavior(t_game *game, t_ghost *ghost)
{
	switch_scatter_chase(ghost);
	eat_frightened_ghost(ghost, &game->player);
	select_ghost_target(game, ghost);
}
