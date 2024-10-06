# Colors and formatting
RED=\033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[1;38;5;214m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

#TARGETS
NAME=libftprintf.a
CC=cc
CFLAGS= -Wall -Wextra -Werror
INCDIR= ./include/
DIR_LIBFT=./libft/
COMPILED_FILES = 0
TOTAL_FILES = $(words $(OBJ))
OS = $(shell uname)

CFUNCTIONS = ft_utils1 ft_utils2
OBJ = $(CFUNCTIONS:%=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "$(CYAN) library created succesfully!$(RESET)"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
ifeq ($(OS), Darwin)
	@printf "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))%% ] $(ORANGE)Compiling $<... $(RESET)"
else
	@echo -n "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))% ] $(ORANGE)Compiling $<... $(RESET)"
endif
	@$(CC) $(CFLAGS) -c $< -I$(INCDIR) -o $@

clean:
	@cd ./libft && make clean > /dev/null
	@rm -rf *.o > /dev/null

fclean: clean
	@rm -f $(NAME)
	@cd ./libft && rm -rf libft.a

re: clean fclean all




















# SRC=$(addprefix $(SRC_LIBDIR), $(addsuffix .c, $(CFUNCTIONS)))
# OBJ=$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(CFUNCTIONS)))

# .PHONY: all clean fclean re

# all: $(TARGET)

# $(TARGET): 	$(NAME) main.c
# 			@$(CC) main.c -I$(INCDIR) -L. -lftprintf -o $@
# 			@echo "$(COLOUR_blue)$(TARGET) compiled!"

# $(NAME): $(OBJ)
# 			@ar rcs $(NAME) $^
# 			@echo "$(COLOUR_GREEN)ft_printf compiled!"

# $(OBJ_DIR)/%.o: $(SRC_LIBDIR)/%.c | $(OBJ_DIR)
# 			@echo "$(COLOUR_YELLOW)Compiling $< files $(SYSTEM_COLOR)"
# 			@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# $(OBJ_DIR):
# 			@mkdir -p $(OBJ_DIR)

# clean:
# 			@echo "$(COLOUR_RED)Removing $(OBJ_DIR) $(SYSTEM_COLOR)"
# 			@rm -rf $(OBJ_DIR)

# fclean:	clean
# 			@echo "$(COLOUR_RED)Removing $(NAME) $(TARGET) $(SYSTEM_COLOR)"
# 			@rm -f $(NAME) $(TARGET)

# re:	fclean all
