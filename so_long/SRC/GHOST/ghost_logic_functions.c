/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_logic_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:54:59 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/13 19:28:10 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

int	enqueue(t_queue_node **queue, t_node *node)
{
	t_queue_node	*new_node;
	t_queue_node	*current;

	new_node = malloc(sizeof(t_queue_node));
	if (!new_node)
		return (-1);
	new_node->node = node;
	new_node->next = NULL;
	if (!*queue || (*queue)->node->distance > node->distance)
	{
		new_node->next = *queue;
		*queue = new_node;
	}
	else
	{
		current = *queue;
		while (current->next && current->next->node->distance <= node->distance)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
	return (0);
}

t_node	*dequeue(t_queue_node **queue)
{
	t_queue_node	*temp;
	t_node			*node;

	if (!queue || !*queue)
		return (NULL);
	node = (*queue)->node;
	temp = *queue;
	*queue = (*queue)->next;
	free(temp);
	return (node);
}
