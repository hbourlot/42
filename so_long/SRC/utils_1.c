/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:12:03 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/27 08:17:06 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

void	my_usleep(unsigned int microseconds)
{
	volatile unsigned int	count;
	unsigned int			target;

	count = 0;
	target = microseconds * 100;
	while (count < target)
		count++;
}

bool	is_collision(t_object *obj, int mov, int *new_pos)
{
	const int	movement_vectors[DIR_COUNT][2] = {{-1, 0}, {1, 0}, {0, -1}, {0,
		1}};
	int			g_x;
	int			g_y;

	new_pos[0] = movement_vectors[mov][0] * obj->speed;
	new_pos[1] = movement_vectors[mov][1] * obj->speed;
	g_x = (obj->pos_x + new_pos[0]) / 32;
	g_y = (obj->pos_y + new_pos[1]) / 32;
	if (g_x < 0 || g_x >= obj->map->width || g_y < 0 || g_y >= obj->map->height)
		return (true);
	if (obj->map->map_grid[g_y][g_x] == '1')
		return (true);
	if (mov == DIR_DOWN && obj->map->map_grid[(obj->pos_y / 32) + 1][obj->pos_x
		/ 32] == '1')
		return (true);
	if (mov == DIR_RIGHT && obj->map->map_grid[obj->pos_y
			/ BLOCK_SIZE][(obj->pos_x / 32) + 1] == '1')
		return (true);
	return (false);
}

int	remake_path(t_node **last)
{
	t_node	*tmp;

	if (!last || !*last)
		return (-1);
	while ((*last)->prev)
	{
		tmp = (*last);
		(*last) = (*last)->prev;
		(*last)->next = tmp;
	}
	return (0);
}

unsigned int	get_pixel_color(t_sprite *sprite, int pos_x, int pos_y)
{
	unsigned int	color;

	color = *(unsigned int *)(sprite->addr + (pos_y * sprite->size_line + pos_x
				* (sprite->bpp / 8)));
	return (color);
}
