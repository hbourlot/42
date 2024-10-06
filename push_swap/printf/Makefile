# COLOR

SYSTEM_COLOR = \033[0;39m
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW = \033[0;93m
COLOUR_END=\033[0m

#TARGETS
NAME=libftprintf.a
CC=cc
CFLAGS= -Wall -Wextra -Werror
INCDIR= ./inc/
DIR_LIBFT=./libft/

CFUNCTIONS = ft_utils1 ft_utils2
OBJ = $(CFUNCTIONS:%=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)


$(OBJ): %.o:%.c
	@$(CC) $(CFLAGS) -c $< -I$(INCDIR) -o $@


clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

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
