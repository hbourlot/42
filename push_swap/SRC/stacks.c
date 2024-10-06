/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:45:48 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/12 19:42:57 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pushswap.h"

/// @brief Creates a new stack node with a given value.
/// @param value The value to be stored in the new node.
/// @return A pointer to the newly created node, or NULL on failure.
t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = value;
	node->next = NULL;
	return (node);
}

/// @brief Adds a node to the end of the stack.
/// There's a plus change from original function, which makes my new
/// last_node->previous get connected with previous node;
/// This can be only used if there`s head node, if not ->previous
/// will get null address;
/// @param head Pointer to the head of the stack.
/// @param node The node to be added.
/// @return 0 on success, 1 on failure.
int	stack_add_back(t_stack **head, t_stack *node)
{
	t_stack	*temp;

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

/// @brief Adds a node to the front of the stack.
/// @param head Pointer to the head of the stack.
/// @param node The node to be added.
/// @return 0 on success, 1 on failure.
int	stack_add_front(t_stack **head, t_stack *node)
{
	if (head && node)
	{
		node->next = (*head);
		(*head) = node;
		return (0);
	}
	return (1);
}

/// @brief Returns the last node in the stack.
/// @param lst Pointer to the head of the stack.
/// @return A pointer to the last node, or NULL if the stack is empty.
t_stack	*stack_last(t_stack **lst)
{
	t_stack	*last;

	last = *lst;
	if (!lst)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}
