/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 08:45:02 by hbourlot          #+#    #+#             */
/*   Updated: 2024/06/29 20:41:45 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Creates a new node for a linked list.
/// @param content The content to be stored in the new node.
/// @return A pointer to the newly created node, or NULL if allocation fails.
t_list	*ft_lstnew(void *content)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(*temp));
	if (!temp)
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}
