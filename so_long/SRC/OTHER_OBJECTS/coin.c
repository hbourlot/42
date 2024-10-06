/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 22:56:26 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 21:49:33 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

void	activate_frightened_mode(t_game *game)
{
	t_ghost	*tmp;

	tmp = game->ghost;
	while (tmp)
	{
		if (tmp->alive)
		{
			tmp->mode = FRIGHTENED;
			tmp->mode_timer = FRIGHTENED_TIMER;
			tmp->cal_route = true;
		}
		tmp = tmp->next;
	}
}

int	player_eat_coin(t_game *game)
{
	t_coin	*c;
	int		p_x;
	int		p_y;

	p_x = game->player.pos_x;
	p_y = game->player.pos_y;
	c = game->coin;
	while (c)
	{
		if ((p_x == c->pos_x - 16 && p_y == c->pos_y) || (p_x == c->pos_x + 16
				&& p_y == c->pos_y) || (p_y == c->pos_y - 16 && p_x == c->pos_x)
			|| (p_y == c->pos_y + 16 && p_x == c->pos_x) || (p_x == c->pos_x
				&& p_y == c->pos_y))
		{
			if (c->removed == false)
			{
				c->removed = true;
				return (draw_obj(&game->map.sprite_black, c->pos_x, c->pos_y),
					1);
			}
		}
		c = c->next;
	}
	return (0);
}

void	draw_coin(t_game *game)
{
	t_coin		*coin;
	static int	phase = 0;

	if (player_eat_coin(game))
		activate_frightened_mode(game);
	coin = game->coin;
	while (coin)
	{
		if (coin->removed == false)
		{
			if (phase < 84)
				draw_obj(&(*coin->sprites)[RED], coin->pos_x, coin->pos_y);
			else if (phase <= 148)
				draw_obj(&(*coin->sprites)[GREEN], coin->pos_x, coin->pos_y);
			else
				draw_obj(&(*coin->sprites)[YELLOW], coin->pos_x, coin->pos_y);
		}
		coin = coin->next;
		phase++;
		if (phase == 220)
			phase = 0;
	}
}

t_coin	*new_coin(int pos_x, int pos_y)
{
	t_coin	*coin;

	coin = malloc(sizeof(t_coin));
	if (!coin)
		return (NULL);
	coin->pos_x = pos_x;
	coin->pos_y = pos_y;
	coin->sprites = NULL;
	coin->removed = false;
	coin->next = NULL;
	return (coin);
}

int	coin_add_back(t_coin **head, t_coin *node)
{
	t_coin	*temp;

	if (!node || !head)
		return (1);
	if (!(*head))
	{
		*head = node;
		return (0);
	}
	if (head && node)
	{
		temp = (*head);
		while (temp->next)
			temp = temp->next;
		temp->next = node;
		return (0);
	}
	return (1);
}
