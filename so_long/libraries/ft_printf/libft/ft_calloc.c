/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:29:10 by hbourlot          #+#    #+#             */
/*   Updated: 2024/04/10 13:36:31 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;

	temp = (void *)malloc(nmemb * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, (nmemb * size));
	return (temp);
}
