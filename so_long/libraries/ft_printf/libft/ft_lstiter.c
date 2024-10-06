/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:01:33 by hbourlot          #+#    #+#             */
/*   Updated: 2024/04/15 16:05:54 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
