/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_definitions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:05:46 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/17 22:00:15 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DEFINITIONS_H
# define LIB_DEFINITIONS_H

# include "libso_long.h"

# define BLOCK_SIZE 32
# define MLX_ERROR 3
# define CHECK_BITS 31
# define PAC_MAN_FRAME 10
# define LAYOUT 38
# define PAC_OPEN_LEFT "assets/player/pac_open_left.xpm"
# define PAC_SEMI_LEFT "assets/player/pac_semi_left.xpm"
# define PAC_OPEN_RIGHT "assets/player/pac_open_right.xpm"
# define PAC_SEMI_RIGHT "assets/player/pac_semi_right.xpm"
# define PAC_OPEN_UP "assets/player/pac_open_up.xpm"
# define PAC_SEMI_UP "assets/player/pac_semi_up.xpm"
# define PAC_OPEN_DOWN "assets/player/pac_open_down.xpm"
# define PAC_SEMI_DOWN "assets/player/pac_semi_down.xpm"
# define PAC_CLOSED "assets/player/pac_closed.xpm"
# define MAP_LAYOUT "assets/layout.xpm"
# define INKY_PATH "assets/ghost/INKY/"
# define BLINKY_PATH "assets/ghost/BLINKY/"
# define CLYDE_PATH "assets/ghost/CLYDE/"
# define PINKY_PATH "assets/ghost/PINKY/"
# define G_R1 "ghost_right1.xpm"
# define G_R2 "ghost_right2.xpm"
# define G_U1 "ghost_up1.xpm"
# define G_U2 "ghost_up2.xpm"
# define G_L1 "ghost_left1.xpm"
# define G_L2 "ghost_left2.xpm"
# define G_D1 "ghost_down1.xpm"
# define G_D2 "ghost_down2.xpm"
# define G_PANIC_BLUE1 "ghost-chased-blue1.xpm"
# define G_PANIC_BLUE2 "ghost-chased-blue2.xpm"
# define G_PANIC_WHITE1 "ghost-chased-white1.xpm"
# define G_PANIC_WHITE2 "ghost-chased-white2.xpm"
# define G_EYES_PATH "assets/ghost/EYES/"
# define G_EYES_LEFT "eyes_left.xpm"
# define G_EYES_RIGHT "eyes_right.xpm"
# define G_EYES_UP "eyes_up.xpm"
# define G_EYES_DOWN "eyes_down.xpm"
# define FRIGHTENED_TIMER 150
# define SCATTER_TIMER 30
# define CHASE_TIMER 150

typedef enum ghost_id
{
	PINKY,
	BLINKY,
	INKY,
	CLYDE,
	GHOST_COUNT
}	t_ghost_id;

typedef enum player_id
{
	p_open_left,
	p_semi_left,
	p_open_right,
	p_semi_right,
	p_open_up,
	p_semi_up,
	p_open_down,
	p_semi_down,
	p_closed,
}	t_player_id;

typedef enum movement_id
{
	DIR_LEFT,
	DIR_RIGHT,
	DIR_UP,
	DIR_DOWN,
	DIR_COUNT
}	t_movement_id;

typedef enum ghost_movement
{
	G_UP,
	G_DOWN,
	G_LEFT,
	G_RIGHT,
	DIR_O_COUNT
}	t_ghost_movement;

typedef enum ghost_mode
{
	SCATTER,
	CHASE,
	FRIGHTENED,
	EYES,
}	t_ghost_mode;

typedef enum coin_colors_id
{
	RED,
	YELLOW,
	GREEN,
	COIN_COUNT
}	t_coin_colors_id;

# ifndef FRAME_RATE
#  define FRAME_RATE 140
# endif

#endif
