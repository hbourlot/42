/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:45:17 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 11:56:22 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

t_ghost	*new_ghost(int pos_x, int pos_y)
{
	t_ghost		*gh;
	static int	gh_id = 0;

	gh = malloc(sizeof(t_ghost));
	if (!gh)
		return (NULL);
	ft_bzero(gh, sizeof(t_ghost));
	gh->id = gh_id;
	gh->pos_x = pos_x;
	gh->pos_y = pos_y;
	gh->start_x = pos_x;
	gh->start_y = pos_y;
	gh->mode_timer = CHASE_TIMER;
	gh->direction = DIR_RIGHT;
	gh->cal_route = true;
	gh->alive = true;
	gh->mode = SCATTER;
	gh_id++;
	if (gh_id == 4)
		gh_id = 0;
	return (gh);
}

int	ghost_add_back(t_ghost **head, t_ghost *node)
{
	t_ghost	*temp;

	if (!node || !head)
		return (0);
	if (!(*head))
	{
		*head = node;
		return (1);
	}
	if (head && node)
	{
		temp = (*head);
		while (temp->next)
			temp = temp->next;
		temp->next = node;
		return (1);
	}
	return (0);
}
