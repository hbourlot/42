/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:47:45 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 21:48:52 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

// ? White: 	0xFFFFFFFF
// ? Black: 	0xFF000000
// ? Red: 		0xFFFF0000
// ? Green: 	0xFF00FF00
// ? Blue: 		0xFF0000FF
// ? Yellow: 	0xFFFFFF00
// ? Cyan:		0xFF00FFFF
// ? Magenta: 	0xFFFF00FF

int	draw_obj(t_sprite *sprite, int width, int height)
{
	int	x_des;
	int	y_des;

	x_des = 0;
	y_des = 0;
	if (!sprite || !sprite->img || !sprite->addr)
	{
		perror("Invalid sprite\n");
		return (-1);
	}
	if (sprite->size_x < BLOCK_SIZE)
		x_des = (BLOCK_SIZE - sprite->size_x) / 2;
	if (sprite->size_y < BLOCK_SIZE)
		y_des = (BLOCK_SIZE - sprite->size_y) / 2;
	mlx_put_image_to_window(sprite->mlx_ptr, sprite->mlx_win, sprite->img, width
		+ x_des, height + y_des);
	return (0);
}

void	draw_pixel(t_sprite *sprite, int x, int y, int color)
{
	mlx_pixel_put(sprite->mlx_ptr, sprite->mlx_win, x, y, color);
}

void	draw_layout(t_game *game)
{
	creat_sprite(game, MAP_LAYOUT, &game->map.layout);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->map.layout.img,
		(game->map.width * 32 / 2) - (game->map.layout.size_x / 2),
		(game->map.height * BLOCK_SIZE) + 15);
}

void	draw_with_no_collision(t_sprite *sprite, int w, int h,
		t_object *collision)
{
	int				pos_x;
	int				pos_y;
	unsigned int	color;
	bool			object_area;

	pos_y = 0;
	while (pos_y++ < sprite->size_y)
	{
		pos_x = 0;
		while (pos_x++ < sprite->size_x)
		{
			object_area = (w + pos_x >= collision->pos_x && w
					+ pos_x < collision->pos_x + 32) && (h
					+ pos_y >= collision->pos_y && h + pos_y < collision->pos_y
					+ 32);
			color = get_pixel_color(sprite, pos_x, pos_y);
			if (color != (unsigned int)0xFF000000)
				draw_pixel(sprite, w + pos_x, h + pos_y, color);
			else if (!object_area)
			{
				draw_pixel(sprite, w + pos_x, h + pos_y,
					(unsigned int)0xFF000000);
			}
		}
	}
}
