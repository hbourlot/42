RED=\033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[1;38;5;214m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m


CC = cc
INCLUDES = inc/
CFLAGS =  #-Wall -Wextra -Werror -g #--fsanitize=address
SRC_DIR = SRC/
OBJ_DIR = OBJ/
OBJ_DIR_B = OBJ/
LIBFT_LIB = ./libft/libft.a
PRINTF_LIB =./printf/libftprintf.a
GETNEXTLINE_LIB = ./get_next_line/libget_next_line.a
LIBFT_DIR = libft/
LIB = lib_pushswap.a
PRINTF_DIR = printf/
GETNEXTLINE_DIR = get_next_line/
BONUS_DIR = BONUS/
TARGET = push_swap
BONUS_TARGET = checker

CFUNCTIONS = algorithm.c cal_moves.c checker.c count_moves.c move.c 	\
			 stack_math_utils.c stack_operations.c stack_utils.c 		\
			 stack_validation.c stacks.c

BONUS_FUNCTIONS = tests_bonus.c utils_bonus.c process_moves.c

OBJ_SRC = $(addprefix $(OBJ_DIR), $(CFUNCTIONS:%.c=%.o))
BONUS_SOURCE = $(addprefix $(OBJ_DIR)$(BONUS_DIR), $(BONUS_FUNCTIONS:%.c=%.o))

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(LIBFT_LIB) $(PRINTF_LIB) $(GETNEXTLINE_LIB) $(LIB) main.o
	@cc $(CFLAGS) main.o $(LIB) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(GETNEXTLINE_DIR) -lget_next_line -o $@
	@echo "$(GREEN)Executable compiled successfully!$(RESET)"

$(LIB): $(OBJ_SRC)
	@echo "$(CYAN)Files compiled successfully!$(RESET)"
	@ar -rcs $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(ORANGE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -I$(INCLUDES) -o $@

$(LIBFT_LIB):
	@echo "$(ORANGE)Compiling files...$(RESET)"
	@make -s -C $(LIBFT_DIR)

$(PRINTF_LIB):
	@make -s -C $(PRINTF_DIR)

$(GETNEXTLINE_LIB):
	@make -s -C $(GETNEXTLINE_DIR)

main_bonus.o : main_bonus.c
	@$(CC) $(CFLAGS) $< -I./$(INCLUDES) -c $<
main.o : main.c
	@$(CC) $(CFLAGS) $< -I./$(INCLUDES) -c $<

$(OBJ_DIR)$(BONUS_DIR)%.o: $(BONUS_DIR)%.c
	@mkdir -p $(OBJ_DIR)$(BONUS_DIR)
	@echo "$(ORANGE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -I$(INCLUDES) -o $@

bonus: $(BONUS_TARGET)

$(BONUS_TARGET): $(LIBFT_LIB) $(PRINTF_LIB) $(GETNEXTLINE_LIB) $(LIB) $(BONUS_SOURCE) main_bonus.o
	@cc $(CFLAGS) main_bonus.o $(LIB) $(BONUS_SOURCE) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(GETNEXTLINE_DIR) -lget_next_line -o $@	
	@echo "$(GREEN)Bonus compiled successfully!$(RESET)"

clean:
	@rm -rf main.o main_bonus.o $(OBJ_DIR) $(TARGET) $(BONUS_TARGET)
	@make clean -s -C $(LIBFT_DIR)
	@make clean -s -C $(PRINTF_DIR)
	@make clean -s -C $(GETNEXTLINE_DIR)
	@echo "$(ORANGE)Removing .o files!"

fclean: clean
	@echo "$(ORANGE)Removing .a files!"
	@echo "Removing exec files!"
	@rm -rf $(LIB) $(EXEC) $(BONUS_EXEC)
	@make fclean -s -C $(LIBFT_DIR)
	@make fclean -s -C $(PRINTF_DIR)
	@make fclean -s -C $(GETNEXTLINE_DIR)
	@echo "$(SYSTEM_COLOR)"

re: clean fclean all

# show_ascii:
# 	@echo "$$ascii_art"

invalid1:
	@make
	@make bonus
	./push_swap "" | ./checker ""
invalid2:
	@make
	@make bonus
	./push_swap " " | ./checker " "
invalid3:
	@make
	@make bonus
	./push_swap 9999999999999999999999999999999999999999999999999999999999999999 | ./checker 9999999999999999999999999999999999999999999999999999999999999999
invalid4:
	@make
	@make bonus
	./push_swap +0 | ./checker +0
invalid5:
	@make
	@make bonus
	./push_swap -0 +0 | ./checker -0 +0
invalid6:
	@make
	@make bonus
	./push_swap -0 +0
invalid7:
	@make
	@make bonus
	ARG="4 67 3 999999999999999999999999999999999999999999999999999999" ; ./push_swap $ARG | ./checker $ARG
