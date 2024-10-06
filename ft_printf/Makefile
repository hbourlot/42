# COLOR

SYSTEM_COLOR = \033[0;39m
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW = \033[0;93m
COLOUR_END=\033[0m

#TARGETS
NAME=			libftprintf.a
CC=				cc
CFLAGS= 		-Wall -Wextra -Werror
INCDIR= 		./include/

CFUNCTIONS = 	ft_utils1 ft_utils2
OBJ = 			$(CFUNCTIONS:%=%.o)

all: 		$(NAME)

$(NAME): 	$(OBJ)
				@ar -rcs $(NAME) $(OBJ)
				@echo "$(COLOUR_GREEN) $@ compiled!"

$(OBJ): %.o:%.c
				@echo "$(COLOUR_YELLOW) Compiling $@..."
				@$(CC) $(CFLAGS) -c $< -I$(INCDIR) -o $@

clean:
				@echo "$(COLOUR_RED)Removing .o files!"
				@rm -rf *.o

fclean: 	clean
				@echo "$(COLOUR_RED)Removing .a files!"
				@rm -f $(NAME)

re: 		fclean all

exec: 		all
				@rm -rf exec
				@cc $(NAME)
				@./a.out
