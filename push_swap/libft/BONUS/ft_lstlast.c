/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:20:44 by hbourlot          #+#    #+#             */
/*   Updated: 2024/06/29 20:42:14 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Finds the last element of a linked list.
/// @param lst The beginning of the linked list.
/// @return The last element of the linked list.
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (!lst)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}
