/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libso_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:23:29 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/19 08:31:07 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSO_LONG_H
# define LIBSO_LONG_H

# include "../libraries/get_next_line/inc/get_next_line.h"
# include "../libraries/get_next_line/inc/get_next_line_bonus.h"
# include "../libraries/libft_upd/inc/libft.h"
# include "../libraries/ft_printf/include/ft_printf.h"
# include "../libraries/minilibx-linux/mlx.h"
# include "lib_definitions.h"
# include <X11/X.h>      // Button press
# include <X11/keysym.h> // Key device
# include <math.h>
# include <mcheck.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdbool.h>

typedef struct s_node
{
	int					x;
	int					y;
	int					distance;
	bool				visited;
	struct s_node		*prev;
	struct s_node		*next;
}						t_node;

typedef struct s_queue_node
{
	t_node				*node;
	struct s_queue_node	*next;
}						t_queue_node;

typedef struct s_location
{
	int					pos_x;
	int					pos_y;
	int					tar_x;
	int					tar_y;
}						t_location;

typedef struct s_img
{
	char				*addr;
	void				*mlx_ptr;
	void				*mlx_win;
	void				*img;
	int					size_x;
	int					size_y;
	int					color;
	int					bpp;
	int					size_line;
	int					endian;
}						t_sprite;

typedef struct s_coin
{
	bool				removed;
	int					pos_x;
	int					pos_y;
	t_sprite (*sprites)[COIN_COUNT];
	struct s_coin		*next;
}						t_coin;

typedef struct s_exit
{
	int					pos_x;
	int					pos_y;
	t_sprite			closed;
	t_sprite			open;
}						t_exit;

typedef struct s_counter
{
	t_sprite			sprites[10];
}						t_counter;

typedef struct s_map
{
	char				*path;
	char				**map_grid;
	int					width;
	int					height;
	int					n_exit;
	int					n_player;
	int					n_ghost;
	int					n_coin;
	t_sprite			sprite_wall;
	t_sprite			sprite_black;
	t_sprite			sprite_star;
	t_sprite			layout;
}						t_map;

typedef struct s_collision
{
	t_map				*map;
	int					pos_x;
	int					pos_y;
	int					speed;
}						t_object;

typedef struct s_logic_ghost
{
	t_node				**map_nodes;
	t_node				*start;
	t_node				*target;
	t_node				*current;
	t_node				*next;
	t_node				*prev;
}						t_logic_ghost;

typedef struct s_ghost
{
	int					id;
	int					pos_x;
	int					pos_y;
	int					direction;
	int					start_x;
	int					start_y;
	int					mode_timer;
	t_ghost_mode		mode;
	bool				alive;
	bool				swap_mode;
	bool				cal_route;
	t_logic_ghost		ai_ghost;
	t_sprite (*alive_sprite)[DIR_COUNT][2];
	t_sprite (*panic_sprite)[4];
	t_sprite (*eyes_sprite)[4];
	t_node				*path;
	t_object			object;
	struct s_ghost		*next;
}						t_ghost;

typedef struct s_player
{
	bool				dead;
	int					direction;
	int					attempt_mov;
	int					pos_x;
	int					pos_y;
	t_sprite (*pac_dying)[10];
	t_sprite			sprites[DIR_COUNT][3];
	t_object			object;
}						t_player;

typedef struct s_game
{
	void				*mlx_ptr;
	void				*mlx_win;
	t_map				map;
	t_coin				*coin;
	t_player			player;
	t_ghost				*ghost;
	t_object			object;
	t_exit				exit;
	t_counter			counter;
	t_sprite			pac_dying[10];
	t_sprite			coin_sprites[COIN_COUNT];
	t_sprite			ghost_alive_sprite[GHOST_COUNT][DIR_COUNT][2];
	t_sprite			ghost_panic_sprite[4];
	t_sprite			ghost_eyes_sprite[4];
}						t_game;

void					switch_scatter_chase(t_ghost *gh);
void					select_ghost_target(t_game *game, t_ghost *ghost);
void					manage_ghost_behavior(t_game *game, t_ghost *ghost);
bool					is_in_tile(int x, int y, int tile_size);

/// @brief Retrieves the color of a pixel from a sprite at a given position.
/// @param sprite The sprite from which to get the pixel color.
/// @param pos_x The X position of the pixel in the sprite.
/// @param pos_y The Y position of the pixel in the sprite.
/// @return The color of the pixel as an unsigned int.
unsigned int			get_pixel_color(t_sprite *sprite, int pos_x, int pos_y);

/// @brief Animates Pac-Man's death sequence and pauses the game.
/// @param game Pointer to the game structure containing Pac-Man's state.
int						draw_pac_man_dead(t_game *game);

/// @brief Handles the window close event by closing the game
///	and cleaning up resources.
/// @param game The game structure containing all relevant data.
/// @return Always returns 0.
int						ft_close_x(t_game *game);

/// @brief Initializes the game window by setting up the map and graphics.
/// @param game The game structure to be initialized.
/// @return 0 on success, 1 on failure.
int						initialize_window(t_game *game);

/// @brief Processes the map layout and updates game dimensions.
/// @param game The game structure containing the map.
/// @return 0 if successful, 1 if an error occurs.
int						process_map_layout(t_game *game);

/// @brief Loads the map from a file descriptor into a grid.
/// @param fd The file descriptor to read from.
/// @return A 2D array of strings representing the map, or NULL on failure.
char					**load_grid_map(int fd);

/// @brief Validates the map by checking wall boundaries, format,
/// character usage, and path reachability.
/// @param game Contains the map and game state.
/// @return 0 if the map is valid, 1 if invalid.
int						is_invalid_map(t_game *game);

/// @brief Checks if the map is surrounded by walls (i.e.,
///	the borders are all '1').
/// @param map The 2D map grid.
/// @return 1 if surrounded by walls, 0 otherwise.
int						is_surrounded_by_walls(char **map);

/// @brief Checks if the map is a proper square map (i.e.,
///	all rows have the same width).
/// @param map The map structure containing the map grid.
/// @return 1 if the map is not a square, 0 otherwise.
int						is_invalid_format(t_map *map);

/// @brief Checks if the map contains exactly one player and one exit,
///	and validates characters.
/// @param map The map structure containing the map grid.
/// @return 1 if invalid or incorrect number of players/exits, 0 otherwise.
int						check_letter(t_map *map);

/// @brief Frees all resources and closes the game window.
/// @param game Pointer to the game structure.
void					free_window(t_game *game);

/// @brief Closes the game, frees all allocated resources,
///	and optionally displays an error message.
/// @param game Pointer to the game structure.
/// @param error_msg Pointer to the error message string.
/// @param state Exit state of the program
///	(usually EXIT_SUCCESS or EXIT_FAILURE).
void					close_game(t_game *game, const char *error_msg,
							int state);

/// @brief Draws the game layout on the screen.
/// @param game The game structure that holds the map and rendering information.
void					draw_layout(t_game *game);

/// @brief Frees all nodes in the priority queue.
/// @param pq Pointer to the priority queue.
void					free_priority_queue(t_queue_node **pq);

/// @brief Frees the memory allocated for the linked
/// list of coins and their associated resources.
/// @param game The game structure containing the coin linked list.
void					free_coin(t_game *game);

/// @brief Frees all resources associated with the map in the game.
/// This includes sprite images for the map layout, wall, stars,
///	and black sprite,
/// as well as the counter sprites used for displaying the move counter.
/// @param game The game structure containing map and sprite information.
void					free_map(t_game *game);

/// @brief Frees the resources associated with the player's sprites.
/// This includes freeing all player sprites for different directions
///	and states.
/// @param game The game structure containing player sprite information.
void					free_player(t_game *game);

/// @brief Removes a coin from the game when the player reaches its position.
/// @param game The game structure containing the player and coin information.
int						player_eat_coin(t_game *data);

/// @brief Adds a new coin to the end of the linked list of coins.
/// @param head Pointer to the head of the coin list.
/// @param node Pointer to the new coin to be added.
/// @return 0 if successful, 1 if there is an error
int						coin_add_back(t_coin **head, t_coin *node);

/// @brief Creates a new coin object at the specified position.
/// @param pos_x The x-coordinate of the coin.
/// @param pos_y The y-coordinate of the coin.
/// @return Pointer to the newly created coin,
///	or NULL if memory allocation fails.
t_coin					*new_coin(int pos_x, int pos_y);

/// @brief Draws the coins on the game map with a color-changing animation.
/// @param game The game structure containing the coin information.
void					draw_coin(t_game *game);

/// @brief Adds a ghost to the end of the linked list.
/// @param head A pointer to the head of the list of ghosts.
/// @param node The ghost to be added.
/// @return 1 if the ghost was added successfully, 0 otherwise.
int						ghost_add_back(t_ghost **head, t_ghost *node);

/// @brief Creates a new ghost with specified coordinates.
/// @param pos_x The x-coordinate of the ghost.
/// @param pos_y The y-coordinate of the ghost.
/// @return A pointer to the newly created ghost, or NULL if allocation fails.
t_ghost					*new_ghost(int pos_x, int pos_y);

/// @brief Frees the memory allocated for the linked
/// list of ghosts and their associated resources.
/// @param game The game structure containing the ghosts.
void					free_ghosts(t_game *game);
void					draw_ghost(t_game *game);

int						ai_ghost(t_game *game);

/// @brief Updates and draws the player sprite depending on
///	the frame rate and direction.
/// @param game The game structure containing player
/// and game information.
void					draw_player(t_game *game);

/// @brief Draws a pixel at a specific position with a given color.
/// @param sprite The sprite or window where the pixel will be drawn.
/// @param x The X position of the pixel.
/// @param y The Y position of the pixel.
/// @param color The color of the pixel in hexadecimal (e.g.,
///	0xFFFFFF for white).
void					draw_pixel(t_sprite *sprite, int x, int y, int color);

/// @brief Draws a sprite at a given width and height in the window.
/// @param sprite The sprite to draw.
/// @param width The X position on the window where the sprite should be drawn.
/// @param height The Y position on the window where the sprite should be drawn.
/// @return 0 on success, -1 if there is an error (e.g., invalid sprite).
int						draw_obj(t_sprite *sprite, int width, int height);

/// @brief Draws the exit on the screen,
///	based on whether all coins are collected or not.
/// @param game The game structure containing the exit and coin information.
void					draw_exit(t_game *game);

/// @brief Checks if an object is positioned upon another object.
/// @param pos_x The X position of the first object.
/// @param pos_y The Y position of the first object.
/// @param obj_x The X position of the second object (to check collision with).
/// @param obj_y The Y position of the second object (to check collision with).
/// @return true if the first object is upon the second object, otherwise false.
bool					is_upon_object(int pos_x, int pos_y, int obj_x,
							int obj_y);

/// @brief Draws a sprite while avoiding areas of collision.
/// @param sprite The sprite to draw.
/// @param w The width offset to draw the sprite.
/// @param h The height offset to draw the sprite.
/// @param collision The object to avoid drawing over (collision area).
void					draw_with_no_collision(t_sprite *sprite, int w, int h,
							t_object *collision);

/// @brief Updates and draws the move counter if the player's direction changes.
/// @param game The game structure containing game and player information.
/// @return 0 if the counter is drawn, 1 if no drawing is needed.
int						draw_counter(t_game *game);

/// @brief Loads the sprites for the player's movement and state.
/// @param game The game structure to which the sprites are added.
void					load_player_sprites(t_game *game);

/// @brief Loads all sprites required for the game.
/// @param game The game structure where sprites are added.
void					load_all_sprites(t_game *game);

/// @brief Loads all ghost sprites for each ghost and direction,
///	then assigns them.
/// @param game The game structure where the sprites will be
/// loaded and assigned.
void					load_ghost_sprites(t_game *game);

/// @brief Loads the sprites for the player's dying animation.
/// @param game The game structure to which the sprites are added.
void					load_pac_dead_sprites(t_game *game);

/// @brief Initializes the game loop by loading sprites, setting up event hooks,
///	and starting the game loop.
/// @param game The game structure containing all relevant data.
/// @return 0 on success, -1 on failure.
int						initialize_game_loop(t_game *game);

///  @brief Pauses the execution of the program for a
/// specified number of microseconds.
/// This function uses a simple busy loop to pause the execution of the program
/// for the specified number of microseconds. It achieves this by incrementing
/// a counter until it reaches a target value, which is calculated based
/// on the input microseconds.
/// @param microseconds The number of microseconds to pause the program for.
/// @return This function does not return a value.
void					my_usleep(unsigned int microseconds);

/// @brief Creates a sprite by loading an image into the provided
/// t_sprite structure.
/// @param game Pointer to the game structure containing the MLX pointers.
/// @param sprite Path to the sprite image file (XPM format).
/// @param image Pointer to the sprite structure where the image
/// data will be stored.
void					creat_sprite(t_game *game, const char *sprite,
							t_sprite *image);

/// @brief Checks for collision based on an object's movement and position.
/// @param obj Pointer to the object being moved.
/// @param mov Movement direction (using directional constants like DIR_UP,
///	DIR_DOWN, etc.).
/// @param new_pos Array where the new calculated position will be stored.
/// @return Returns true if a collision occurs, otherwise false.
bool					is_collision(t_object *obj, int mov, int *new_pos);

/// @brief Reconstructs a path by traversing from the last
///	node to the first, setting the 'next' pointer of each node.
/// @param last Pointer to the last node in the path.
/// @return Returns 0 on success, or -1 if the input is invalid.
int						remake_path(t_node **last);

/// @brief  Moves the ghost along the given path in the game map,
/// updating its position  if no collision occurs.
/// @param ghost Pointer to the t_ghost structure containing the
/// ghost's state (position, direction, etc.).
/// @param game Pointer to the t_game structure, which holds the
/// game's map and  global state.
/// @param path Pointer to the t_node structure representing the
/// current path  node the ghost is following.
void					move_ghost(t_ghost *ghost, t_game *game, t_node *path);

/// @brief Automatically handles the player's movement, checking
/// for collisions and updating the player's position.
/// @param game Pointer to the game structure containing player
/// and map information.
/// @return Returns 1 if the player's position changed, otherwise returns 0.
int						automatic_moves_player(t_game *game);

/// @brief Initializes the nodes used by the ghost for pathfinding.
/// @param game The game structure containing the map information.
/// @param ghost The ghost whose nodes are to be initialized.
void					init_nodes(t_game *game, t_ghost *ghost);

/// @brief Allocates memory for the logic nodes used by ghosts.
/// @param game The game structure containing ghost information.
/// @param width The width of the map in tiles.
/// @param height The height of the map in tiles.
/// @return 0 if successful, -1 if an error occurs during allocation.
int						malloc_ghost_logic_nodes(t_game *game, int width,
							int height);

/// @brief Initializes the pathfinding logic for a ghost.
/// @param game The game structure containing player and map information.
/// @param ghost The ghost whose pathfinding logic is to be initialized.
void					init_logic(t_game *game, t_ghost *ghost);

/// @brief Calculates the route for the ghost's movement,
///	considering its AI state and target.
/// @param game Pointer to the game structure.
/// @param ghost Pointer to the ghost structure.
/// @return Returns the node representing the ghost's next position.
t_node					*cal_route(t_game *game, t_ghost *ghost);

/// @brief Adds a node to the priority queue based on its distance.
/// @param queue A pointer to the head of the priority queue.
/// @param node The node to be added to the queue.
/// @return 0 if the node was successfully added, -1 otherwise.
int						enqueue(t_queue_node **queue, t_node *node);

/// @brief Removes and returns the node at the front of the priority queue.
/// @param queue A pointer to the head of the priority queue.
/// @return The node removed from the queue, or NULL if the queue was empty.
t_node					*dequeue(t_queue_node **queue);

#endif