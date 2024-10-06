/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:32:05 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 22:03:03 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libso_long.h"

int	main(int argc, char *argv[])
{
	const char	error[] = "Missing map argument\n";
	t_game		game;

	if (argc == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		game.player.direction = DIR_RIGHT;
		game.player.attempt_mov = -1;
		game.map.path = argv[1];
		if (initialize_window(&game))
			return (MLX_ERROR);
		if (initialize_game_loop(&game))
			return (1);
		return (0);
	}
	write(2, error, ft_strlen(error));
	return (1);
}
