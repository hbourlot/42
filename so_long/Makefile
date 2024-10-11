# Colors and formatting
RED=				\033[1;31m
YELLOW = 			\033[1;33m
ORANGE = 			\033[1;38;5;214m
GREEN = 			\033[1;32m
GREEN_D = 			\033[3;32m
CYAN = 				\033[1;36m
RESET = 			\033[0m

# !GAME RULES
FRAME_RATE ?= 		80
# !END GAME RULES

# -- VARIABLES --
CC = 				cc
MEMCHECKER = 		-fsanitize=address
CFLAGS = 			-g -Wall -Wextra -Werror -DFRAME_RATE=$(FRAME_RATE)
LEAKS = 			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
MINILIB_FLAGS = 	-Llibraries/minilibx-linux -lmlx_Linux -lX11 -lXext
INC = 				inc/
NAME =		 		so_long
OBJ_DIR = 			OBJ/
SRC_DIR = 			SRC/
SRC_MAP_DIR = 		$(SRC_DIR)MAP/
SRC_FREE_DIR = 		$(SRC_DIR)FREE/
SRC_GHOST_DIR = 	$(SRC_DIR)GHOST/
SRC_SPRITES_DIR = 	$(SRC_DIR)SPRITES/
SRC_OTHER_OBJ_DIR = $(SRC_DIR)OTHER_OBJECTS/
LIB = 				libso_long.a
LIB_DIR = 			./inc/$(LIB)
LINK = 				-L$(LIBFT_DIR) -lft $(MINILIB_FLAGS) -L. -lso_long -L$(GETNEXTLINE_DIR) -lget_next_line -L$(PRINTF_DIR) -lftprintf
TOTAL_FILES = 		$(words $(OBJ_SRC))
COMPILED_FILES = 	0
OS = 				$(shell uname)
# -- END VARIABLES --

# -- Importing others projects --
PRINTF_DIR = 		libraries/ft_printf/
PRINTF_LIB = 		$(PRINTF_DIR)libftprintf.a
LIBFT_DIR = 		libraries/libft_upd/
LIBFT_LIB = 		$(LIBFT_DIR)libft.a
GETNEXTLINE_DIR = 	libraries/get_next_line/
GETNEXTLINE_LIB = 	$(GETNEXTLINE_DIR)libget_next_line.a
# -- END importing --

FREE_FUNCTIONS = 	free_coin.c free_map.c free_player.c free_ghost.c
GHOST_FUNCTIONS = 	ai_ghost.c cal_ghost_path.c ghost_behavior.c ghost_functions.c 	\
				  	ghost_logic_functions.c ghost_target.c ghost.c init_aighost.c  	\
				  	movement_ghost.c
MAP_FUNCTIONS = 	map_grid.c process_map_layout.c validate_map_functions.c 			\
					validate_map.c
OTHER_FUNCTIONS	= 	coin_functions.c coin.c counter.c door_exit.c movement_player.c 	\
				  	player.c
SPRITES_FUNCTIONS = load_all_sprites.c load_ghost_sprites.c load_player_sprites.c

GAME_FUNCTIONS = 	close_game.c draw.c game.c initialize_window.c utils_1.c utils_2.c 

C_FUNCTIONS = 		$(addprefix $(SRC_FREE_DIR), $(FREE_FUNCTIONS)) 		\
					$(addprefix $(SRC_GHOST_DIR), $(GHOST_FUNCTIONS)) 		\
					$(addprefix $(SRC_OTHER_OBJ_DIR), $(OTHER_FUNCTIONS)) 	\
					$(addprefix $(SRC_SPRITES_DIR), $(SPRITES_FUNCTIONS)) 	\
					$(addprefix $(SRC_MAP_DIR), $(MAP_FUNCTIONS)) 			\
					$(addprefix $(SRC_DIR),	$(GAME_FUNCTIONS))
				
OBJ_SRC = 			$(C_FUNCTIONS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

invalid_maps =		MAP/invalid/1.ber MAP/invalid/2.ber MAP/invalid/3.ber MAP/invalid/4.ber \
					MAP/invalid/5.ber MAP/invalid/6.ber MAP/invalid/7.ber MAP/invalid/8.ber \
					MAP/invalid/9.ber MAP/

.PHONY:		all clean fclean re
all:			$(NAME) 

$(NAME):	$(LIBFT_LIB) $(GETNEXTLINE_LIB) $(PRINTF_LIB) $(LIB) main.o
					@make re -s -C ./libraries/minilibx-linux/
					@$(CC) $(CFLAGS) main.o $(LIB) $(LINK) -o $@
					@echo "$(GREEN_D)Executable '$(NAME)' compiled successfully!$(RESET)"

$(LIB):		$(OBJ_SRC)
					@echo "$(CYAN)Files compiled successfully!$(RESET)"
					@ar -rcs $@ $^

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c
					@mkdir -p $(dir $@)
					$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))

ifeq ($(OS), Darwin)
					@printf "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))%% ] $(ORANGE)Compiling $<... $(RESET)"
else
					@echo -n "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))% ] $(ORANGE)Compiling $<... $(RESET)"
endif
					@$(CC) $(CFLAGS) -c $< -I$(INC) -o $@

$(LIBFT_LIB):
					@make -s -C $(LIBFT_DIR)

$(PRINTF_LIB):
					@make -s -C $(PRINTF_DIR)

$(GETNEXTLINE_LIB):
					@make -s -C $(GETNEXTLINE_DIR)

$(GETNEXTLINE_DIR)%.o: $(GETNEXTLINE_DIR)%.c
					@mkdir -p $(dir $(OBJ_DIR))
					@$(CC) $(CFLAGS) -c $< -o $@
					@mv $@  $(OBJ_DIR)

main.o:		main.c
					@$(CC) $(CFLAGS) $< -c -I./$(INC) -o $@

clean:
					@printf "$(CYAN)Cleaning up *.o files...$(RESET)\b"
					@rm -rf $(OBJ_DIR) main.o
					@make clean -s -C $(LIBFT_DIR)
					@make clean -s -C $(GETNEXTLINE_DIR)
					@make clean -s -C $(PRINTF_DIR)
					@echo " $(GREEN)Cleaned successfully.$(RESET)"

fclean:		clean
					@printf "$(CYAN)Cleaning up *.a files...$(RESET)\b"
					@rm -rf $(NAME) $(LIB)
					@make fclean -s -C $(LIBFT_DIR)
					@make fclean -s -C $(GETNEXTLINE_DIR)
					@make fclean -s -C $(PRINTF_DIR)
					@echo " $(GREEN)Cleaned successfully.$(RESET)"

re:			fclean all

new:
					@make re -s -C ./libraries/minilibx-linux

invalid: 	all
					@echo "$(CYAN)Starting memory leak checks for invalid maps...$(RESET)"
					@ for map in $(invalid_maps); do \
					printf "\nCommand: $(GREEN)$(LEAKS)./$(NAME) $$map$(RESET)\n"; \
					$(LEAKS) ./$(NAME) $$map ; \
					done
					@echo "$(CYAN)Memory checks completed for all invalid maps.$(RESET)"

pacman:
					@$(MAKE) re -s
					@./$(NAME) MAP/pacman.ber



