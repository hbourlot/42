/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:01:33 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/09 23:48:47 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Iterates through a linked list and applies a
///			 function to each element.
/// @param lst The beginning of the linked list.
/// @param f The function to apply to each element's content.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lista;

	if (!lst || !f)
		return ;
	lista = lst;
	f(lista->content);
	lista = lista->next;
	if (lista)
		ft_lstiter(lista, f);
}
