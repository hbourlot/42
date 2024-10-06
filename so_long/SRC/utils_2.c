/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:47:51 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/27 08:17:42 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

bool	is_in_tile(int x, int y, int tile_size)
{
	if (x % tile_size == 0 && y % tile_size == 0)
		return (true);
	return (false);
}

bool	is_upon_object(int pos_x, int pos_y, int obj_x, int obj_y)
{
	bool	first_condition;
	bool	second_condition;

	first_condition = pos_x > (obj_x - BLOCK_SIZE) && pos_x < (obj_x
			+ BLOCK_SIZE);
	second_condition = pos_y > (obj_y - BLOCK_SIZE) && pos_y < (obj_y
			+ BLOCK_SIZE);
	if (first_condition && second_condition)
		return (true);
	return (false);
}
