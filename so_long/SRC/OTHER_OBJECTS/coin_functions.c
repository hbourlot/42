/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:40:54 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/14 16:10:50 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

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
